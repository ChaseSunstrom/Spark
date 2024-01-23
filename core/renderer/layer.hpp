#ifndef CORE_LAYER_HPP
#define CORE_LAYER_HPP

#include "../core.hpp"

#include "../ecs/ecs.hpp"
#include "../window/window.hpp"
#include "renderer.hpp"


namespace ac
{
	// ==============================================================================
	// LAYER:        | Used for organizing related data in the layer stack and application
	// ==============================================================================

	__A_CORE_API__ class layer
	{
	public:
		virtual ~layer() = default;
		virtual void on_attach() = 0;
		virtual void on_detach() = 0;
		virtual void on_update() = 0;
		virtual void on_event() = 0;
	};

	__A_CORE_API__ class renderer_layer : public layer
	{
	public:
		renderer_layer() = default;
		void on_attach() override;
		void on_detach() override;
		void on_update() override;
		void on_event() override;
	private:
		std::shared_ptr<renderer> m_renderer = std::make_shared<renderer>();
	};

	__A_CORE_API__ class window_layer : public layer
	{
	public:
		window_layer() = default;
		window_layer(std::string title, uint64_t height, uint64_t width, bool vsync) { m_window = std::make_unique<window>(title, vsync, height, width); }
		void on_attach() override;
		void on_detach() override;
		void on_update() override;
		void on_event() override;
	private:
		std::unique_ptr<window> m_window = std::make_unique<window>();
	};
	
	__A_CORE_API__ class ecs_layer : public layer
	{
	public:
		ecs_layer() = default;
		void on_attach() override;
		void on_detach() override;
		void on_update() override;
		void on_event() override;
	private:
		std::unique_ptr<ecs> m_ecs = std::make_unique<ecs>();
	};
}

#endif //CORE_LAYER_H