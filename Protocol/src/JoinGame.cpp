//
// Created by marmus_a on 10/01/18.
//


#include "JoinGame.hpp"

namespace Protocol {

  JoinGame::JoinGame() {
    this->command = JOINGAME;
  }

  JoinGame::JoinGame(const std::string &gameId) {
    this->command = JOINGAME;
    this->gameId = gameId;
  }

  JoinGame::~JoinGame() {}

  std::string* JoinGame::stringify() {
    std::string* res = new std::string("Type:JOINGAME;");
    *res += "gameId:";
    *res += this->gameId + "\r\n";
    return (res);
  }

#ifdef SERVER
    bool JoinGame::run(Server *s, ISocket* userSockets) {
      s->acceptPlayerInGame(userSockets);
      return true;
  }
#else
    bool JoinGame::run(Client *c) {
        return false;
    }
#endif
}