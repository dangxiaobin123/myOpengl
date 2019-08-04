/*
 * @Descripttion: resource.h
 * @copyright: xiaobin 2016-2019
 * @version: 1.0
 * @Author: xiaobin
 * @Date: 2019-08-04 12:00:02
 * @LastEditors: xiaobin
 * @LastEditTime: 2019-08-04 16:52:56
 */
#ifndef RESOURCE_H
#define RESOURCE_H

#include "asset.h"
#include "types.h"

enum ResourceType
{
    GENERIC = 0,
    TEXTURE,
    SHADER
};

class Resource
{
public: 
    Resource();
    ~Resource();

public: 
    const ResourceType get_resource_type() const ;

    void set_resource_name(const std::string &name);

    const std::string &get_resource_name() const;

    const u32 get_filename_hash() const;

    const long long get_memory() const;

    const long get_use_time() const;

    const bool is_async() const;

    const bool is_available() const;

protected: 
    std::string _resource_name;
    u32 _hash;
    long long _memory;
    long _use_time;
    bool _async;
    bool _available;
};

#endif //RESOURCE_H