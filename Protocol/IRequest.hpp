//
// Created by marmus_a on 09/01/18.
//

#ifdef SERVER
#include "Server.hpp"
#else
#include "Client.hpp"
#endif

#ifndef R_TYPE_IREQUEST_HPP
#define R_TYPE_IREQUEST_HPP

#include  <string>
#include  "Protocol.hpp"
#include  "ISocket.hpp"

namespace Protocol {

  class IRequest {
  public:
      virtual std::string *stringify() = 0;

      virtual Command getCommand() const = 0;

#ifdef SERVER
      virtual bool run(Server *s, ISocket *userSockets) = 0;
#else
      virtual bool run(Client *c) = 0;
#endif
  };
};

#endif //R_TYPE_IREQUEST_HPP
