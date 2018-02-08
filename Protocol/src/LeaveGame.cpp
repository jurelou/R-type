//
// Created by marmus_a on 10/01/18.
//

#include "LeaveGame.hpp"

namespace Protocol {

  LeaveGame::LeaveGame() {
    this->command = LEAVEGAME;
  }

  LeaveGame::~LeaveGame() {}

  std::string *LeaveGame::stringify() {
    return (new std::string("Type:LEAVEGAME;gameId:;"));
  }

#ifdef SERVER
    bool LeaveGame::run(Server *s ,ISocket* userSockets) {
    s->kickPlayer(userSockets);
    return false;
  }
#else
    bool LeaveGame::run(Client *c) {
      return false;
    }
#endif
}