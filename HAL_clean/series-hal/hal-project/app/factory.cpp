#include "platform-config.h"
#include "board/board.h"
#include "trace/trace.h"
#include "app/buttonmanager.h"
#include "board/button.h"
#include "board/display/simpledisplay.h"
#include "factory.h"

Factory * Factory::_pInstance(nullptr);

Factory::Factory()
{
	assert(!_pInstance);
	_pInstance = this;
}

void Factory::buildApplication()
{
	board::initialize();	// Initialize board specific stuff

	//
	// Initialize objects
	//
	button().initialize();
	buttonManager().initialize();
	display().initialize();

	//
	// Initialize relations
	//
	buttonManager().initializeRelations(&button());
	button().initializeRelations(&buttonManager());

	// Draw title on display
	display().clear();
	display().drawText("Series", 22, 2);
	display().drawLine({1, 36}, {SimpleDisplay::X_MAX - 1, 36});
	display().drawText("HAL", 34, 5);

	//
	// Start state machines
	//
	buttonManager().start();
}

//static
ButtonManager & Factory::buttonManager()
{
	static ButtonManager bm;

	return bm;
}

//static
Button & Factory::button()
{
	static Button button;

	return button;
}

// static
SimpleDisplay & Factory::display()
{
	static SimpleDisplay display;

	return display;
}
