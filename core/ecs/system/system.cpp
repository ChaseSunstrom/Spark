#include "system.hpp"

namespace ac
{
	__A_CORE_API__ system_manager::~system_manager()
	{
		shutdown_systems();
	}

	template<typename T, typename... Args>
	__A_CORE_API__ std::shared_ptr<T> system_manager::register_update_system(Args&&... args)
	{
		auto system = std::make_shared<T>(m_component_manager, std::forward<Args>(args)...);
		m_update_systems.push_back(system);
		return system;
	}

	template<typename T, typename... Args>
	__A_CORE_API__ std::shared_ptr<T> system_manager::register_start_system(Args&&... args)
	{
		auto system = std::make_shared<T>(m_component_manager, std::forward<Args>(args)...);
		m_start_systems.push_back(system);
		return system;
	}

	template<typename T, typename... Args>
	__A_CORE_API__ std::shared_ptr<T> system_manager::register_shutdown_system(Args&&... args)
	{
		auto system = std::make_shared<T>(m_component_manager, std::forward<Args>(args)...);
		m_shutdown_systems.push_back(system);
		return system;
	}

	__A_CORE_API__ void system_manager::start_systems()
	{
		for (auto& system : m_start_systems)
			system->on_start();
	}

	__A_CORE_API__ void system_manager::update_systems(float64_t delta_time)
	{
		for (auto& system : m_update_systems)
			system->on_update(delta_time);
	}

	__A_CORE_API__ void system_manager::shutdown_systems()
	{
		for (auto& system : m_shutdown_systems)
			system->on_shutdown();
	}
}