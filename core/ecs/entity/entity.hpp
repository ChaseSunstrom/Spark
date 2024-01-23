#ifndef CORE_ENTITY_H
#define CORE_ENTITY_H

#include "../../core.hpp"
#include "entity_type.hpp"
#include "../component/component.hpp"

namespace ac
{
	__A_CORE_API__ class entity_manager
	{
	public:
		entity_manager(std::shared_ptr<component_manager> component_manager) : m_component_manager(component_manager) {}
		~entity_manager() = default;
		entity create_entity();
		void destroy_entity(entity id);
	private:
		entity m_next_id = 0;
		std::stack<entity> m_recycled_ids = std::stack<entity>();
		std::shared_ptr<component_manager> m_component_manager;
	};
}

#endif //CORE_ENTITY_H