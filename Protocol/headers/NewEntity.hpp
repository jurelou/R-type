//
// Created by marmus_a on 18/01/18.
//

#ifndef R_TYPE_NEWENTITY_HPP
#define R_TYPE_NEWENTITY_HPP

#include <ARequest.hpp>
#include "Vertex.hpp"

namespace Protocol {

  class NewEntity : public ARequest {
  public:
    NewEntity();
    NewEntity(EntityType type, int id, const Vertex& pos);
    virtual ~NewEntity();

    EntityType  type;
    int         id;
    Vertex      pos;
    virtual std::string*      stringify();
#ifdef SERVER
    virtual bool          run(Server *s, ISocket* userSockets);
#else
    virtual bool          run(Client *c);
#endif
  };

}


#endif //R_TYPE_NEWENTITY_HPP
