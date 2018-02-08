//
// Created by marmus_a on 09/01/18.
//

#ifndef R_TYPE_LOGIN_HPP
#define R_TYPE_LOGIN_HPP

#include "../ARequest.hpp"

namespace Protocol {
  class Login : public ARequest {
  public:
    Login();
    Login(const std::string& login);

    std::string           login;
    virtual std::string*  stringify();
#ifdef SERVER
        virtual bool          run(Server *s, ISocket* userSockets);
#else
        virtual bool          run(Client *c);
#endif
  };

}

#endif //R_TYPE_LOGIN_HPP
