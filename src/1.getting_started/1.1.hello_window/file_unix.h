/*
** file_unix.h for LearnOpengl in /Users/dangxiaobin01/Documents/myProject/LearnOpengl/src/1.getting_started/1.1.hello_window
**
** Made by dxb
** Login   <>
**
** Started on  Wed Jul 24 12:31:31 PM 2019 dxb
** Last update Thu Jul 24 2:12:09 PM 2019 dxb
*/

#ifndef UNIX_FILE_H
# define UNIX_FILE_H

#include <string>
#include <stdio.h>

class UnixFile
{
public: 
    UnixFile(const char* filename, const char* mode) ;
    ~UnixFile();
    bool open(const char* filename, const char* mode);
    bool read(void* buffer, size_t size, size_t count);
    bool write(const void* buffer, size_t size, size_t count);
    bool seek(long offset, int origin);
    bool tell(long *pos) const;
    bool filesize(long *size);
    bool is_open();
    bool flush();
    bool close();
private: 
    FILE *_file_handle;
};

#endif /* !UNIX_FILE_H */
