//
// Created by marmus_a on 18/01/18.
//

#include "MoveEntity.hpp"

namespace Protocol {

  MoveEntity::MoveEntity() {
    this->command = MOVEENTITY;
  }

  MoveEntity::MoveEntity(int id, const Vertex &pos, EntityType type) {
    this->command = MOVEENTITY;
    this->id = id;
    this->pos = pos;
    this->type = type;
  }

  MoveEntity::~MoveEntity() {}

  std::string *MoveEntity::stringify() {
    std::string* res = new std::string("Type:MOVEENTITY;Id:");

    *res += std::to_string(id);
    *res += ";EntityType:" + std::to_string(static_cast<int>(this->type));
    *res += ";PosX:";
    *res += std::to_string(this->pos.x);
    *res += ";PosY:";
    *res += std::to_string(this->pos.y);
    *res += ";";
    return res;
  }

#ifdef SERVER
  bool MoveEntity::run(Server *s, ISocket *userSockets) {
    return false;
  }
#else
  bool MoveEntity::run(Client *c) {
    c->MoveEntity(type, id, pos);
    return false;
  }
#endif
}