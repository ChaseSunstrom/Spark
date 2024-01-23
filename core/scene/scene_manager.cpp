#include "scene_manager.hpp"

namespace ac
{
	void scene_manager::add_scene(const std::string& name, std::unique_ptr<scene> scene)
	{
		m_scenes[name] = std::move(scene);

		if (m_scenes.size() == 1)
			m_current_scene = m_scenes[name].get();
	}

	void scene_manager::remove_scene(const std::string& name)
	{
		m_scenes.erase(name);
	}

	scene* scene_manager::get_scene(const std::string& name)
	{
		return m_scenes[name].get();
	}

	void scene_manager::switch_scene(const std::string& name)
	{
		m_current_scene = m_scenes[name].get();
	}

	scene* scene_manager::get_current_scene()
	{
		return m_current_scene;
	}

	void scene_manager::update_current_scene(float64_t time_step)
	{
		m_renderer->render(m_current_scene);
	}
}