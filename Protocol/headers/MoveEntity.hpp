//
// Created by marmus_a on 18/01/18.
//

#ifndef R_TYPE_MOVEENTITY_HPP
#define R_TYPE_MOVEENTITY_HPP

#include <ARequest.hpp>
#include <Vertex.hpp>

namespace Protocol {

  class MoveEntity : public ARequest {
  public:
    MoveEntity();
    MoveEntity(int id, const Vertex& pos, EntityType type);
    virtual ~MoveEntity();

    int         id;
    Vertex      pos;
    EntityType  type;
    virtual std::string*      stringify();
#ifdef SERVER
    virtual bool          run(Server *s, ISocket* userSockets);
#else
    virtual bool          run(Client *c);
#endif
  };
}

#endif //R_TYPE_MOVEENTITY_HPP
