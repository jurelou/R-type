//
// Created by marmus_a on 18/01/18.
//

#include "PlayerMove.hpp"

namespace Protocol {

  PlayerMove::PlayerMove() {
    this->command = PLAYERMOVE;
  }

  PlayerMove::PlayerMove(PlayerAction move) {
    this->command = PLAYERMOVE;
    this->move = move;
  }

  PlayerMove::~PlayerMove() {}

  std::string *PlayerMove::stringify() {
    std::string* res = new std::string("Type:PLAYERMOVE;Move:");

    *res += std::to_string(static_cast<int>(this->move));
    *res += ";";
    return res;
  }

#ifdef SERVER
  bool PlayerMove::run(Server *s, ISocket *userSockets) {
    return false;
  }
#else
  bool PlayerMove::run(Client *c) {
    return false;
  }
#endif


}