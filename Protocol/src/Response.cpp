//
// Created by marmus_a on 10/01/18.
//

#include "../headers/Response.hpp"

namespace Protocol {

  Response::Response() {
    this->command = RESPONSE;
  }

  Response::Response(bool value) {
    this->command = RESPONSE;
    this->value = value;
  }

  Response::~Response() {

  }

  std::string *Response::stringify() {
    std::string* res = new std::string("Type:RESPONSE;value:");

    if (this->value) {
      *res += "1";
    } else {
      *res += "0";
    }
    *res +=";";
    return (res);
  }

#ifdef SERVER
    bool Response::run(Server *s, ISocket* userSockets) {
    return false;
  }
#else
    bool Response::run(Client *c) {
        return this->value;
    }
#endif
}