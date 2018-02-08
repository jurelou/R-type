//
// Created by marmus_a on 10/01/18.
//

#ifndef R_TYPE_JOINGAME_HPP
#define R_TYPE_JOINGAME_HPP

#include "../ARequest.hpp"
#include "PlayerAccepted.hpp"

namespace Protocol {

  class JoinGame : public ARequest {
  public:
    JoinGame();
    JoinGame(const std::string& gameId);
    virtual ~JoinGame();

    std::string           gameId;
    virtual std::string*  stringify();
#ifdef SERVER
        virtual bool          run(Server *s, ISocket* userSockets);
#else
        virtual bool          run(Client *c);
#endif
  };

}

#endif //R_TYPE_JOINGAME_HPP
