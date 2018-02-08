//
// Created by louis on 11/01/18.
//

#include "UnixFs.hpp"

UnixFs::UnixFs(const std::string& path)
{
    _isOpen = false;
    this->open(path);
}

UnixFs::~UnixFs()
{}

bool UnixFs::open(const std::string& path)
{
    _file = ::open(path.c_str(), O_RDWR| O_CREAT, 0644);
    if (_isOpen){
        close();
    }
    if (_file == -1) {
        return (false);
    }
    _isOpen = true;
    return (true);
}

bool UnixFs::close()
{
    if (_isOpen && ::close(_file) == -1)
        return (false);
    _isOpen = false;
    return (true);
}

std::string UnixFs::read(int len)
{
    char        *tmp = new char[10];
    std::string res("");

    int nb = ::read(_file, tmp, len);
    if (nb == -1)
    {
        delete[] tmp;
        return (res);
    }
    res = std::string(tmp, nb);
    delete[] tmp;
    return res;
}

int UnixFs::write(const std::string& str)
{
    int nb = ::write(_file, str.c_str(), str.length());
    if (nb == -1)
        return (-1);
    return nb;

}