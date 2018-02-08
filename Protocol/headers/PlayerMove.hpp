//
// Created by marmus_a on 18/01/18.
//

#ifndef R_TYPE_PLAYERMOVE_HPP
#define R_TYPE_PLAYERMOVE_HPP

#include <ARequest.hpp>

namespace Protocol {

  class PlayerMove : public ARequest {
  public:
  PlayerMove();
  PlayerMove(PlayerAction move);
  virtual ~PlayerMove();

  PlayerAction move;
  virtual std::string *stringify();
#ifdef SERVER
  virtual bool run(Server *s, ISocket *userSockets);
#else
  virtual bool          run(Client *c);
#endif
};

}

#endif //R_TYPE_PLAYERMOVE_HPP
