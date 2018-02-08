//
// Created by marmus_a on 09/01/18.
//

#include "../headers/Login.hpp"

namespace Protocol {

  Login::Login() : ARequest() {
    this->command = LOGIN;

  }

  Login::Login(const std::string &login) {
    this->command = LOGIN;
    this->login = login;
  }

  std::string* Login::stringify() {
    std::string* res = new std::string("Type:LOGIN;login:");
    *res += this->login;
    *res += ";";
    return res;
  }
#ifdef SERVER
    bool Login::run(Server *s, ISocket* userSockets) {
    if (userSockets->isUDP() == true){
        std::cout <<  "HEREEEEEe" << std::endl;
        s->addUDPtoplayer(this->login, userSockets);
    }
    else
        s->createPlayer(this->login, userSockets);
    return true;
  }
#else
    bool Login::run(Client *c) {
        return true;
    }
#endif
}