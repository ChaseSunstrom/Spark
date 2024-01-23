#ifndef CORE_WRAP_HPP
#define CORE_WRAP_HPP

#include "../core.hpp"

#include "../logging/log.hpp"

// ===============================================================================
// MAIN FILE FOR WRAPPING OPENGL CALLS
// ===============================================================================

namespace ac
{

#ifdef __A_CORE_DEBUG__

#define check_gl_error(_type) \
	do { \
		GLenum err; \
			while ((err = glGetError()) != GL_NO_ERROR) \
				A_CORE_ERROR("[" << _type << "]:  OpenGL error - " << glewGetErrorString(err)); \
	} while (0)
#else

#define check_gl_error(_type)

#endif

	__A_CORE_API__ void set_background_color(float64_t r, float64_t g, float64_t b, float64_t a);

	__A_CORE_API__ void clear_screen();

	__A_CORE_API__ void set_viewport(int32_t x, int32_t y, int32_t width, int32_t height);

	__A_CORE_API__ void set_depth_test(bool enabled);

	__A_CORE_API__ void set_blending(bool enabled);

	__A_CORE_API__ void set_vertex_attribute_ptr(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);

	__A_CORE_API__ void enable_vertex_attribute_ptr(GLuint index);

	__A_CORE_API__ void use_shader_program(GLuint& program);

	__A_CORE_API__ void generate_vertex_array(GLuint& vao);

	__A_CORE_API__ void generate_vertex_buffer(GLuint& vbo);

	__A_CORE_API__ void generate_index_buffer(GLuint& ibo);

	__A_CORE_API__ void delete_vertex_array(GLuint& vao);

	__A_CORE_API__ void delete_vertex_buffer(GLuint& vbo);

	__A_CORE_API__ void delete_index_buffer(GLuint& ibo);

	__A_CORE_API__ void buffer_index_data(GLuint ibo, const std::vector<GLuint>& data);

	__A_CORE_API__ void bind_vertex_array(GLuint vao);

	__A_CORE_API__ void bind_vertex_buffer(GLuint vbo);

	__A_CORE_API__ void bind_index_buffer(GLuint ibo);

	__A_CORE_API__ void draw_elements(GLenum mode, GLsizei count, GLenum type, const void* indices);

	__A_CORE_API__ GLuint create_program();

	__A_CORE_API__ GLuint create_shader(GLenum type);

	__A_CORE_API__ void delete_program(GLuint program);

	__A_CORE_API__ void delete_shader(GLuint shader);

	__A_CORE_API__ void attach_shader(GLuint program, GLuint shader);

	__A_CORE_API__ void link_program(GLuint program);

	__A_CORE_API__ void use_program(GLuint program);

	__A_CORE_API__ void shader_source(GLuint shader, const std::string& source);

	__A_CORE_API__ void compile_shader(GLuint shader);
	
	template <typename T>
	__A_CORE_API__ void buffer_vertex_data(GLuint vbo, const std::vector<T>& data)
	{
		bind_vertex_buffer(vbo);
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(T), data.data(), GL_DYNAMIC_DRAW);

		check_gl_error("Buffer vertex data");
	}
}

#endif