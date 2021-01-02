#include <assert.h>
#include <array>
#include <list>
#include <map>
#include <vector>
#include <utility>
#include "platform-config.h"
#include "desenet/frame.h"
#include "desenet/beacon.h"
#include "abstractapplication.h"
#include "factory.h"
#include "board/ledcontroller.h"
#include "networkentity.h"
#include "MultiPDU.h"

using std::array;
using std::list;
using std::map;
using std::make_pair;
using std::bind;
using std::pair;
using std::vector;
using std::list;

using desenet::sensor::NetworkEntity;

NetworkEntity * NetworkEntity::_pInstance(nullptr);		// Instantiation of static attribute

NetworkEntity::NetworkEntity()
 : _pTimeSlotManager(nullptr),
   _pTransceiver(nullptr),
   _slotNumber(0)
{
	assert(!_pInstance);		// Only one instance allowed
	_pInstance = this;
	_publisherList.fill(nullptr);
}

NetworkEntity::~NetworkEntity()
{
}

void NetworkEntity::initialize(const desenet::SlotNumber & slotNumber)
{
	_slotNumber=slotNumber;
}

void NetworkEntity::initializeRelations(ITimeSlotManager & timeSlotManager, NetworkInterfaceDriver & transceiver)
{
	_pTimeSlotManager = &timeSlotManager;
    _pTransceiver = &transceiver;

     // Set the receive callback between transceiver and network. Bind this pointer to member function
    transceiver.setReceptionHandler(std::bind(&NetworkEntity::onReceive, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

}

/**
 * This method does not automatically create an instance if there is none created so far.
 * It is up the the developer to create an instance of this class prior to access the instance() method.
 */
//static
NetworkEntity & NetworkEntity::instance()
{
	assert(_pInstance);
	return *_pInstance;
}

/**
 * Called by the NetworkInterfaceDriver (layer below) after reception of a new frame
 */
void NetworkEntity::onReceive(NetworkInterfaceDriver & driver, const uint32_t receptionTime, const uint8_t * const buffer, size_t length)
{
	UNUSED(driver);
	UNUSED(receptionTime);
	Frame frame = Frame::useBuffer(buffer, length);

	// TODO: Add your code here

	if (frame.type() == FrameType::Beacon) {
		Beacon b(frame);
		Factory::instance().ledController().flashLed(0); // Blink led when beacon is detected
		// 1. Start a timer for calculating the time need for sending back the response to the beacon
		_pTimeSlotManager->onBeaconReceived(b.slotDuration());

		//2. Synchronize all subscribed application using the svSyncIndications(b.networkTime()) for each application
		syncApps(b.networkTime()); // This method perform a svSyncIndication for each subsscribed application

		//3. Save the SVMask
		svMask=b.svGroupMask();

		 // When the slot-timer elapses the function NetworkEntity::onTimeSlotSignal is called

	} else {
		// This is the case of MDUs but we are not controllers.
	}
}

// TODO: Add missing class method implementations here
void NetworkEntity::onTimeSlotSignal(const ITimeSlotManager & timeSlotManager, const ITimeSlotManager::SIG & signal){
	Factory::instance().ledController().flashLed(0); // Blink led when MPDU is send back to the GW
	// Send the MPDUs back to the GW
	MultiPDU MPDU;
	MPDU.setDestinationAddr(GATEWAY_ADDRESS);
	MPDU.setSlotNumber(_slotNumber);
	// Add to the MPDU all the SVePDU possibles
	for (size_t i = 0; i < svMask.size(); i++){
		if (svMask.test(i) && _publisherList[i] != nullptr){
			SharedByteBuffer mySharedBuffer(MPDU.Mtu);
			_publisherList[i]->svPublishIndication(i, mySharedBuffer);
			if (MPDU.addePDU(i, mySharedBuffer) == false ) break;
		}
	}

	// Add to the MPDU all the EVePDU possibles
	for (size_t i = 0; i < _eventElementList.size(); i++){
		if (MPDU.addePDU( _eventElementList.front().id , _eventElementList.front().data) == false ) break;
	}
	MPDU.setePDUCount();
	// Send the MPDU to the GW using the radio
	_pTransceiver->transmit(MPDU.getFinalMPDU(), MPDU.length());
}

void NetworkEntity::subscribeApps(AbstractApplication *new_app){
	// add the app to the list of app to be synchronized
	_syncList.push_back(new_app);
}

void NetworkEntity::syncApps(NetworkTime time){

	ApplicationSyncList::iterator appSyncList_it;
		for (appSyncList_it=_syncList.begin();
				appSyncList_it!=_syncList.end(); ++appSyncList_it){
			(*(appSyncList_it))->svSyncIndication(time);
		}
}


bool NetworkEntity::addToPublisherList(SvGroup group, AbstractApplication *abstractApplication){
		if ( _publisherList[group] == nullptr) {
			_publisherList[group] = abstractApplication;
			return true;
		}
		return false;
	}

