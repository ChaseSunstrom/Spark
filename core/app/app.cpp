#include "app.hpp"

#include "app_interface.hpp"
#include "../events/sub.hpp"
#include "../logging/log.hpp"

namespace ac
{
	application::application()
	{
		this->push_layer<renderer_layer>();
		this->push_layer<window_layer>("App", 720, 1280, false);

		m_scene_manager->add_scene("Main Scene", std::make_unique<scene>());
	}

	void application::on_start()
	{
		auto sub = subscription<event>::create(
			subscription_topic::WINDOW_EVENT, app_functions::s_on_event);

		while (true)
		{
			on_update();
		}
	}

	template <typename T, typename... Args>
	void application::push_layer(Args&&... args)
	{
		m_layer_stack->push_layer<T>(std::forward<Args>(args)...);
	}

	void application::pop_layer()
	{
		m_layer_stack->pop_layer();
	}

	void application::on_update()
	{
		app_functions::s_on_update();

		for (const auto& layer : m_layer_stack->get_layers())
			layer->on_update();

		m_scene_manager->update_current_scene(0.005);
	}

	bool application::on_event(std::shared_ptr<event> event)
	{
		ac::event_dispatcher dispatcher(event);

		return dispatcher.dispatch(app_functions::s_on_event);
	}
}