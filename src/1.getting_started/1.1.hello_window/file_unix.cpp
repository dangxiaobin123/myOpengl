/*
** file_unix.cpp for LearnOpengl in /Users/dangxiaobin01/Documents/myProject/LearnOpengl/src/1.getting_started/1.1.hello_window
**
** Made by dxb
** Login   <>
**
** Started on  Wed Jul 24 2:06:35 PM 2019 dxb
** Last update Thu Jul 24 2:42:35 PM 2019 dxb
*/

#include "file_unix.h"

UnixFile::UnixFile(const char *filename, const char *mode) 
{
    open(filename, mode);
}

UnixFile::~UnixFile() 
{
    close();
}

bool UnixFile::open(const char *filename, const char *mode)
{
    _file_handle = fopen(filename, mode);
    if (!_file_handle) {
        return false;
    }
    return true;
}

bool UnixFile::read(void *buffer, size_t size, size_t count)
{
    size_t ret_code = fread(buffer, size, count, _file_handle);
    if (ret_code!=size) {
        if (feof(_file_handle)||ferror(_file_handle)) {
            return false;
        }
    }
    return true;
}

bool UnixFile::write(const void *buffer, size_t size, size_t count)
{
    fwrite(buffer, size, count, _file_handle);
    if (ferror(_file_handle)) return false;
    return true;
}

bool UnixFile::seek(long offset, int origin)
{
    if (fseek(_file_handle, offset, origin)!=0) {
        if (ferror(_file_handle)) return false;
    }
    return true;
}

bool UnixFile::tell(long *pos) const
{
    *pos = ftell(_file_handle);
    if (*pos==-1L) return false;
    return true;
}

bool UnixFile::filesize(long *size)
{
    seek(0, SEEK_END);
    tell(size);
    seek(0, SEEK_SET);
    return true;
}

bool UnixFile::is_open()
{
    return _file_handle != nullptr;
}

bool UnixFile::flush()
{
    if (_file_handle) {
        fflush(_file_handle);
        return true;
    }
    return false;
}

bool UnixFile::close()
{
    if (_file_handle) {
        fclose(_file_handle);
        _file_handle = nullptr;
        return true;
    }
    return false;
}