//
// Created by marmus_a on 10/01/18.
//

#ifndef R_TYPE_RESPONSE_HPP
#define R_TYPE_RESPONSE_HPP

#include "../ARequest.hpp"

namespace Protocol {

  class Response : public ARequest {
  public:
    Response();
    Response(bool value);
    virtual ~Response();

    bool value;
    virtual std::string* stringify();

#ifdef SERVER
      virtual bool          run(Server *s, ISocket* userSockets);
#else
        virtual bool          run(Client *c);
#endif
  };

}

#endif //R_TYPE_RESPONSE_HPP
