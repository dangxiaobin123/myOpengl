/*
** file_util.cpp for LearnOpengl in /Users/dangxiaobin01/Documents/myProject/LearnOpengl/src/1.getting_started/1.1.hello_window
**
** Made by dxb
** Login   <>
**
** Started on  Wed Jul 24 4:40:08 PM 2019 dxb
** Last update Wed Jul 24 4:40:08 PM 2019 dxb
*/
#include <iostream>
#include <fstream>
#include <istream>
#include "logger.h"

void file2string(const char *filename, std::string *content)
{
    if (nullptr == filename) {
        LOG_ERR("error when read file %s.", filename);
        *content = nullptr;
    } else {
        std::ifstream file(filename);
        std::istreambuf_iterator<char> begin(file), end;
        std::string string(begin, end);
        file.close();

        *content = string;
    }
}

unsigned int bkdr_hash(const char *str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * seed + (*str++);
    }
    return hash & 0x7FFFFFFF;
}

void split_base_filename(const std::string &full_name, std::string &base_name, std::string &extention)
{
    std::string::size_type i = full_name.find_last_of('.');
    if ( i == std::string::npos) {
        extention = "";
        base_name = full_name;
    } else {
        extention = full_name.substr(i+1);
        base_name = full_name.substr(0, i);
    }
}