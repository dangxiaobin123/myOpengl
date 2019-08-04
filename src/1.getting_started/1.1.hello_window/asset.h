/*
 * @Descripttion: asset.h
 * @copyright: xiaobin 2016-2019
 * @version: 1.0
 * @Author: xiaobin
 * @Date: 2019-08-04 12:02:58
 * @LastEditors: xiaobin
 * @LastEditTime: 2019-08-04 19:13:48
 */
#ifndef ASSET_H
#define ASSET_H

#include "file_unix.h"
#include <string>

enum SEEK_POS
{
    BEGIN,
    CURRENT,
    END
};

enum FILE_MODE
{
    FILE_READ = 0,
    FILE_WRITE,
    FILE_READWRITE
};

static const char *OpenMode[] = 
{
    "rb",
    "wb",
    "r+b",
    "w+b"
};

class Asset
{
public: 
    Asset(const std::string &file_name, FILE_MODE mode = FILE_READ);
    Asset(const char *file_name, FILE_MODE mode = FILE_READ);

    ~Asset();

    void read_data(bool report_error_log = false);

    bool read(UnixFile *file);

public: 
    /**
     * @name: clear()
     * @description: release the resource of the asset
     * @param {type} 
     * @return: 
     */
    void clear();

    const bool is_available() const ;

    const long get_filesize() const ;

    char *get_filedata() const ;

    const std::string &get_filename() const;

    void set_filename(const std::string &filename);

private: 
    std::string _file_name;
    long _file_size;
    char *_file_data;
    FILE_MODE _mode;
    bool _available = false;
};

#endif //ASSET_H