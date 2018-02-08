//
// Created by marmus_a on 09/01/18.
//

#include "ListGame.hpp"

namespace Protocol {

  ListGame::ListGame() {
    this->command = LISTGAME;
  }


  ListGame::ListGame(const std::vector<std::string> &gamesId) {
    this->command = LISTGAME;
    this->gamesId = gamesId;
  }

  ListGame::~ListGame() {}

  std::string *ListGame::stringify() {
    std::string* res = new std::string("Type:LISTGAME;list:");
    for (auto it = this->gamesId.begin(); it < this->gamesId.end(); it++) {
      *res += *it;
      if (it != this->gamesId.end() - 1) {
        *res += ",";
      }
    }
    *res += ';';
    return (res);
  }

#ifdef SERVER
    bool ListGame::run(Server *s, ISocket* userSockets) {
        s->sendAllGames(userSockets);
    return (true);
  }
#else
    bool ListGame::run(Client *c) {
      c->setGamesList(this->gamesId);
      return (true);
    }
#endif
}