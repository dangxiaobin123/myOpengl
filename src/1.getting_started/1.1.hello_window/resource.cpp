#include "resource.h"

Resource::Resource() : _resource_name(""), _hash(0),
    _memory(0), _use_time(0), _async(false)
{

}

Resource::~Resource()
{
    
}

const ResourceType Resource::get_resource_type() const
{
    return ResourceType::GENERIC;
}

void Resource::set_resource_name(const std::string &name)
{
    _resource_name = name;
}

const std::string &Resource::get_resource_name() const
{
    return _resource_name;
}

const u32 Resource::get_filename_hash() const
{
    return _hash;
}

const long long Resource::get_memory() const
{
    return _memory;
}

const long Resource::get_use_time() const
{
    return _use_time;
}

const bool Resource::is_async() const
{
    return _async;
}

const bool Resource::is_available() const
{
    return _available;
}