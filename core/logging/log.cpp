#include "log.hpp"

namespace ac
{

#ifdef _WIN32
#include <windows.h>

	__A_CORE_API__ void set_console_color(uint32_t color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
#else
	__A_CORE_API__ void set_console_color(uint32_t color);
#endif
}