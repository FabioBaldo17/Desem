#ifndef SENSOR_NETWORK_ENTITY_H
#define SENSOR_NETWORK_ENTITY_H

#include <assert.h>
#include <list>
#include <array>
#include "platform-config.h"
#include "desenet/desenet.h"
#include "desenet/networkinterfacedriver.h"
#include "itimeslotmanager.h"
#include "MultiPDU.h"
#include <queue>

using desenet::NetworkInterfaceDriver;
using namespace desenet;

class LedController;

namespace desenet {
namespace sensor {

class AbstractApplication;
class Net;

/**
 * @brief Implements the desenet protocol on the network layer.
 */
class NetworkEntity: public ITimeSlotManager::Observer {
	friend class AbstractApplication;
	friend class Net;

public:
	NetworkEntity();
	virtual ~NetworkEntity();

	void initialize(const SlotNumber &slotNumber);///< Initializes the instance.
	void initializeRelations(ITimeSlotManager &timeSlotManager,
			NetworkInterfaceDriver &transceiver);///< Initializes all relations needed by the instance.

	static NetworkEntity& instance();///< Returns reference to single instance.

protected:
	/**
	 * @brief Holds event information.
	 */
	struct EventElement {
		EventElement(EvId id, const SharedByteBuffer &data) :
				id(id), data(data) {
		}

		EvId id;					///< Event identifier (ex. EVID_JOYSTICK).
		const SharedByteBuffer data;///< Data that goes together with the event.
	};

	// desenet::NetworkInterfaceDriver::Callback callback
protected:
	/**
	 * @brief Called by the lower layer after reception of a new frame
	 */
	virtual void onReceive(NetworkInterfaceDriver &driver,
			const uint32_t receptionTime, const uint8_t *const buffer,
			size_t length);
	virtual void onTimeSlotSignal(const ITimeSlotManager &timeSlotManager,
			const ITimeSlotManager::SIG &signal);

protected:
	inline ITimeSlotManager& timeSlotManager() const {
		assert(_pTimeSlotManager);
		return *_pTimeSlotManager;
	}	///< Internal access to TimeSlotManager
	inline NetworkInterfaceDriver& transceiver() const {
		assert(_pTransceiver);
		return *_pTransceiver;
	}		///< Internal access to Transceiver

protected:
	// New types used in this class
	typedef std::list<AbstractApplication*> ApplicationSyncList;
	typedef std::array<AbstractApplication*, 16> ApplicationPublishersArray;
	typedef std::queue<EventElement> EventElementQueue;

protected:
	static NetworkEntity *_pInstance;					//< Pointer to single instance.
	ITimeSlotManager *_pTimeSlotManager;				//< Pointer to TimeSlotManager.
	NetworkInterfaceDriver *_pTransceiver;				//< Pointer to transceiver.
	SlotNumber _slotNumber;
	SvGroupMask svMask;								//< When a beacon is received it is used to store the svMask
	ApplicationSyncList _syncList; 					//< This list must be updated at the beginning
	ApplicationPublishersArray _publisherList;	 	//< This list contains the Applications to be called for publishing their SV
	EventElementQueue _eventElementQueue; 			//< This queue contains the Event ID and relative data to be published in the MPDU

protected:
	// Functions developed to support the desenet protocol
	void subscribeApps(AbstractApplication *new_app);
	void syncApps(NetworkTime time);
	void getDataApps(SvGroupMask svMask);
	bool addToPublisherList(SvGroup group, AbstractApplication *abstractApplication);
	void addToEventElementQueue(EventElement eventElement);


};

} // sensor
} // desenet
#endif // SENSOR_NETWORK_ENTITY_H
