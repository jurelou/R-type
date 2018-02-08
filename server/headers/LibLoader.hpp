//
// Created by marmus_a on 19/01/18.
//

#ifndef R_TYPE_LIBLOADER_HPP
#define R_TYPE_LIBLOADER_HPP

#include <dlfcn.h>
#include <string>
#include "IEntity.hpp"

class LibLoader {
  LibLoader(const std::string& lib);
  ~LibLoader();

  void          LoadLib(const std::string& lib);
  IEntity        *getInstance(const std::string &type, const Vertex &pos, const Vertex &dir);

private:
  void*         handler;
};



#endif //R_TYPE_LIBLOADER_HPP
