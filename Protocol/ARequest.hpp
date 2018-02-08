//
// Created by marmus_a on 09/01/18.
//

#if defined(_WIN32) || defined(_WIN64)

#include  <string>
#include  <iostream>
#include  "IRequest.hpp"
#include  "Protocol.hpp"

#endif

#ifndef R_TYPE_AREQUEST_HPP
#define R_TYPE_AREQUEST_HPP

#ifdef __GNUC__

#include  <string>
#include  <iostream>
#include  "IRequest.hpp"
#include  "Protocol.hpp"

#endif

namespace Protocol {

  class ARequest : public IRequest {
  public:
    ARequest();
    virtual ~ARequest();

    Command getCommand() const;

  protected:
    Command command;
  };

};

#endif //R_TYPE_AREQUEST_HPP
