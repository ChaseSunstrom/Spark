#ifndef CORE_RENDERER_H
#define CORE_RENDERER_H

#include "../core.hpp"

#include "../scene/scene.hpp"
#include "../events/event.hpp"
#include "../ecs/ecs.hpp"
#include "batcher.hpp"

namespace ac
{
	// ==============================================================================
	// RENDERER:     | Used for rendering and storing rendering data
	// ==============================================================================

	class renderer
	{
	public:
		renderer() = default;
		~renderer() = default;
		void on_update();
		void render(const scene* scene);
		void calculate_total_time();
		void calculate_delta_time();
		void calculate_last_frame_time();
	public:
		static float64_t s_fixed_delta_time;
		static uint64_t s_tick_speed;
	private:
		float64_t m_delta_time = 0;
		float64_t m_last_frame_time = 0;
		float64_t m_total_time = 0;
	
		std::unique_ptr<batcher> m_batcher = std::make_unique<batcher>();

		// Time when renderer was constructed (used for time calculations)
		std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time = std::chrono::high_resolution_clock::now();
		std::chrono::time_point<std::chrono::high_resolution_clock> m_last_frame_time_point = std::chrono::high_resolution_clock::now();
	};
}

#endif //CORE_RENDERER_H