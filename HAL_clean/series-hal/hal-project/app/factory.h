#ifndef FACTORY_H
#define FACTORY_H

#include <assert.h>
#include "platform-config.h"

class ButtonManager;
class Button;
class SimpleDisplay;

/**
 * @brief Provides access to general instances. Initializes and builds the application.
 */
class Factory
{
public:
	Factory();

	void buildApplication();

	static Factory & instance() { assert(_pInstance); return *_pInstance; }

	static ButtonManager & buttonManager();
	static Button & button();

	static SimpleDisplay & display();

protected:
	static Factory * _pInstance;
};

#endif
