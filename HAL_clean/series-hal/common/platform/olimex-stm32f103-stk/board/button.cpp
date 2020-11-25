#include "stm32f10x_gpio.h"
#include "button.h"

Button::Button()
 : pManager(NULL),
   state(RELEASED)
{
}

Button::~Button()
{
}

void Button::initialize()
{
	// Read actual button state (GPIO state)
	// (It may be pressed already at start up!)
	state = checkButtonState();
}

void Button::initializeRelations(ToButtonManager * p)
{
	setButtonManager(p);
}

void Button::setButtonManager(ToButtonManager * p)
{
	pManager = p;
}

BState Button::checkButtonState()
{
	// TODO: Implement method accordingly.
	return RELEASED;
}



