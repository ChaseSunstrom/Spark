#ifndef CORE_EVENT_H
#define CORE_EVENT_H

#include "../core.hpp"

namespace ac
{
	// ===============================================================
	// EVENT TYPES: | Used to store the type of event
	// ===============================================================

	__A_CORE_API__ enum class event_type
	{
		NO_TYPE,
		APP_UPDATE,
		APP_TICK,
		APP_RENDER,
		WINDOW_CLOSED,
		WINDOW_RESIZED,
		WINDOW_MOVED,
		KEY_PRESSED,
		KEY_RELEASED,
		KEY_REPEAT,
		MOUSE_PRESSED,
		MOUSE_RELEASED,
		MOUSE_MOVE,
		MOUSE_SCROLLED,
	};

	// ===============================================================
	// EVENT STRUCTS: | Used to hold event data related to their type

	__A_CORE_API__ struct event
	{
		event() = default;
		event(event_type type) : m_type(type) {}

		bool m_handled = false;
		event_type m_type = event_type::NO_TYPE;
	};

	__A_CORE_API__ using app_update_event = event;
	__A_CORE_API__ using app_tick_event = event;
	__A_CORE_API__ using app_render_event = event;
	__A_CORE_API__ using window_closed_event = event;

	__A_CORE_API__ struct window_resized_event : event
	{
		window_resized_event() = default;
		window_resized_event(int32_t width, int32_t height) : event(event_type::WINDOW_RESIZED), m_width(width), m_height(height) {}

		int32_t m_width;
		int32_t m_height;
	};

	__A_CORE_API__ struct window_moved_event : event
	{
		window_moved_event() = default;
		window_moved_event(int32_t x_pos, int32_t y_pos) : event(event_type::WINDOW_MOVED), m_x_pos(x_pos), m_y_pos(y_pos) {}

		int32_t m_x_pos;
		int32_t m_y_pos;
	};

	__A_CORE_API__ struct key_pressed_event : event
	{
		key_pressed_event() = default;
		key_pressed_event(int32_t key_code) : event(event_type::KEY_PRESSED), m_key_code(key_code) {}

		int32_t m_key_code;
	};

	__A_CORE_API__ struct key_released_event : event
	{
		key_released_event(int32_t key_code) : event(event_type::KEY_RELEASED), m_key_code(key_code) {}

		int32_t m_key_code;
	};

	__A_CORE_API__ struct key_repeat_event : event
	{
		key_repeat_event() = default;
		key_repeat_event(int32_t key_code) : event(event_type::KEY_REPEAT), m_key_code(key_code) {}

		int32_t m_key_code;
	};

	__A_CORE_API__ struct mouse_pressed_event : event
	{
		mouse_pressed_event() = default;
		mouse_pressed_event(int32_t button) : event(event_type::MOUSE_PRESSED), m_button(button) {}

		int32_t m_button;
	};

	__A_CORE_API__ struct mouse_released_event : event
	{
		mouse_released_event() = default;
		mouse_released_event(int32_t button) : event(event_type::MOUSE_RELEASED), m_button(button) {}

		int32_t m_button;
	};

	__A_CORE_API__ struct mouse_moved_event : event
	{
		mouse_moved_event() = default;
		mouse_moved_event(float64_t x_pos, float64_t y_pos) : event(event_type::MOUSE_MOVE), m_x_pos(x_pos), m_y_pos(y_pos) {}

		float64_t m_x_pos;
		float64_t m_y_pos;
	};

	__A_CORE_API__ struct mouse_scrolled_event : event
	{
		mouse_scrolled_event() = default;
		mouse_scrolled_event(float64_t x_offset, float64_t y_offset) : event(event_type::MOUSE_SCROLLED), m_x_offset(x_offset), m_y_offset(y_offset) {}

		float64_t m_x_offset;
		float64_t m_y_offset;
	};

	// ===============================================================

	__A_CORE_API__ class event_dispatcher
	{
	public:
		event_dispatcher() = default;
		event_dispatcher(std::shared_ptr<event> event) : m_event(event) {}

		bool dispatch(std::function<bool(std::shared_ptr<event>)> fn);

	private:
		std::shared_ptr<event> m_event;
	};
}

#endif // CORE_EVENT_H