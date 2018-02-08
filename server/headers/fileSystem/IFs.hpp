//
// Created by louis on 11/01/18.
//

#ifndef R_TYPE_IFS_HPP
#define R_TYPE_IFS_HPP

#include <string>

class   IFs{
public:
    virtual ~IFs(){};

    virtual bool open(const std::string& path) = 0;
    virtual bool close() = 0;

    virtual std::string read(int len) = 0;
    virtual int write(const std::string& bugg) = 0;

};

#endif //R_TYPE_IFS_HPP
