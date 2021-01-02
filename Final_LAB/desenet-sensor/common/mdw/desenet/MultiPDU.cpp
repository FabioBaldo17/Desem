/*
 * MultiPDU.cpp
 *
 *  Created on: Dec 14, 2020
 *      Author: fabio
 */

#include <algorithm>
#include <cstring>
#include "platform-config.h"
#include "MultiPDU.h"


using std::string;
using std::uint32_t;
using std::uint8_t;
using std::size_t;
using std::min;
using std::memcpy;
using std::memset;
using std::bitset;


/* In the creation of the MPDU the class should set:
 * Frametype to Frametype = MPDU
 * SensorID to
 */
desenet::MultiPDU::MultiPDU()
	: Frame(MINIMUM_FRAME_LENGTH)
{
	// Set the type for the MPDU
	Frame::setType(FrameType::MPDU);
}

desenet::MultiPDU::MultiPDU(const Frame & frame)
	: Frame(frame)
{
}





