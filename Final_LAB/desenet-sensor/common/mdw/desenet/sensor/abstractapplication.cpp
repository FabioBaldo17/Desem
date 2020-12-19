#include "desenet/sensor/net.h"
#include "abstractapplication.h"

using desenet::sensor::AbstractApplication;

/*********************************************************************************************************
* TODO: Implement the protected methods of the AbstractApplication class here. From these you have to    *
* call the different methods on your DESENET Controller Entity implementation...                         *
*********************************************************************************************************/

// Default implementations.

void AbstractApplication::svSyncRequest()
{
	// TODO: Register application using the network entity
	// use a function in of the NetworkEntity for adding this application
	//XXX IS it good?
	NetworkEntity::instance().subscribeApps(this);

}

bool AbstractApplication::svPublishRequest(SvGroup group)
{
	// TODO: Register application for the provided group using the network entity
	//add_to_list


	return false;
}

void AbstractApplication::evPublishRequest(EvId id, const SharedByteBuffer & evData)
{
	// TODO: Publish event data
}

/**
 * Default callback method for syncs
 * In this method all sampled values applications need to be synched with the network time
 */
void AbstractApplication::svSyncIndication(desenet::NetworkTime time)
{
	// This function is defined in the app
}

/**
 * Default callback method for SV publishes
 */
SharedByteBuffer::sizeType AbstractApplication::svPublishIndication(SvGroup, SharedByteBuffer &)
{
	return 0;
}

