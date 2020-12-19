/*
 * MultiPDU.h
 *
 *  Created on: Dec 14, 2020
 *      Author: fabio
 */

#ifndef DESENET_MULTIPDU_H_
#define DESENET_MULTIPDU_H_

#include <frame.h>

namespace desenet {

	/**
     * @brief Object to represent a MPDU Frame.
     *
     * The class can be used to construct a DESENET MPDU frame to send data from the applications to the GW.
     */

class MultiPDU: public Frame {
public:

	// XXX Problem: ePDU can be a lot
	static const uint8_t SIZE = Frame::HEADER_SIZE + 12 + Frame::FOOTER_SIZE;			///< Beacon size header + payload: (from 'Frametype' to 'SV Group Mask')
    /**
     * @brief Constructs a new MPDU frame.
     *
     * Allocates a new frame and initializes its fields to the given parameter values and default values for all other fields.
     *
     * @param cycleInterval The cycle interval in microseconds.
     */
	MultiPDU(uint32_t cycleInterval = 0);

    /**
     * @brief Sets the destination address
     */
    void setDestinationAddress(Address destinationAddress);

    int ePDUCount;
    SharedByteBuffer insertionBuffer

	virtual ~MultiPDU();
	MultiPDU(const MultiPDU &other);
};

} /* namespace desenet */

#endif /* DESENET_MULTIPDU_H_ */
