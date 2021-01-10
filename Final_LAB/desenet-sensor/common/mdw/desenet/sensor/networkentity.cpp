#include <assert.h>
#include <array>
#include <queue>
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
using std::queue;

using desenet::sensor::NetworkEntity;

NetworkEntity *NetworkEntity::_pInstance(nullptr);// Instantiation of static attribute

NetworkEntity::NetworkEntity() :
		_pTimeSlotManager(nullptr), _pTransceiver(nullptr), _slotNumber(0) {
	assert(!_pInstance);		// Only one instance allowed
	_pInstance = this;
	_publisherList.fill(nullptr);
	//Trace::outln("NE_constructor: instance address %p", _pInstance);

}

NetworkEntity::~NetworkEntity() {
}

void NetworkEntity::initialize(const desenet::SlotNumber &slotNumber) {
	//Trace::outln("NE_initialize: instance address %p", _pInstance);
	_slotNumber = slotNumber;
}

void NetworkEntity::initializeRelations(ITimeSlotManager &timeSlotManager, NetworkInterfaceDriver &transceiver) {
	//Trace::outln("NE_initializeRelations: instance address %p", _pInstance);
	_pTimeSlotManager = &timeSlotManager;
	_pTransceiver = &transceiver;

	// Set the receive callback between transceiver and network. Bind this pointer to member function
	transceiver.setReceptionHandler( std::bind(&NetworkEntity::onReceive, this, std::placeholders::_1,
					std::placeholders::_2, std::placeholders::_3,
					std::placeholders::_4));
}

/**
 * This method does not automatically create an instance if there is none created so far.
 * It is up the the developer to create an instance of this class prior to access the instance() method.
 */
//static
NetworkEntity& NetworkEntity::instance() {
	assert(_pInstance);
	//Trace::outln("NE_instance: instance address %p", _pInstance);
	return *_pInstance;
}

/**
 * This method is called whenever a Frame is received by the RX antenna
 *
 */
void NetworkEntity::onReceive(NetworkInterfaceDriver &driver,
		const uint32_t receptionTime, const uint8_t *const buffer ,size_t length) {

	UNUSED(driver);
	UNUSED(receptionTime);
	Frame frame = Frame::useBuffer(buffer, length);


	// Check if the received Frame is a Beacon
	if (frame.type() == FrameType::Beacon) {
		// Create a Beacon object from the buffer received
		Beacon b(frame);
		// Blink led when beacon is detected
		Factory::instance().ledController().flashLed(0);
		// 1. Start a timer for calculating the time need for sending back the response to the beacon
		_pTimeSlotManager->onBeaconReceived(b.slotDuration());
		//2. Synchronize all subscribed application sending them the NetworkTime received inside the Beacon
		syncApps(b.networkTime());
		//3. Save the SVMask
		svMask = b.svGroupMask();
		// When the slot-timer elapses the function NetworkEntity::onTimeSlotSignal is called ->

	} else {
		// This is the case of MDUs but we are not controllers.
	}
}

/*
 * This method is called every time an event coming from the timer launched inside the onBeaconReceive arrives
 * This is the implementation of the method of the interface class ItimeSlotManage
 */
void NetworkEntity::onTimeSlotSignal(const ITimeSlotManager &timeSlotManager, const ITimeSlotManager::SIG &signal) {

	// Check which of the signals has launched the method
	if (signal == ITimeSlotManager::OWN_SLOT_START) {


		// Create an object for storing the data to be transmitted in this slot
		// It is important that every slot a completely new object is rebuild in order to
		// Remove old data
		MultiPDU MPDU;
		// Set the destination address of the GW
		MPDU.setDestinationAddr(GATEWAY_ADDRESS);
		// Set the slot number in the MPDU
		MPDU.setSlotNumber(_slotNumber);

		// Add to the MPDU all the SVePDU that can fit in the frame
		for (size_t i = 0; i < svMask.size(); i++) {
			if (svMask.test(i) && _publisherList[i] != nullptr) {
				// Create a support where the new data is copied from the application sensor
				// to the eMPDU field
				SharedByteBuffer mySharedBuffer(MPDU.Mtu);
				size_t dataSize = _publisherList[i]->svPublishIndication(i,
						mySharedBuffer);
				// Add the received data to the MPDU
				Trace::outln("NE_AcceApplication data send: %2X%2X%2X%2X%2X%2X", mySharedBuffer[0],mySharedBuffer[1],mySharedBuffer[2],mySharedBuffer[3],mySharedBuffer[4],mySharedBuffer[5]);
				if (MPDU.addePDU(i, mySharedBuffer, dataSize) == false)
					break;
			}
		}

		// Add to the MPDU all the EVePDU possibles
		while (!_eventElementQueue.empty()) {
			// If the EVePDU could be added to the MPDU then the next EVePDU in the queue
			// is is added while the one already inside the MPDU frame is popped  out of the queue
			Trace::outln("NE_JoysticApplication: Data send: %2X", _eventElementQueue.back().data[0]);
			if (MPDU.addePDU(_eventElementQueue.back().id,
					_eventElementQueue.back().data,
					_eventElementQueue.back().data.size()) == true) {
				// Because every event is double then: send one and clear two
				_eventElementQueue.pop();_eventElementQueue.pop();
			}
			// If the space inside the MPDU is finished then the addition to the MPDU is blocked
			// and the following MPDU will start with the remaining events first
			else
				break;
		}
		// After all ePDUs are added to the MPDU the count of ePDUs inside the final Frame is updated
		MPDU.setePDUCount();

		// Send the MPDU to the GW using the radio
		_pTransceiver->transmit(MPDU.getFinalMPDU(), MPDU.size());

		// For better understanding the functioning when the MPDU is send the led blinks
		Factory::instance().ledController().flashLed(0);
	}
}
/*
 * This method is used by the application to subscribe itself to the
 * list of applications that wants to be notified with the new networktime
 * when the new beacon is received
 */
void NetworkEntity::subscribeApps(AbstractApplication *new_app) {
	// add the app to the list of app to be synchronized
	_syncList.push_back(new_app);
}


/*
 * When the new beacon is received all the applications that are present in the
 * _syncList are updated with the new networkTime
 */
void NetworkEntity::syncApps(NetworkTime time) {

	ApplicationSyncList::iterator appSyncList_it;
	for (appSyncList_it = _syncList.begin(); appSyncList_it != _syncList.end();
			++appSyncList_it) {
		(*(appSyncList_it))->svSyncIndication(time);
	}
}

/*
 * When an application wants to send data when new data are are send to the GW
 * this method need to be called by the application for adding itself to the list of
 * the applications that have data to be publish
 */
bool NetworkEntity::addToPublisherList(SvGroup group,
		AbstractApplication *abstractApplication) {
	if (_publisherList[group] == nullptr) {
		_publisherList[group] = abstractApplication;
		return true;
	}
	return false;
}

/*
 * When an application wants to add a new event to the queue of events that
 * are send to the GW inside the MPDU this method must be called by the application
 * passing the EventElement that is a structure defined in the NetworkEntity class
 */
void NetworkEntity::addToEventElementQueue(EventElement eventElement) {
	_eventElementQueue.push(eventElement);
}
