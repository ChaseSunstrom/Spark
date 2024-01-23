#include "core.hpp"

#include "app/app.hpp"

namespace ac
{
	// Default main function
	__A_CORE_API__ void core_main()
	{
		application app;
		app.on_start();
	}
}