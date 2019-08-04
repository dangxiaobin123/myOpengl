#include "texture.h"
#include "file_util.h"

Texture::Texture(const std::string &filename, TextureType type)
{
    std::shared_ptr<Asset> _file(new Asset(filename));
    _file->read_data();
    if (_file->is_available()) {
        init_resource_property(_file);
        gen_texture();
        load_image_data(_memory, _file->get_filedata());
    }
}

Texture::Texture(GLenum textureTarget, const TextureSample &sample)
{
    _texture_target = textureTarget;

    glGenTextures(1, &_texture_id);
    glBindTexture(textureTarget, _texture_id);
    set_sample(sample);
}

Texture::~Texture()
{
    if (_texture_id) {
        glDeleteTextures(1, &_texture_id);
    }
}

void Texture::gen_texture() 
{
    _texture_target = GL_TEXTURE_2D;
    glGenTextures(1, &_texture_id);
    glBindTexture(_texture_target, _texture_id);
    set_sample(TextureSample());
}

void Texture::set_texture_id(u32 texture_id)
{
    _texture_id = texture_id;
}

const u32 Texture::get_texture_id() const
{
    return _texture_id;
}

void Texture::set_sample(const TextureSample &sample)
{
    glBindTexture(_texture_target, _texture_id);
    glTexParameteri(_texture_target, GL_TEXTURE_MIN_FILTER, sample.min_filter);
    glTexParameteri(_texture_target, GL_TEXTURE_MAG_FILTER, sample.mag_filter);
    glTexParameteri(_texture_target, GL_TEXTURE_WRAP_S, sample.wrap_s);
    glTexParameteri(_texture_target, GL_TEXTURE_WRAP_T, sample.wrap_t);
}

void Texture::bind(u32 unit)
{
    glActiveTexture(unit);
    glBindTexture(_texture_target, _texture_id);
}

void Texture::unbind()
{
    glBindTexture(_texture_target, 0);
}

void Texture::create_texture(u32 width, u32 height, u8 *data, const TextureInfo &info)
{
    switch (info.format) {
    case RGBA:
    case RGB:
        glTexImage2D(_texture_target, 0, componets[info.format], width, height, 0, componets[info.componet], GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(_texture_target);
        break;
    default:
        glTexImage2D(_texture_target, 0, componets[info.format], width, height, 0, componets[info.componet], GL_FLOAT, data);
        break;
    }
}

void Texture::init_resource_property(std::shared_ptr<Asset> asset)
{
    _resource_name = asset->get_filename();
    _memory = asset->get_filesize();
    _hash = bkdr_hash(_resource_name.c_str());
    init_texture_info(asset->get_filedata());
}

void Texture::init_texture_info(const char *data)
{
    bool ispng = is_png(_resource_name.c_str());
    _texture_info.pic_type = ispng?PNG:JPG;
    _texture_info.componet = ispng?RGBA:RGB;
    _texture_info.format = ispng?RGBA:RGB;
    _texture_info.tex_type = GL_UNSIGNED_BYTE;
}

u8 *Texture::stbi_load(const char *filename, int *x, int *y, int *comp)
{
    u8 *data = nullptr;
    Asset *asset = new Asset(filename);
    asset->read_data();

    if (asset->is_available()) {
        const char *asset_data = asset->get_filedata();
        int req_comp = RGBA;
        data = stbi_load_from_memory(
                   reinterpret_cast<const u8 *>(asset_data), \
                   asset->get_filesize(), x, y, comp, req_comp);
        if (comp) *comp = req_comp;
    }

    delete asset;
    asset = nullptr;
    return data;
}

void Texture::set_height(int height)
{
    _height = height;
}

void Texture::set_width(int width)
{
    _width = width;
}

void Texture::load_image_data(const long long data_size, char *asset_data)
{
    int x = 0, y = 0;
    int bytes_perpixel = 0;
    bool ispng = is_png(_resource_name.c_str());

    u8 *data = nullptr;
    data = (u8 *)stbi_load_from_memory(reinterpret_cast<const u8 *>(asset_data), \
                                        data_size, &x, &y, &bytes_perpixel, ispng?RGBA:RGB);
    
    set_width(x);
    set_height(y);

    create_texture(x, y, data, _texture_info);
    stbi_image_free(data);
    _available = true;
}

bool Texture::is_png(const char *filename)
{
    std::string base_name, extention;
    split_base_filename(filename, base_name, extention);
    if (extention == "png") return true;
    return false;
}
