//
// Created by marmus_a on 19/01/18.
//

#include "Vertex.hpp"
#include "LibLoader.hpp"

LibLoader::LibLoader(const std::string &lib) {
  this->handler = dlopen(lib.c_str(), RTLD_LAZY);
}

LibLoader::~LibLoader() {
  dlclose(this->handler);
}

void LibLoader::LoadLib(const std::string &lib) {
  dlclose(this->handler);
  this->handler = dlopen(lib.c_str(), RTLD_LAZY);
}

IEntity* LibLoader::getInstance(const std::string &type, const Vertex& pos, const Vertex& dir) {
  IEntity*   (*loadedFunction)(const Vertex&, const Vertex&);

  loadedFunction = reinterpret_cast<IEntity*(*)(const Vertex&, const Vertex&)>(dlsym(this->handler, type.c_str()));
  if (loadedFunction == nullptr)
    return nullptr;
  return (loadedFunction(pos, dir));
}
