//
// Created by marmus_a on 18/01/18.
//

#include "NewEntity.hpp"

namespace Protocol {

  NewEntity::NewEntity() {
    this->command = NEWENTITY;
  }

  NewEntity::NewEntity(EntityType type, int id, const Vertex &pos) {
    this->command = NEWENTITY;
    this->type = type;
    this->id = id;
    this->pos = pos;
  }

  NewEntity::~NewEntity() {
  }

  std::string *NewEntity::stringify() {
    std::string* res = new std::string("Type:NEWENTITY;EntityType:");

    *res += std::to_string(static_cast<int>(this->type)) + ";";
    *res += "Id:" + std::to_string(this->id);
    *res += ";PosX:" + std::to_string(static_cast<int>(this->pos.x));
    *res += ";PosY:" + std::to_string(static_cast<int>(this->pos.y));
    *res += ";";
    return res;
  }

#ifdef SERVER
  bool NewEntity::run(Server *s, ISocket *userSockets) {
    return false;
  }
#else
  bool NewEntity::run(Client *c) {
    c->NewEntity(this->type, this->id, this->pos);
    return false;
  }
#endif
}