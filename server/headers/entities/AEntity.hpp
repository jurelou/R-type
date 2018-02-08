//
// Created by louis on 10/01/18.
//

#ifndef CPP_RTYPE_AENTITY_HPP
#define CPP_RTYPE_AENTITY_HPP

#include "../../../Physics/headers/Vertex.hpp"
#include "Protocol.hpp"
#include "IEntity.hpp"

class       AEntity : public IEntity{
public:
    AEntity(Protocol::EntityType type, const Vertex& pos, const Vertex& dir);
    virtual ~AEntity();

    const Vertex&   getPos() const;
    void            setPos(Vertex v);

    void    move();

protected:
    Vertex  _pos;
    Vertex  _dir;

    int     _id;
    bool    _canShoot;

    ssize_t     _hp;
    Protocol::EntityType    _type;
};

#endif //CPP_RTYPE_AENTITY_HPP
