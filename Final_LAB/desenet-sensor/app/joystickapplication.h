/*
 * joystickapplication.h
 *
 *  Created on: Jan 4, 2021
 *      Author: fabio
 */

#pragma once
#include "desenet/sensor/abstractapplication.h"
#include "common/platform/platform-common/board/interfaces/ijoystickobserver.h"
#include "common/platform/platform-common/board/interfaces/ijoystick.h"
#include "platform-config.h"
#include "trace/trace.h"
#include "types.h"
#include <deque>
namespace app
{


class JoysticApplication : public IJoystickObserver , public desenet::sensor::AbstractApplication{

//	enum Position
//		{
//			Invalid	= 0x00 ,	///< @brief The joystick value is invalid.
//			Center 	= 0x01 ,	///< @brief The joystick is centered (idle).
//			Left 	= 0x02 ,	///< @brief The joystick has been moved to or is at the left.
//			Right	= 0x04 ,	///< @brief The joystick has been moved to or is at the right.
//			Up		= 0x08 ,	///< @brief The joystick has been moved upwards or is in the up position.
//			Down	= 0x10 ,	///< @brief The joystick has been moved downwards or is in down position.
//			Pressed = 0x20		///< @brief The joystick has been pressed at the center.
//		};

public:
	JoysticApplication():
	evData(1){

	}

	void onPositionChange( IJoystick::Position position ){
		memset(evData.data(), 0xAB, sizeof(0xAB));
		//memset(evData.data(), position, sizeof(position));
		Trace::outln("JoysticApplication: %p--> Data send: %02X", this, *(evData.data()));
		// Thanks to the fact that the evPublishRequest makes a copy of the data
		// Even if the onPositionChange function is called from other threads or inside ISR
		// There should be no problem
		AbstractApplication::evPublishRequest(MyEventId, evData);
	}

	void initialize(){

	}
private:

protected:
	SharedByteBuffer evData;
	const desenet::EvId MyEventId = EVID_JOYSTICK;

};

} //namespace app

