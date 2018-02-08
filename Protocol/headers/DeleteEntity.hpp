//
// Created by marmus_a on 18/01/18.
//

#ifndef R_TYPE_DELETEENTITY_HPP
#define R_TYPE_DELETEENTITY_HPP

#include <ARequest.hpp>

namespace Protocol {

  class DeleteEntity : public ARequest {
  public:
    DeleteEntity();
    DeleteEntity(int id);
    virtual ~DeleteEntity();

    int         id;
    virtual std::string*      stringify();
#ifdef SERVER
    virtual bool          run(Server *s, ISocket* userSockets);
#else
    virtual bool          run(Client *c);
#endif
  };;

}

#endif //R_TYPE_DELETEENTITY_HPP
