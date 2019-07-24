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