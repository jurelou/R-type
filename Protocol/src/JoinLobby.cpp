//
// Created by marmus_a on 10/01/18.
//

#include "JoinLobby.hpp"

namespace Protocol {

  JoinLobby::JoinLobby() {
    this->command = JOINLOBBY;
  }

  JoinLobby::JoinLobby(const std::string& gameId, int nbPlayers, Protocol::MapLevel mapLevel, bool started) {
    this->command = JOINLOBBY;
      this->gameId = gameId;
      this->nbPlayers = nbPlayers;
      this->mapLevel = mapLevel;
      this->started = started;
  }

  JoinLobby::~JoinLobby() {
  }

  std::string *JoinLobby::stringify() {
    std::string* res = new std::string("Type:JOINLOBBY;gameId:");
    *res += this->gameId;
    *res += ";nbPlayers:";
    *res += std::to_string(this->nbPlayers);
    *res += ";mapLvl:";
    *res += std::to_string(convertToInt(this->mapLevel));
    *res += ";started:";
    if (this->started == true)
        *res += "1;";
    else
        *res += "1;";
    return res;
  }

#ifdef SERVER
    bool JoinLobby::run(Server *s, ISocket*  userSockets) {
    s->addPlayerToLobby(this->gameId, userSockets);
    return false;
  }
#else
    bool JoinLobby::run(Client *c) {
      return true;
    }
#endif
    Protocol::MapLevel  JoinLobby::convertToEnum(int i)
    { return (static_cast<Protocol::MapLevel>(i)); }

    int                 JoinLobby::convertToInt(Protocol::MapLevel lvl)
    {
        if (lvl == Protocol::MapLevel::EASY) return 0;
        else if(lvl == Protocol::MapLevel::MEDIUM) return 1;
        else if(lvl == Protocol::MapLevel::HARD) return 2;
        else if(lvl == Protocol::MapLevel::LEGENDARY) return 3;
        return 0;
    }
}