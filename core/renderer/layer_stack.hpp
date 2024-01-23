#ifndef CORE_LAYER_STACK_HPP
#define CORE_LAYER_STACK_HPP

#include "layer.hpp"

namespace ac
{
	// ==============================================================================
	// LAYER STACK:   | Used for different application layers
	// ==============================================================================

	class layer_stack
	{
	public:
		layer_stack() = default;
		~layer_stack() = default;

		template <typename T, typename... Args>
		void push_layer(Args&&... args)
		{
			auto layer = std::make_unique<T>(std::forward<Args>(args)...);
			layer->on_attach();
			m_layers.emplace_back(std::move(layer));
		}


		template <typename T, typename... Args>
		void push_overlay(Args&&... args)
		{
			auto overlay = std::make_unique<T>(std::forward<Args>(args)...);
			overlay->on_attach();
			m_layers.emplace_back(std::move(overlay));
		}

		void pop_layer();
		void pop_overlay();

		std::vector<std::unique_ptr<layer>>& get_layers() { return m_layers; }
	private:
		std::vector<std::unique_ptr<layer>> m_layers = std::vector<std::unique_ptr<layer>>();
	};

}

#endif //CORE_LAYER_STACK_H