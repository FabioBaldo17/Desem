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
	MultiPDU( );
	MultiPDU(const Frame & frame);

    SharedByteBuffer buildSVePDU(SvGroup svGroup, SharedByteBuffer &svData){
    	SharedByteBuffer mySVePDU(1+svData.size()); // create new container with the appropriate size
    	// ePDU_type (1 bit); SV_Group (4 bits); Length (3 bits); Data (length bits)
    	uint8_t ePDU_head=0x0 + ((svGroup && 0x15)<<3) + (svData.size() && 0x7);
    	memcpy(mySVePDU.data(), &ePDU_head, sizeof(ePDU_head));
    	memcpy(mySVePDU.data()+1, &svGroup, svData.size());
    	return mySVePDU;
    }

    SharedByteBuffer buildEVePDU(EvId id, const SharedByteBuffer & evData){
    	SharedByteBuffer myEVePDU(1+evData.size());
    	// ePDU_type (1 bit); EvId (4 bits); Length (3 bits); Data (length bits)
		uint8_t ePDU_head=0x1 + ((id && 0x15)<<3) + (evData.size() && 0x7);
		memcpy(myEVePDU.data(), &ePDU_head, sizeof(ePDU_head));
		memcpy(myEVePDU.data()+1, &evData, evData.size());
		return myEVePDU;
    }


    bool addePDU(SharedByteBuffer &ePDU){
    	SharedByteBuffer ib = SharedByteBuffer::proxy(insertionPointAddress + 1, remainingLength-1 );
    	size_t nbrBytes = ePDU.size();
    	if (nbrBytes <= remainingLength && nbrBytes > 0) {
    		MPDUtotalSize+=nbrBytes;
    		// Add the ePDU to the structure
    		memcpy(insertionPointAddress , ePDU.data(), ePDU.size() );	// Set first field in payload to zero
    		insertionPointAddress+=nbrBytes;
    		remainingLength-=nbrBytes;
    		ePDUCount++;
    		return true;
    	}
    	return false;
    }
    uint8_t *getFinalMPDU(){
    	return Frame::buffer();
    }
private:

    int ePDUCount = 0; // Number of ePDU already inside the SharedBuffer
    int MPDUtotalSize= 0;
    size_t remainingLength = Frame::Mtu - Frame::HEADER_SIZE - Frame::reservedLength();
    unsigned char *insertionPointAddress = Frame::buffer() + Frame::HEADER_SIZE + 7 + 1 + 1 ;
};

} /* namespace desenet */

