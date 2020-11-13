#include "platform-config.h"
#include "xf/xf.h"
#include "app/factory.h"

int main(int argc, char ** argv)
{
	UNUSED(argc); UNUSED(argv);

	Factory factory;

	XF::init(10);	// Initialize XF

	// Create and initialize objects
	factory.buildApplication();

	XF::start();	// Start XF

	return 0;
}
