#include "platform-config.h"
#include "xf/xf.h"
#include "app/factory.h"

int main(int argc, char ** argv)
{
	int myButton=0;
	UNUSED(argc); UNUSED(argv);

	Factory factory;

	XF::init(10);	// Initialize XF

	// Create and initialize objects
	factory.buildApplication();

	XF::start();	// Start XF

	return 0;
}
