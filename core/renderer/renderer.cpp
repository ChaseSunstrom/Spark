#include "../logging/log.hpp"
#include "renderer.hpp"
#include "../util/wrap.hpp"

namespace ac
{
	float64_t renderer::s_fixed_delta_time = 0.0;
	uint64_t renderer::s_tick_speed = 0;

	__A_CORE_API__ void renderer::on_update()
	{
		calculate_delta_time();
		calculate_last_frame_time();
		calculate_total_time();
	}

	__A_CORE_API__ void renderer::render(const scene* scene)
	{
		clear_screen();

		glm::vec4 color = scene->get_scene_config()->get_background_color();

		set_background_color(color.r, color.g, color.b, color.a);
		
		//component_array<render_component>& render_components = 
		//	scene->get_ecs()->get_component_array<render_component>();

		//for (const auto& rc : render_components.get_array())
		//{
		//	// place holder for now
		//	A_CORE_WARN("rc");
		//}
	}

	__A_CORE_API__ void renderer::calculate_total_time()
	{
		m_total_time += m_delta_time;
	}

	__A_CORE_API__ void renderer::calculate_delta_time()
	{
		auto now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float64_t> elapsed = now - m_last_frame_time_point;
		m_delta_time = elapsed.count(); // Time between the last frame and the current frame in seconds
		m_last_frame_time_point = now;
	}

	__A_CORE_API__ void renderer::calculate_last_frame_time()
	{
		m_last_frame_time = m_delta_time * 1000.0; // Convert seconds to milliseconds
	}
}