//
// Created by marmus_a on 09/01/18.
//

#ifndef R_TYPE_LISTGAME_HPP
#define R_TYPE_LISTGAME_HPP

#include <vector>
#include "../ARequest.hpp"

namespace Protocol {

  class ListGame : public ARequest {
  public:
    ListGame();
    ListGame(const std::vector<std::string>& gamesId);
    virtual ~ListGame();

    std::vector<std::string>  gamesId;
    virtual std::string*      stringify();
#ifdef SERVER
        virtual bool          run(Server *s, ISocket* userSockets);
#else
        virtual bool          run(Client *c);
#endif
  };

}

#endif //R_TYPE_LISTGAME_HPP