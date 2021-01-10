/*
 * MultiPDU.h
 *
 *  Created on: Dec 14, 2020
 *      Author: fabio
 */
#pragma once
#include <string>
#include <list>
#include "frame.h"
#include "types.h"
#include "containers/SharedByteBuffer"

#define MINIMUM_FRAME_LENGTH 7
#define MAXIMUM_FRAME_LENGTH 500 //TODO understand which is the value
namespace desenet {

	/**
     * @brief Object to represent a MPDU Frame.
     *
     * The class can be used to construct a DESENET MPDU frame to send data from the applications to the GW.
     */

class MultiPDU: public Frame {

public:


    /**
     * @brief Constructs a new MPDU frame.
     *
     * Allocates a new frame and initializes its fields to the given parameter values and default values for all other fields.
     *
     * @param TODO
     */
	MultiPDU( )
	: Frame(Frame::Mtu){
	// Set the type for the MPDU
	Frame::setType(FrameType::MPDU);
	}

	MultiPDU(const Frame & frame);

	void setDestinationAddr(Address GWAddr){
		Frame::setDestination(GWAddr);
	}
	void setSlotNumber(const SlotNumber &slotNumber){
		// Write in MPDU frame the value of the slot without touching the frametype
		memset(Frame::buffer() + Frame::HEADER_SIZE, slotNumber | 0x80, 1);
	}
	void setePDUCount(){
		// Write in the MPDU frame the ePDU count
		memcpy(Frame::buffer() + Frame::HEADER_SIZE + 1, &ePDUCount, 1);
	}


    bool addePDU(SvGroup svGroup, SharedByteBuffer &svData, size_t svDataSize){
    	Trace::outln("MPDU before sv-start");
		for (size_t i = 0; i < size(); ++i) {
			Trace::outln("%2X", Frame::buffer()[i]);
		}
		Trace::outln("MPDU before sv-end");
    	SharedByteBuffer mySVePDU(1+svDataSize); // create new container with the appropriate size
		// ePDU_type (1 bit); SV_Group (4 bits); Length (3 bits); Data (length bits)
		uint8_t ePDU_head=0x00 | ((svGroup & 0x0F )<< 3) | (svDataSize & 0x7);
		memcpy(mySVePDU.data(), &ePDU_head, sizeof(ePDU_head));
		memcpy(mySVePDU.data()+1, svData.data(), svDataSize);
		Trace::outln("MPDU: svData %02X%02X%02X%02X%02X%02X", svData.data()[0],svData.data()[1],svData.data()[2],svData.data()[3],svData.data()[4],svData.data()[5]);
		Trace::outln("MPDU: mySVePDU %02X%02X%02X%02X%02X%02X", (mySVePDU.data()+1)[0],(mySVePDU.data()+1)[1],(mySVePDU.data()+1)[2],(mySVePDU.data()+1)[3],(mySVePDU.data()+1)[4],(mySVePDU.data()+1)[5]);

    	SharedByteBuffer ib = SharedByteBuffer::proxy(insertionPointAddress + 1, remainingLength-1 );
    	size_t nbrBytes = mySVePDU.size();
    	if (nbrBytes <= remainingLength && nbrBytes > 0) {
    		MPDUtotalSize+=nbrBytes;
    		// Add the ePDU to the structure
    		memcpy(insertionPointAddress ,  mySVePDU.data(),  mySVePDU.size() );
    		insertionPointAddress+=nbrBytes;
    		remainingLength-=nbrBytes;
    		ePDUCount++;
    		Frame::setLength(MPDUtotalSize);
    		Trace::outln("MPDU after sv-start");
			for (size_t i = 0; i < size(); ++i) {
				Trace::outln("%2X", Frame::buffer()[i]);
			}
			Trace::outln("MPDU after sv-end");
    		return true;
    	}
    	return false;
    }

    bool addePDU(EvId id, const SharedByteBuffer & evData, size_t svDataSize){
    	Trace::outln("MPDU before event-start");
		for (size_t i = 0; i < size(); ++i) {
			Trace::outln("%2X", Frame::buffer()[i]);
		}
		Trace::outln("MPDU before event-end");
    	SharedByteBuffer myEVePDU(1+svDataSize);
		// ePDU_type (1 bit); EvId (4 bits); Length (3 bits); Data (length bits)
		uint8_t ePDU_head=0x80 | ((id & 0x0F)<<3) | (evData.size() & 0x7);
		memcpy(myEVePDU.data(), &ePDU_head, sizeof(ePDU_head));
		memcpy(myEVePDU.data()+1, evData.data(), svDataSize);
		SharedByteBuffer ib = SharedByteBuffer::proxy(insertionPointAddress + 1, remainingLength-1 );
		size_t nbrBytes = myEVePDU.size();
		if (nbrBytes <= remainingLength && nbrBytes > 0) {
			MPDUtotalSize+=nbrBytes;
			// Add the ePDU to the structure
			memcpy(insertionPointAddress , myEVePDU.data(), myEVePDU.size() );	// Set first field in payload to zero
			insertionPointAddress+=nbrBytes;
			remainingLength-=nbrBytes;
			ePDUCount++;
			Frame::setLength(MPDUtotalSize);
			Trace::outln("MPDU after event-start");
			for (size_t i = 0; i < size(); ++i) {
				Trace::outln("%2X", Frame::buffer()[i]);
			}
			Trace::outln("MPDU after event-end");
			return true;
		}
		return false;
   }


    uint8_t *getFinalMPDU(){
    	Trace::outln("MPDU-start");
    	for (size_t i = 0; i < size(); ++i) {
    		Trace::outln("%2X", Frame::buffer()[i]);
		}
    	Trace::outln("MPDU-end");
    	return Frame::buffer();
    }
    size_t size(){
    	return Frame::length();
    }
private:
    uint8_t ePDUCount = 0; // Number of ePDU already inside the SharedBuffer
    int MPDUtotalSize = Frame::HEADER_SIZE + Frame::FOOTER_SIZE + 2;
    // The insertionPointAddres at the starting of the MPDU building is 7 in the simulation case
    unsigned char *insertionPointAddress = Frame::buffer() + Frame::HEADER_SIZE + 2;
    size_t remainingLength = Frame::Mtu - (size_t)(Frame::buffer() - insertionPointAddress);
};

} /* namespace desenet */

