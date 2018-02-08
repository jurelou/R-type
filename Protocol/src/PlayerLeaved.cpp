//
// Created by marmus_a on 18/01/18.
//

#include "PlayerLeaved.hpp"

namespace Protocol {

  PlayerLeaved::PlayerLeaved() {
    this->command = PLAYERLEAVED;
  }

  PlayerLeaved::PlayerLeaved(const std::string &playerId) {
    this->command = PLAYERLEAVED;
    this->playerId = playerId;
  }

  PlayerLeaved::~PlayerLeaved() {}

  std::string* PlayerLeaved::stringify() {
    std::string* res = new std::string("Type:PLAYERLEAVED;PlayerId:");

    *res += this->playerId;
    *res += ";";
    return res;
  }

#ifdef SERVER
  bool PlayerLeaved::run(Server *s, ISocket *userSockets) {
    return false;
  }
#else
  bool PlayerLeaved::run(Client *c) {
  return false;
  };
#endif

}