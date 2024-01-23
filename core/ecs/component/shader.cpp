#include "shader.hpp"

#include "../../util/file.hpp"
#include "../../util/wrap.hpp"

namespace ac
{
	shader_manager::~shader_manager()
	{
		for (auto& it : m_shaders)
			delete_program(it.second);
	}

	GLuint shader_manager::load_shader(const std::string& vertex_path, const std::string& fragment_path)
	{
		std::string vertex_code = read_file(vertex_path);
		std::string fragment_code = read_file(fragment_path);

		GLuint vertex_shader = compile_shader(vertex_code, GL_VERTEX_SHADER);
		GLuint fragment_shader = compile_shader(fragment_code, GL_FRAGMENT_SHADER);

		GLuint shader_program = create_program();
		attach_shader(shader_program, vertex_shader);
		attach_shader(shader_program, fragment_shader);
		
		link_program(shader_program);

		ac::delete_shader(vertex_shader);
		ac::delete_shader(fragment_shader);

		std::string shader_name = concat_paths(vertex_path, fragment_path);
		m_shaders[shader_name] = shader_program;

		return shader_program;
	}

	GLuint shader_manager::get_shader(const std::string& vertex_path, const std::string& fragment_path)
	{
		std::string name = concat_paths(vertex_path, fragment_path);
		return m_shaders[name];
	}

	void shader_manager::delete_shader(const std::string& vertex_path, const std::string& fragment_path)
	{
		std::string name = concat_paths(vertex_path, fragment_path);
		auto it = m_shaders.find(name);

		if (it != m_shaders.end())
		{
			delete_program(it->second);
			m_shaders.erase(it);
		}
	}

	GLuint shader_manager::compile_shader(const std::string& shader_code, GLenum shader_type)
	{
		GLuint shader = create_shader(shader_type);
		shader_source(shader, shader_code);
		ac::compile_shader(shader);
		return shader;
	}

	inline std::string shader_manager::concat_paths(const std::string& vertex_path, const std::string& fragment_path)
	{
		return vertex_path + fragment_path;
	}
}