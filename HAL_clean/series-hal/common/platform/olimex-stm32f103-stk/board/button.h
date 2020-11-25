#ifndef BUTTON_H
#define BUTTON_H

#include "platform-config.h"
#include "xf/xfreactive.h"
#include "button-interface.h"

/**
 * @brief Button class representing center button of the joystick.
 */
class Button : public ToButton
{
public:
	Button();
    virtual ~Button();

    /* Factory Pattern */
    void initialize();
    void initializeRelations(ToButtonManager * p);

    /* SAP Pattern */
    void setButtonManager(ToButtonManager * p);

private:
    BState checkButtonState();			///< Returns the button state based on the actual GPIO state.

private:
    ToButtonManager* pManager;			///< Pointer to button observer.
    BState state;						///< Holds the previous read button state.
};

#endif // BUTTON_H
