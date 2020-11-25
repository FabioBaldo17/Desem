#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include "xf/xfreactive.h"
#include "board/button-interface.h"
#include "board/led.h"
#include <unistd.h>

class ButtonManager : protected XFReactive,
					  public ToButtonManager
{
    friend class Factory;

public:
    /* Factory Pattern */
    void initialize();
    void initializeRelations(ToButton * p, BuiltInLed *pled);
    /* Singleton Pattern */
    static ButtonManager & instance();
    /* State machine pattern */
    void start();

private:
    /* Factory Pattern */
    ButtonManager();
    ButtonManager(ButtonManager &);
    void operator=(ButtonManager &);
    virtual ~ButtonManager();

    /* SAP Pattern */
    void pressed();
    void released();

    /* State machine pattern, from the XFReactive interface */
    virtual EventStatus processEvent(); // This is the state machine

    enum evID {evPressed, evReleased};		// These are the event ids
    enum tmID {tmLongPressed, tmLedBlink};				// This is the timeout id
    enum smState {STATE_INITIAL, STATE_WAIT, STATE_PRESSED,
                  STATE_CLICK, STATE_LONG, STATE_LED_TIMER_WAIT}; // These are the state ids
    static int longPressTimeout, blinkTimeout;

    smState rootState;

private:
    BuiltInLed *pLed;
    /* SAP pattern */
    ToButton * pButton;
};
#endif // BUTTONMANAGER_H
