#ifndef CORE_APP_INTERFACE_HPP
#define CORE_APP_INTERFACE_HPP

#include "../core.hpp"

#include "../events/event.hpp"

namespace ac
{
	struct app_functions
	{
		static std::function<void()> s_on_start;
		static std::function<void()> s_on_update;
		static std::function<bool(std::shared_ptr<event>)> s_on_event;

		static void register_functions(
			std::function<void()> on_start,
			std::function<void()> on_update,
			std::function<bool(std::shared_ptr<event>)> on_event);
	};
}

#endif