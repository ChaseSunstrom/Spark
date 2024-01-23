#include "layer.hpp"

namespace ac
{
	__A_CORE_API__ void window_layer::on_update()
	{
		m_window->on_update();
	}


	__A_CORE_API__ void renderer_layer::on_update()
	{
		m_renderer->on_update();
	}

	__A_CORE_API__ void ecs_layer::on_update()
	{
		m_ecs->update_systems(0.005);
	}

	__A_CORE_API__ void ecs_layer::on_event()
	{

	}

	__A_CORE_API__ void window_layer::on_event()
	{

	}

	__A_CORE_API__ void renderer_layer::on_event()
	{

	}

	__A_CORE_API__ void ecs_layer::on_attach()
	{

	}

	__A_CORE_API__ void window_layer::on_attach()
	{

	}

	__A_CORE_API__ void renderer_layer::on_attach()
	{

	}

	__A_CORE_API__ void ecs_layer::on_detach()
	{

	}

	__A_CORE_API__ void window_layer::on_detach()
	{

	}

	__A_CORE_API__ void renderer_layer::on_detach()
	{

	}
}