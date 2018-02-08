//
// Created by marmus_a on 18/01/18.
//

#include "PlayerAccepted.hpp"

namespace Protocol {

  PlayerAccepted::PlayerAccepted() {
    this->command = PLAYERACCEPTED;
  }

  PlayerAccepted::PlayerAccepted(const std::string &playerId) {
    this->command = PLAYERACCEPTED;
    this->playerId = playerId;
  }

  PlayerAccepted::~PlayerAccepted() {}

  std::string* PlayerAccepted::stringify() {
    std::string* res = new std::string("Type:PLAYERACCEPTED;PlayerId:");

    *res += this->playerId;
    *res += ";";
    return res;
  }

#ifdef SERVER
  bool PlayerAccepted::run(Server *s, ISocket *userSockets) {
    return false;
  }
#else
  bool PlayerAccepted::run(Client *c) {
    c->setPlayerAccepted(this->playerId);
    return false;
  };
#endif

}