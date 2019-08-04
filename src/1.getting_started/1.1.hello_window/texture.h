#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad/glad.h>
#include "stb_image.h"
#include "types.h"
#include <string>
#include "resource.h"
#include <memory>
#include "asset.h"

enum TextureComponent
{
    NONE,
    G,
    GA,
    RGB,
    RGBA,
    COMSIZE
};

static const int componets[COMSIZE] = 
{
    GL_NONE, GL_GREEN, GL_GREEN_SCALE, GL_RGB, GL_RGBA
};

enum TextureType
{
    TEXTURE2D,
    TEXTURE_EMPTY,
    TEXTURE_SIZE
};

enum PictureType
{
    PNG,
    JPG
};

struct TextureSample
{
    u32 min_filter = GL_LINEAR;
    u32 mag_filter = GL_LINEAR;
    u32 wrap_s = GL_REPEAT;
    u32 wrap_t = GL_REPEAT;
};

struct TextureInfo
{
    TextureComponent componet;
    TextureComponent format;
    int tex_type;
    PictureType pic_type;
    TextureSample tex_samp;
};

class Texture : public Resource
{
public: 
    Texture(const std::string &filename, TextureType type = TEXTURE2D);

    Texture(GLenum textureTarget, const TextureSample &sample);

    ~Texture();
public: 

    void gen_texture();
    /**
     * @name: set_texture_id
     * @description: set the id of texture
     * @param {int} 
     * @return: void
     */
    void set_texture_id(u32 texture_id);
    /**
     * @name: get_texture_id
     * @description: get the id of texture
     * @param {void} 
     * @return: int
     */
    const u32 get_texture_id() const;
    /**
     * @name: set_sample
     * @description: set the texture sample
     * @param {TextureSample} 
     * @return: void
     */
    void set_sample(const TextureSample &sample);
    /**
     * @name: bind
     * @description: bind texture to unit{GL_TEXTURE0}
     * @param {type} 
     * @return: 
     */
    void bind(u32 unit);
    /**
     * @name: unbind
     * @description: unbind the texture
     * @param {type} 
     * @return: 
     */
    void unbind();

    void create_texture(u32 width, u32 height, u8 *data, const TextureInfo &info);

    void init_resource_property(std::shared_ptr<Asset> asset) ;

    void init_texture_info(const char *data);

    u8 *stbi_load(const char *filename, int *x, int *y, int *comp);

    void load_image_data(const long long data_size, char *asset_data);

    void set_width(int width);

    void set_height(int height);

    bool is_png(const char *filename);

private: 
    // resource formate
    u32 _width, _height;

    // textureid
    u32 _texture_id = 0;
    GLenum _texture_target = GL_TEXTURE_2D;

    std::shared_ptr<Asset> _file;

    TextureInfo _texture_info = {};
};

#endif //TEXTURE_H