#include "entity.hpp"

namespace ac
{
	__A_CORE_API__ entity entity_manager::create_entity()
	{
		if (m_recycled_ids.empty())
			return m_next_id++;

		uint64_t id = m_recycled_ids.top();
		m_recycled_ids.pop();
		return id;
	}

	__A_CORE_API__ void entity_manager::destroy_entity(entity e)
	{
		m_recycled_ids.push(e);
	}
}