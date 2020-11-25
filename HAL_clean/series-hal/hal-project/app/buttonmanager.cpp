#include "trace/trace.h"
#include "xf/xfevent.h"
#include "buttonmanager.h"

using namespace std;

void ButtonManager::initialize()
{
    rootState = STATE_INITIAL;
}

void ButtonManager::initializeRelations(ToButton * p)
{
    pButton = p;
}

int ButtonManager::longPressTimeout = 1000;

ButtonManager & ButtonManager::instance()
{
    static ButtonManager bm;
    return bm;
}

ButtonManager::ButtonManager()
 : rootState(STATE_INITIAL),
   pButton(nullptr)
{}

ButtonManager::ButtonManager(ButtonManager &)
 : XFReactive(),
   rootState(STATE_INITIAL),
   pButton(nullptr)
{}

void ButtonManager::operator=(ButtonManager &)
{}

ButtonManager::~ButtonManager()
{}

void ButtonManager::pressed()
{
    Trace::outln("Button pressed");
    //create the pressed event
    XFEvent* ev = new XFEvent(evPressed, this);
    //fire the event
    pushEvent(ev);
}

void ButtonManager::released()
{
	Trace::outln("Button released");
    //create the released event
    XFEvent* ev = new XFEvent(evReleased, this);
    //fire the event
    pushEvent(ev);
}

EventStatus ButtonManager::processEvent()
{
    // will we handle the event ?
    EventStatus result = EventStatus::Unknown;
    // get the actual event
    const IXFEvent* ev = this->getCurrentEvent();

    // save the current state
    smState lastState = rootState;

    // the transition switch
    switch (rootState)
    {
        case STATE_INITIAL:
            if (ev->getEventType() == IXFEvent::Initial)
            {
                rootState = STATE_WAIT;
            }
            break;
        case STATE_WAIT:
            if (ev->getEventType() == IXFEvent::Event &&
                ev->getId() == evPressed)
            {
                rootState = STATE_PRESSED;
            }
            break;
        case STATE_PRESSED:
            // if the timeout wins
            if (ev->getEventType() == IXFEvent::Timeout &&
                    getCurrentTimeout()->getId() == tmLongPressed)
            {
                rootState = STATE_LONG;
            }
            // if the released event wins
            if (ev->getEventType() == IXFEvent::Event &&
                    ev->getId() == evReleased)
            {
                rootState = STATE_CLICK;
            }
            break;
        case STATE_CLICK:
            if (ev->getEventType() == IXFEvent::NullTransition)
            {
                rootState = STATE_WAIT;
            }
            break;
        case STATE_LONG:
            if (ev->getEventType() == IXFEvent::NullTransition)
            {
                rootState = STATE_WAIT;
            }
            break;
    }

    // the action switch
    if (lastState != rootState)
    {
        result = EventStatus::Consumed;
        switch (rootState)
        {
            case STATE_INITIAL:
            break;
            case STATE_WAIT:
            	Trace::outln("-- button manager waiting -- ");
                break;
            case STATE_PRESSED:
            	Trace::outln("-- button manager sees a button pressed -- ");
                /* start the long pressed timeout
                 */
                getThread()->scheduleTimeout(tmLongPressed, longPressTimeout, this);
                break;
            case STATE_CLICK:
            	Trace::outln("-- button manager sees a button clicked -- ");
                /* we must stop the long pressed timeout
                */
                getThread()->unscheduleTimeout(tmLongPressed, this);
                // generate a default transition to get out of here
                GEN(XFNullTransition());
                break;
            case STATE_LONG:
            	Trace::outln("-- button manager sees a long button press -- ");
                // generate a default transition to get out of here
                GEN(XFNullTransition());
                break;
        }
    }
    else
    {
        result = EventStatus::NotConsumed;
    }
    return result;
}

void ButtonManager::start()
{
    this->startBehavior();
}

