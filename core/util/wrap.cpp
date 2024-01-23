#include "../logging/log.hpp"

#include "wrap.hpp"

namespace ac
{

	__A_CORE_API__ void set_background_color(float64_t r, float64_t g, float64_t b, float64_t a)
	{
		glClearColor(r, g, b, a);

		check_gl_error("Background color set");
	}

	__A_CORE_API__ void clear_screen()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		check_gl_error("Screen clear");
	}

	__A_CORE_API__ void set_viewport(int32_t x, int32_t y, int32_t width, int32_t height)
	{
		glViewport(x, y, width, height);

		check_gl_error("Viewport set");
	}

	__A_CORE_API__ void set_depth_test(bool enabled)
	{
		if (enabled)
			glEnable(GL_DEPTH_TEST);

		else
			glDisable(GL_DEPTH_TEST);

		check_gl_error("Depth test set");
	}

	__A_CORE_API__ void set_blending(bool enabled)
	{
		if (enabled)
		{
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		else
			glDisable(GL_BLEND);

		check_gl_error("Blending set");
	}

	__A_CORE_API__ void use_shader_program(GLuint program)
	{
		glUseProgram(program);

		check_gl_error("Program use");
	}

	__A_CORE_API__ void bind_vertex_array(GLuint vao)
	{
		glBindVertexArray(vao);

		check_gl_error("Vertex array bind");
	}

	__A_CORE_API__ void bind_vertex_buffer(GLuint vbo)
	{
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		check_gl_error("Vertex buffer bind");
	}

	__A_CORE_API__ void bind_index_buffer(GLuint ibo)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

		check_gl_error("Index buffer bind");
	}

	__A_CORE_API__ void draw_elements(GLenum mode, GLsizei count, GLenum type, const void* indices)
	{
		glDrawElements(mode, count, type, indices);

		check_gl_error("Draw elements");
	}

	__A_CORE_API__ void set_vertex_attribute_ptr(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer)
	{
		glVertexAttribPointer(index, size, type, GL_FALSE, stride, pointer);

		check_gl_error("Vertex attribute set");
	}

	__A_CORE_API__ void enable_vertex_attribute_ptr(GLuint index)
	{
		glEnableVertexAttribArray(index);

		check_gl_error("Vertex attribute enable");
	}

	__A_CORE_API__ void use_shader_program(GLuint& program)
	{
		glUseProgram(program);

		check_gl_error("Program use");
	}

	__A_CORE_API__ void generate_vertex_array(GLuint& vao)
	{
		glGenVertexArrays(1, &vao);

		check_gl_error("Vertex array generate");
	}

	__A_CORE_API__ void generate_vertex_buffer(GLuint& vbo)
	{
		glGenBuffers(1, &vbo);

		check_gl_error("Vertex buffer generate");
	}

	__A_CORE_API__ void generate_index_buffer(GLuint& ibo)
	{
		glGenBuffers(1, &ibo);

		check_gl_error("Index buffer generate");
	}

	__A_CORE_API__ void delete_vertex_array(GLuint& vao)
	{
		glDeleteVertexArrays(1, &vao);

		check_gl_error("Vertex array delete");
	}

	__A_CORE_API__ void delete_vertex_buffer(GLuint& vbo)
	{
		glDeleteBuffers(1, &vbo);

		check_gl_error("Vertex buffer delete");
	}

	__A_CORE_API__ void delete_index_buffer(GLuint& ibo)
	{
		glDeleteBuffers(1, &ibo);

		check_gl_error("Index buffer delete");
	}

	__A_CORE_API__ void buffer_index_data(GLuint ibo, const std::vector<GLuint>& data)
	{
		bind_index_buffer(ibo);
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLuint), data.data(), GL_DYNAMIC_DRAW);

		check_gl_error("Index data in buffer");
	}

	__A_CORE_API__ GLuint create_program()
	{
		GLuint program = glCreateProgram();

		check_gl_error("Program create");

		return program;
	}

	__A_CORE_API__ void delete_program(GLuint program)
	{
		glDeleteProgram(program);

		check_gl_error("Program delete");
	}

	__A_CORE_API__ void delete_shader(GLuint shader)
	{
		glDeleteShader(shader);

		check_gl_error("Shader delete");
	}

	__A_CORE_API__ void attach_shader(GLuint program, GLuint shader)
	{
		glAttachShader(program, shader);

		check_gl_error("Shader attach");
	}

	__A_CORE_API__ void link_program(GLuint program)
	{
		glLinkProgram(program);

		check_gl_error("Program link");
	}

	__A_CORE_API__ void use_program(GLuint program)
	{
		glUseProgram(program);

		check_gl_error("Program use");
	}

	__A_CORE_API__ GLuint create_shader(GLenum type)
	{
		GLuint shader = glCreateShader(type);

		check_gl_error("Shader create");

		return shader;
	}

	__A_CORE_API__ void shader_source(GLuint shader, const std::string& source)
	{
		const char* source_ptr = source.c_str();
		glShaderSource(shader, 1, &source_ptr, nullptr);

		check_gl_error("Shader source");
	}

	__A_CORE_API__ void compile_shader(GLuint shader)
	{
		glCompileShader(shader);

		check_gl_error("Shader compilation");
	}
}