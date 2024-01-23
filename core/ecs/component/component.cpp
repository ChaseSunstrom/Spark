#include "component.hpp"

#include "../../util/wrap.hpp"

namespace ac
{
	__A_CORE_API__ mesh::mesh()
	{
		m_index_count = static_cast<GLsizei>(m_indices.size());

		create_mesh();
	}

	__A_CORE_API__ mesh::mesh(const std::vector<vertex>& vertices, const std::vector<GLuint>& indices)
	{
		m_vertices = vertices;
		m_indices = indices;

		m_index_count = static_cast<GLsizei>(m_indices.size());

		create_mesh();
	}

	__A_CORE_API__ void mesh::create_mesh()
	{
		// Generate and bind VAO
		generate_vertex_array(m_vao);
		bind_vertex_array(m_vao);

		// Generate and bind VBO
		generate_vertex_buffer(m_vbo);
		bind_vertex_buffer(m_vbo);
		buffer_vertex_data<vertex>(m_vbo, m_vertices);

		// Generate and bind IBO
		generate_index_buffer(m_ibo);
		bind_index_buffer(m_ibo);
		buffer_index_data(m_ibo, m_indices);

		set_vertex_attribute_ptr(0, 3, GL_FLOAT, sizeof(vertex), (void*)0);
		enable_vertex_attribute_ptr(0);

		set_vertex_attribute_ptr(1, 3, GL_FLOAT, sizeof(vertex), (void*)offsetof(vertex, m_normal));
		enable_vertex_attribute_ptr(1);

		set_vertex_attribute_ptr(2, 2, GL_FLOAT, sizeof(vertex), (void*)offsetof(vertex, m_texcoords));
		enable_vertex_attribute_ptr(2);

		bind_vertex_array(0);
	}

	__A_CORE_API__ mesh::~mesh()
	{
		delete_vertex_buffer(m_vbo);
		delete_index_buffer(m_ibo);
		delete_vertex_array(m_vao);
	}

	__A_CORE_API__ void mesh::bind()
	{
		bind_vertex_array(m_vao);
	}

	__A_CORE_API__ void mesh::unbind()
	{
		bind_vertex_array(0);
	}

	void material_manager::create_material(const std::string& name, const std::shared_ptr<material_component>& material)
	{
		m_materials[name] = material;
	}

	std::shared_ptr<material_component> material_manager::get_material(const std::string& name)
	{
		return m_materials[name];
	}

	void material_manager::destroy_material(const std::string& name)
	{
		auto it = m_materials.find(name);

		if (it != m_materials.end())
			m_materials.erase(it);
	}
}