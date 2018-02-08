//
// Created by marmus_a on 09/01/18.
//

#include "ARequest.hpp"

namespace Protocol {

  ARequest::ARequest() {}

  ARequest::~ARequest() {}

  Command ARequest::getCommand() const {
    return (this->command);
  }

}