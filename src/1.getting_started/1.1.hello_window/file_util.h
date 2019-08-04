/*
** file_util.h for LearnOpengl in /Users/dangxiaobin01/Documents/myProject/LearnOpengl/src/1.getting_started/1.1.hello_window
**
** Made by dxb
** Login   <>
**
** Started on  Wed Jul 24 4:39:13 PM 2019 dxb
** Last update Wed Jul 24 4:39:13 PM 2019 dxb
*/

#ifndef FILE_UTIL_H
# define FILE_UTIL_H

#include <string>

void file2string(const char *filename, std::string *content);

unsigned int bkdr_hash(const char *str);

void split_base_filename(const std::string &full_name, std::string &base_name, std::string &extention);

#endif /* !FILE_UTIL_H */
