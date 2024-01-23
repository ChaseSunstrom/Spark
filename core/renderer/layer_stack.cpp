#include "layer_stack.hpp"

namespace ac
{
	__A_CORE_API__ void layer_stack::pop_layer()
	{
		m_layers.pop_back();
	}

	__A_CORE_API__ void layer_stack::pop_overlay()
	{
		m_layers.pop_back();
	}
}