#include "shader.h"
#include "file_util.h"
#include <iostream>
Shader::Shader(const std::string& vs, const std::string& fs)
{
    _program_id = glCreateProgram();
    std::string vscontent, fscontent;
    file2string(vs.c_str(), &vscontent);
    file2string(fs.c_str(), &fscontent);
    create_shader(vscontent.c_str(), ShaderUseType::VERTEX);
    create_shader(fscontent.c_str(), ShaderUseType::FRAGMENT);
    glLinkProgram(_program_id);
}

void Shader::unuse() { glUseProgram(0); }

void Shader::use() { glUseProgram(_program_id); }

const int Shader::get_uniform_location(const std::string &uniform_name) {
    check_uniform_and_create(uniform_name);
    return _uniform_location_map[uniform_name];
}

const int Shader::get_uniform_location(const char *uniform_name_cstring) {
    std::string uniform_name = std::string(uniform_name_cstring);
    check_uniform_and_create(uniform_name);
    return _uniform_location_map[uniform_name];
}

void Shader::create_shader(const char *shader_src, ShaderUseType shader_type) {
    GLint shader_flag;
    /*  Generate some IDs for our shader programs  */
    switch (shader_type) {
        case VERTEX:
            shader_flag = glCreateShader(GL_VERTEX_SHADER);
            break;
        default:
            shader_flag = glCreateShader(GL_FRAGMENT_SHADER);
            break;
    }

    /*  Assign our above shader source code to these IDs  */
    glShaderSource(shader_flag, 1, &shader_src, nullptr);
    /*  Attempt to compile the source code  */
    glCompileShader(shader_flag);

    /*  check if compilation was successful */
    GLint res;
    glGetShaderiv(shader_flag, GL_COMPILE_STATUS, &res);

    char error_message[1024];
    int error_len = 0;
    if (GL_FALSE == res) {
        glGetShaderInfoLog(shader_flag, 1024, &error_len, error_message);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << error_message << std::endl;
        _available = false;
    } else {
        /*  Attach these shaders to the shader program  */
        glAttachShader(_program_id, shader_flag);
        LOG_INFO("Success compile shader");
    }
    /*  flag the shaders to be deleted when the shader program is deleted  */
    glDeleteShader(shader_flag);
}

void Shader::set_attrib_location(const char *name, int i) {
    // use();
    glGetError();

    glBindAttribLocation(_program_id, i, name);
    int error = glGetError();
    if (error != GL_NO_ERROR) {
        // LOG_ERR("set_attrib_location is error(%d)! %s\n", error, name);
    };
}

int Shader::get_attrib_location(const GLchar *attrib) const {
    return glGetAttribLocation(_program_id, attrib);
}

void Shader::set_uniform1i(const GLint location, const GLint value) {
    glUniform1i(location, value);
}

void Shader::set_uniform1i(const std::string &uniform_name, const int &value) {
    glUniform1i(get_uniform_location(uniform_name), value);
}

void Shader::set_uniform1fv(const std::string &uniform_name, GLsizei count, const GLfloat *value) {
    glUniform1fv(get_uniform_location(uniform_name), count, value);
}

void Shader::set_uniform1f(const std::string &uniform_name, const float value) {
    glUniform1f(get_uniform_location(uniform_name), value);
}

void Shader::set_uniform_vec2f(const std::string &uniform_name, const Vec2 &vector) {
    glUniform2fv(get_uniform_location(uniform_name), 1, glm::value_ptr(vector));
}

void Shader::set_uniform_vec3f(const std::string &uniform_name, const Vec3 &vector) {
    glUniform3fv(get_uniform_location(uniform_name), 1, glm::value_ptr(vector));
}

    void Shader::set_uniform_vec3f(const std::string &uniform_name, unsigned int count, void *value) {
        glUniform3fv(get_uniform_location(uniform_name), count, (GLfloat *)value);
    }

void Shader::set_uniform_vec4f(const std::string &uniform_name, const Vec4 &vector) {
    glUniform4fv(get_uniform_location(uniform_name), 1, glm::value_ptr(vector));
}

void Shader::set_uniform_mat4f(const std::string &uniform_name, const Mat44 &matrix) {
    glUniformMatrix4fv(get_uniform_location(uniform_name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::set_uniform_vec4f(const std::string &uniform_name, unsigned int count, void *value) {
    glUniform4fv(get_uniform_location(uniform_name), count, (GLfloat *)value);
}

void Shader::set_uniform_mat4f(const std::string &uniform_name, GLsizei count,
                               const GLfloat *value) {
    glUniformMatrix4fv(get_uniform_location(uniform_name), count, GL_FALSE, value);
}

void Shader::set_uniform_mat3f(const std::string &uniform_name, GLsizei count,
                               const GLfloat *value) {
    glUniformMatrix3fv(get_uniform_location(uniform_name), count, GL_FALSE, value);
}
