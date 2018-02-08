//
// Created by marmus_a on 18/01/18.
//

#include "DeleteEntity.hpp"

namespace Protocol {

  DeleteEntity::DeleteEntity() {
    this->command = DELETEENTITY;
  }

  DeleteEntity::DeleteEntity(int id) {
    this->command = DELETEENTITY;
    this->id = id;
  }

  DeleteEntity::~DeleteEntity() {}

  std::string *DeleteEntity::stringify() {
    std::string* res = new std::string("Type:DELETEENTITY;Id:");

    *res += std::to_string(this->id);
    *res += ";";
    return res;
  }

#ifdef SERVER
  bool DeleteEntity::run(Server *s, ISocket *userSockets) {
    return false;
  }
#else
  bool DeleteEntity::run(Client *c) {
    c->DeleteEntity(this->id);
    return false;
  }
#endif

}