#ifndef CORE_SCENE_HPP
#define CORE_SCENE_HPP

#include "../ecs/ecs.hpp"
#include "../core.hpp"

namespace ac
{
	struct scene_config
	{
		scene_config() = default;
		scene_config(const glm::vec4& background_color) : m_background_color(background_color) {}
		~scene_config() = default;

		glm::vec4 get_background_color() const;

		glm::vec4 m_background_color = glm::vec4(0);
	};

	class scene
	{
	public:
		scene() = default;
		scene(std::shared_ptr<scene_config> config) : m_config(config) {}
		~scene() = default;
		std::shared_ptr<ecs> get_ecs() const { return m_ecs; }
		std::shared_ptr<scene_config> get_scene_config() const { return m_config; }
	private:
		// This is a shared pointer because multiple scenes can share the same ECS
		std::shared_ptr<ecs> m_ecs = std::make_shared<ecs>();
		// Same with this
		std::shared_ptr<scene_config> m_config = std::make_shared<scene_config>();
	};
}

#endif