#include "event.hpp"

namespace ac
{
	__A_CORE_API__ bool event_dispatcher::dispatch(std::function<bool(std::shared_ptr<event>)> fn)
	{
		return fn(m_event);
	}
}