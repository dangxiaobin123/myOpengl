/*
** shader.h for LearnOpengl in /Users/dangxiaobin01/Documents/myProject/LearnOpengl/src/1.getting_started/1.1.hello_window
**
** Made by dxb
** Login   <>
**
** Started on  Wed Jul 24 12:28:47 PM 2019 dxb
** Last update Thu Jul 24 3:18:42 PM 2019 dxb
*/

#ifndef SHADER_H
# define SHADER_H
#include <string>
#include "file_unix.h"
#include "types.h"
#include "math_inc.h"
#include <unordered_map>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include "logger.h"
#define GL_SILENCE_DEPRECATION
enum ShaderUseType {
    VERTEX,
    FRAGMENT
};

class Shader 
{
public: 
    Shader(const std::string& vs, const std::string& fs);

    u32 get_program_id() ;

    void use();
    void unuse();

    const int get_uniform_location(const std::string& uniformName);
    const int get_uniform_location(const char *uniform_name_cstring);
    
    void set_uniform1i(const GLint location, const GLint value);
    void set_uniform1i(const std::string &uniformName, const int &value);
    void set_uniform1f(const std::string &uniformName, const float value);
    void set_uniform1fv(const std::string &uniformName, GLsizei count, const GLfloat* value);
    

    void set_uniform_vec2f(const std::string &uniform_name, const Vec2 &vector);
    void set_uniform_vec3f(const std::string &uniformName, const Vec3 &vector);
    void set_uniform_vec3f(const std::string &uniform_name, unsigned int count, void *value);
    void set_uniform_vec4f(const std::string &uniformName, const Vec4 &vector);
    void set_uniform_vec4f(const std::string &uniformName, unsigned int count, void* value);

    void set_uniform_mat4f(const std::string &uniformName, const Mat44 &matrix);
    void set_uniform_mat4f(const std::string &uniformName, GLsizei count, const GLfloat* value);
    void set_uniform_mat3f(const std::string &uniformName, GLsizei count, const GLfloat* value);  
    
    void set_attrib_location(const char* name, int i);  
    int get_attrib_location(const GLchar* attrib) const;
private: 
    void create_shader(const char* shader_src, ShaderUseType shader_type);
    inline void check_uniform_and_create(const std::string &uniformName);
    inline void create_uniform(const std::string& uniformName);
private: 
    u32 _program_id = -1;
    std::unordered_map<std::string, int> _uniform_location_map;
    bool _available = false;
};

void Shader::create_uniform(const std::string& uniformName) {
    _uniform_location_map[uniformName] = glGetUniformLocation(_program_id, uniformName.c_str());
}

void Shader::check_uniform_and_create(const std::string &uniformName) {
    use();
    if (0 == _uniform_location_map.count(uniformName)) {
        create_uniform(uniformName);
    }
}

#endif /* !SHADER_H */
