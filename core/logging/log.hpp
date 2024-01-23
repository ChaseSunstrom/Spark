#ifndef CORE_LOG_HPP
#define CORE_LOG_HPP

#include "../core.hpp"


namespace ac
{

// Magic windows color codes
#define TEXT_COLOR_GREEN  2
#define TEXT_COLOR_RED    4
#define TEXT_COLOR_CYAN   11
#define TEXT_COLOR_YELLOW 14

		__A_CORE_API__ void set_console_color(uint32_t color);

#ifdef __A_CORE_TRACE__
#define A_CORE_TRACE(...) ac::set_console_color(TEXT_COLOR_CYAN); std::cout << __VA_ARGS__ << "\n"
#else
#define A_CORE_TRACE(_format_, ...)
#endif // __A_CORE_TRACE__

#ifdef __A_CORE_INFO__
#define A_CORE_INFO(...) ac::set_console_color(TEXT_COLOR_GREEN); std::cout << __VA_ARGS__ << "\n"
#else
#define A_CORE_INFO(_format_, ...)
#endif // __A_CORE_INFO__

#ifdef __A_CORE_WARN__
#define A_CORE_WARN(...) ac::set_console_color(TEXT_COLOR_YELLOW); std::cout << __VA_ARGS__ << "\n"
#else
#define A_CORE_WARN(_format_, ...)
#endif // __A_CORE_WARN__

#ifdef __A_CORE_ERROR__
#define A_CORE_ERROR(...) ac::set_console_color(TEXT_COLOR_RED); std::cout << __VA_ARGS__ << "\n"
#else
#define A_CORE_ERROR(_format_, ...)
#endif // __A_CORE_ERROR__

}

#endif // CORE_LOG_H