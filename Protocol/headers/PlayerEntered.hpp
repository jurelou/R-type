//
// Created by marmus_a on 18/01/18.
//

#ifndef R_TYPE_PLAYERENTERED_HPP
#define R_TYPE_PLAYERENTERED_HPP

#include <ARequest.hpp>

namespace Protocol {

  class PlayerEntered : public ARequest {
  public:
    PlayerEntered();
    PlayerEntered(const std::string &playerId);
    virtual ~PlayerEntered();

    std::string playerId;
    virtual std::string *stringify();
#ifdef SERVER
    virtual bool run(Server *s, ISocket *userSockets);
#else
    virtual bool          run(Client *c);
#endif
  };

}

#endif //R_TYPE_PLAYERENTERED_HPP
