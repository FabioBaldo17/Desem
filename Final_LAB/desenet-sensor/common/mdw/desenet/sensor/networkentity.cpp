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
   _pTransceiver(nullptr)
{
	assert(!_pInstance);		// Only one instance allowed
	_pInstance = this;
}

NetworkEntity::~NetworkEntity()
{
}

void NetworkEntity::initialize()
{
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

		//2. Synchronize all subscrbed application using the svSyncIndications(b.networkTime()) for each application
		syncApps(b.networkTime()); // This method perform a svSyncIndication for each subsscribed application

		//3. Save the SVMask
		svMask=b.svGroupMask();

		//  When the slot-timer elapses the function NetworkEntity::onTimeSlotSignal is called

	} else {
		// This is the case of MDUs but we are not controllers.
	}
}

// TODO: Add missing class method implementations here
void NetworkEntity::onTimeSlotSignal(const ITimeSlotManager & timeSlotManager, const ITimeSlotManager::SIG & signal){
	// Send the MPDUs back to the GW

	MultiPDU MPDU;
	SharedByteBuffer mySharedBuffer;

	// Add to the MPDU all the SVePDU possibles
	for (size_t i = 0; i < svMask.size(); i++){
		if (svMask.test(i)){
			_publisherList[i]->svPublishIndication(i, mySharedBuffer ); // TODO understand the SVGroup
			SharedByteBuffer sB = MPDU.buildSVePDU(i, mySharedBuffer);  // <-/
			if (MPDU.addePDU( sB) == false ) break;
		}
	}

	// Add to the MPDU all the EVePDU possibles
	for (size_t i = 0; i < _eventElementList.size(); i++){
		SharedByteBuffer sB = MPDU.buildEVePDU( _eventElementList.front().id , _eventElementList.front().data );
		if (MPDU.addePDU( sB) == false ) break;
	}

	// Send the MPDU to the GW using the radio
	_pInstance->transceiver().transmit(MPDU.getFinalMPDU(), MPDU.length());

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
		AbstractApplication *_abstractApplication = _publisherList.at(group);
		if (_abstractApplication == nullptr) {
			_abstractApplication = abstractApplication;
			return true;
		}
		return false;
	}

