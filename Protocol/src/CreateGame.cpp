//
// Created by marmus_a on 10/01/18.
//

#include "CreateGame.hpp"

namespace Protocol {

  CreateGame::CreateGame() {
    this->command = CREATEGAME;
  }

  CreateGame::CreateGame(const std::string &gameId, MapLevel mapId) {
    this->command = CREATEGAME;
    this->gameId = gameId;
    this->mapId = mapId;
  }

  CreateGame::~CreateGame() {

  }

  std::string *CreateGame::stringify() {
    std::string* res = new std::string("Type:CREATEGAME;gameId:");
    *res += this->gameId;
    *res += ";mapId:";
    *res += std::to_string(convertToInt(mapId));
    return (res);
  }
#ifdef SERVER
    bool CreateGame::run(Server *s, ISocket* userSockets) {
        s->createGame(gameId, mapId, userSockets);
    return false;
  }
#else
    bool CreateGame::run(Client *c) {
      return false;
    }
#endif
    Protocol::MapLevel  CreateGame::convertToEnum(int i)
    { return (static_cast<Protocol::MapLevel>(i)); }

    int                 CreateGame::convertToInt(Protocol::MapLevel lvl)
    {
        if (lvl == Protocol::MapLevel::EASY) return 0;
        else if(lvl == Protocol::MapLevel::MEDIUM) return 1;
        else if(lvl == Protocol::MapLevel::HARD) return 2;
        else if(lvl == Protocol::MapLevel::LEGENDARY) return 3;
        return 0;
    }
}