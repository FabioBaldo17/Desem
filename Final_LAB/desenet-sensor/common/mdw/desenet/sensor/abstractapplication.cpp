#include "desenet/sensor/net.h"
#include "abstractapplication.h"

using desenet::sensor::AbstractApplication;

/*
 * This method is used by the application to perform a syncRequest to the
 * NetworkEntity. This is done by adding the application to a specific list.
 */
void AbstractApplication::svSyncRequest()
{
	// Register application in the NetworkEntity  syncList
	NetworkEntity::instance().subscribeApps(this);
}

/*
 * This method is used by the application to perform a publishRequest to the
 * NetworkEntity. This is done by adding the application to a specific list.
 * When the function is called the application must tell for which svGroup it
 * wants to be indicated.
 */
bool AbstractApplication::svPublishRequest(SvGroup group)
{
	// TODO: Register application for the provided group using the network entity
	//add_to_list
	NetworkEntity::instance().addToPublisherList(group,this);
	return true;
}

void AbstractApplication::evPublishRequest(EvId id, const SharedByteBuffer & evData)
{
	// TODO: Publish event data
	NetworkEntity::EventElement newEventElement(id, evData);
	NetworkEntity::instance().addToEventElementQueue(newEventElement);
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

