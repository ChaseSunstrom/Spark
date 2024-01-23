#ifndef CORE_SYSTEM_H
#define CORE_SYSTEM_H

#include "../../core.hpp"

#include "../component/component.hpp"

namespace ac
{
	__A_CORE_API__ class base_system
	{
	public:
		base_system(std::shared_ptr<component_manager> component_manager) : m_component_manager(component_manager) {}

		virtual void on_init() = 0;
		virtual void on_start() = 0;
		virtual void on_update(float64_t delta_time) = 0;
		virtual void on_shutdown() = 0;

		virtual ~base_system() = default;
	protected:
		std::shared_ptr<component_manager> m_component_manager;
	};

	__A_CORE_API__ class system_manager
	{
	public:
		system_manager(std::shared_ptr<component_manager> component_manager) : m_component_manager(component_manager) {}
		~system_manager();

		template<typename T, typename... Args>
		std::shared_ptr<T> register_update_system(Args&&... systems);

		template<typename T, typename... Args>
		std::shared_ptr<T> register_start_system(Args&&... systems);

		template<typename T, typename... Args>
		std::shared_ptr<T> register_shutdown_system(Args&&... systems);

		void start_systems();
		void update_systems(float64_t delta_time);
		void shutdown_systems();
	private:
		std::vector<std::shared_ptr<base_system>> m_start_systems = std::vector<std::shared_ptr<base_system>>();
		std::vector<std::shared_ptr<base_system>> m_update_systems = std::vector<std::shared_ptr<base_system>>();
		std::vector<std::shared_ptr<base_system>> m_shutdown_systems = std::vector<std::shared_ptr<base_system>>();
		std::shared_ptr<component_manager> m_component_manager;
	};
}

#endif