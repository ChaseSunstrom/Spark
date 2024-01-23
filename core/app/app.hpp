#ifndef CORE_APP_HPP
#define CORE_APP_HPP

#ifndef ARCNUM_HPP
#define ARCNUM_HPP

#include "../events/event.hpp"
#include "../renderer/layer_stack.hpp"
#include "../scene/scene_manager.hpp"

namespace ac
{
	class application
	{
	public:
		application();
		~application() = default;

		void on_start();
		void on_update();
		static bool on_event(std::shared_ptr<event> event);

		template <typename T, typename... Args>
		void push_layer(Args&&... args);

		void pop_layer();
	private:
		std::unique_ptr<layer_stack> m_layer_stack = std::make_unique<layer_stack>();
		std::unique_ptr<scene_manager> m_scene_manager = std::make_unique<scene_manager>();
	};

	// for debugging
	bool print_event(std::shared_ptr<event> event);
}

#endif // ARCNUM_H

#endif