#include "ecs.hpp"

namespace ac
{
	

	__A_CORE_API__ void ecs::start_systems()
	{
		m_system_manager->start_systems();
	}

	__A_CORE_API__ void ecs::update_systems(float64_t delta_time)
	{
		m_system_manager->update_systems(delta_time);
	}

	__A_CORE_API__ void ecs::shutdown_systems()
	{
		m_system_manager->shutdown_systems();
	}

	__A_CORE_API__ entity ecs::create_entity()
	{
		return m_entity_manager->create_entity();
	}

	__A_CORE_API__ void ecs::destroy_entity(entity entity)
	{
		m_entity_manager->destroy_entity(entity);
		m_component_manager->destroy_component_array(entity);
	}
}