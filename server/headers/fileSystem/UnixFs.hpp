//
// Created by louis on 11/01/18.
//

#ifndef R_TYPE_UNIXFS_HPP
#define R_TYPE_UNIXFS_HPP

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "IFs.hpp"

class   UnixFs : public IFs
{
public:
    UnixFs(const std::string& path);
    virtual ~UnixFs();
    //UnixFs(const std::string& path);

    bool open(const std::string& path);
    bool close();

    std::string read(int len);
    int write(const std::string& str);
private:
    int     _file;
    bool    _isOpen;

};
#endif //R_TYPE_UNIXFS_HPP
