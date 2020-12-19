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
		// Start a timer for calculating the time need for sending back the response to the beacon
		_pTimeSlotManager->onBeaconReceived(b.slotDuration());

		//Synchronize all applications using the svSyncIndications(b.networkTime()) for each application
		syncApps(b.networkTime()); // This method perform a svSyncIndication for each

		// Ask for data (data and events) to all application giving the svMask


		//  When the timer elapses the function NetworkEntity::onTimeSlotSignal is called
		// Inside this function the received data are send to the GW

	} else {
		// This is the case of MDUs but we are not controllers.
	}
}

// TODO: Add missing class method implementations here
void NetworkEntity::onTimeSlotSignal(const ITimeSlotManager & timeSlotManager, const ITimeSlotManager::SIG & signal){
	// Send the MPDUs back to the GW

}

void NetworkEntity::subscribeApps(AbstractApplication *new_app){
	// add the app to the list of app to be synchronized
	syncList.push_back(new_app);
}

void NetworkEntity::syncApps(NetworkTime time){

	ApplicationSyncList::iterator appSyncList_it;
		for (appSyncList_it=syncList.begin();
				appSyncList_it!=syncList.end(); ++appSyncList_it){
			(*(appSyncList_it))->svSyncIndication(time);
		}
}

void NetworkEntity::getDataApps(SvGroupMask svMask){

	// For each app registered ask launch a request with the corresponding group
	ApplicationSyncList::iterator appSyncList_it;
	for (appSyncList_it=syncList.begin();
			appSyncList_it!=syncList.end(); ++appSyncList_it){
		for (int svGroup = 0; svGroup < 16; ++svGroup) {
			if (svMask.test(svGroup)) (*(appSyncList_it))->svPublishRequest(svGroup);
		}

	}
}

// XXX TimeSlotManager interface must be defined
