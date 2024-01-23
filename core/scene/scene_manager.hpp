#ifndef CORE_SCENE_MANAGER_HPP
#define CORE_SCENE_MANAGER_HPP

#include "../core.hpp"

#include "scene.hpp"
#include "../renderer/renderer.hpp"

namespace ac
{
	// Seperate file to prevent circular dependencies
	class scene_manager
	{
	public:
		scene_manager() = default;
		scene_manager(std::shared_ptr<renderer> renderer) : m_renderer(renderer) {}
		~scene_manager() = default;
		void add_scene(const std::string& name, std::unique_ptr<scene> scene);
		void remove_scene(const std::string& name);
		scene* get_scene(const std::string& name);
		scene* get_current_scene();
		void switch_scene(const std::string& name);
		void update_current_scene(float64_t time_step);
	private:
		std::unordered_map<std::string, std::unique_ptr<scene>> m_scenes = std::unordered_map<std::string, std::unique_ptr<scene>>();
		scene* m_current_scene = nullptr;
		// This is a shared pointer because different things can access the renderer
		std::shared_ptr<renderer> m_renderer = std::make_shared<renderer>();
	};
}

#endif