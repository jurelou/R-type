//
// Created by marmus_a on 18/01/18.
//

#include "PlayerEntered.hpp"

namespace Protocol {

  PlayerEntered::PlayerEntered() {
    this->command = PLAYERENTERED;
  }

  PlayerEntered::PlayerEntered(const std::string &playerId) {
    this->command =PLAYERENTERED;
    this->playerId = playerId;
  }

  PlayerEntered::~PlayerEntered() {}

  std::string* PlayerEntered::stringify() {
    std::string* res = new std::string("Type:PLAYERENTERED;PlayerId:");

    *res += this->playerId;
    *res += ";";
    return res;
  }

#ifdef SERVER
  bool PlayerEntered::run(Server *s, ISocket *userSockets) {
    return false;
  }
#else
  bool PlayerEntered::run(Client *c) {
    c->setJoinLobby(this->playerId);
    return false;
  };
#endif

}