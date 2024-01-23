#ifndef CORE_SHADER_HPP
#define CORE_SHADER_HPP

#include "../../core.hpp"

namespace ac
{
	__A_CORE_API__ class shader_manager
	{
	public:
		shader_manager() = default;
		~shader_manager();

		GLuint load_shader(const std::string& vertex_path, const std::string& fragment_path);
		GLuint get_shader(const std::string& vertex_path, const std::string& fragment_path);
		void delete_shader(const std::string& vertex_path, const std::string& fragment_path);
	private:
		GLuint compile_shader(const std::string& shader_code, GLenum shader_type);
		inline std::string concat_paths(const std::string& vertex_path, const std::string& fragment_path);
	private:
		// Uses a concatenated string of the vertex and fragment shader paths
		std::unordered_map<std::string, GLuint> m_shaders = std::unordered_map<std::string, GLuint>();
	};
}

#endif