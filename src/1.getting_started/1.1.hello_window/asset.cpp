#include "asset.h"
#include "logger.h"

const int FILE_COUNT = 1;

Asset::Asset(const std::string &file_name, FILE_MODE mode):
    _file_name(file_name),
    _mode(mode),
    _file_data(nullptr)
{

}

Asset::Asset(const char *file_name, FILE_MODE mode):
    _file_name(file_name),
    _mode(mode)
{

}

Asset::~Asset()
{
    clear();
}

void Asset::clear()
{
    _available = false;
    _file_size = 0;
    if (_file_data) {
        delete []_file_data;
        _file_data = nullptr;
    }
}

void Asset::read_data(bool report_error_log)
{
    if (_file_data) {
        clear();
    }

    UnixFile file(_file_name.c_str(), OpenMode[_mode]);
    if (file.is_open()) {
        if (_mode != FILE_MODE::FILE_WRITE) {
            file.filesize(&_file_size);
            _file_data = new char[_file_size+1];
            _file_data[_file_size] = '\0';
            if (read(&file)) {
                _available = true;
            }
        }
    }
    if (report_error_log) {
        LOG_ERR("Can't not find file[%s] with mode[%s] fail!", _file_name.c_str(), OpenMode[_mode]);
    }
}

bool Asset::read( UnixFile *file)
{
    if (file->is_open() && _mode != FILE_MODE::FILE_WRITE) {
        if (file->read(_file_data, _file_size, FILE_COUNT)) {
            LOG_INFO("Read %s with mode[%s] successful", _file_name.c_str(), OpenMode[_mode]);
            return true;
        }
        LOG_ERR("Read %s with mode[%s] fail", _file_name.c_str(), OpenMode[_mode]);
    }
    return false;
}

const bool Asset::is_available() const 
{
    return _available;
}

const long Asset::get_filesize() const 
{
    return _file_size;
}

char *Asset::get_filedata() const 
{
    return _file_data;
}

const std::string &Asset::get_filename() const
{
    return _file_name;
}

void Asset::set_filename(const std::string &filename)
{
    _file_name = filename;
}
