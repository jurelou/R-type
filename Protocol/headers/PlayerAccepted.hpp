//
// Created by marmus_a on 18/01/18.
//

#ifndef R_TYPE_PLAYERACCEPTED_HPP
#define R_TYPE_PLAYERACCEPTED_HPP

#include <ARequest.hpp>

namespace Protocol {

  class PlayerAccepted : public ARequest {
  public:
    PlayerAccepted();
    PlayerAccepted(const std::string &playerId);
    virtual ~PlayerAccepted();

    std::string playerId;
    virtual std::string *stringify();
#ifdef SERVER
    virtual bool run(Server *s, ISocket *userSockets);
#else
    virtual bool run(Client *c);
#endif
  };

}


#endif //R_TYPE_PLAYERACCEPTED_HPP
