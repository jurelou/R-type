//
// Created by marmus_a on 10/01/18.
//

#ifndef R_TYPE_LEAVEGAME_HPP
#define R_TYPE_LEAVEGAME_HPP

#include "../ARequest.hpp"

namespace Protocol {

  class LeaveGame : public ARequest{
  public:
    LeaveGame();
    virtual ~LeaveGame();

    virtual std::string*  stringify();
#ifdef SERVER
        virtual bool          run(Server *s, ISocket* userSockets);
#else
        virtual bool          run(Client *c);
#endif
  };

}

#endif //R_TYPE_LEAVEGAME_HPP
