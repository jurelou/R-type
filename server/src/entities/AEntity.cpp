//
// Created by louis on 10/01/18.
//

#include "AEntity.hpp"

AEntity::AEntity(Protocol::EntityType type, const Vertex& pos, const Vertex& dir)
{
    _type = type;
    _pos = pos;
    _dir = dir;
    std::cout << "New AEntity" << std::endl;

}

AEntity::~AEntity()
{}

const Vertex&   AEntity::getPos() const
{ return _pos; }

void            AEntity::setPos(Vertex v)
{ _pos = v; }

void        AEntity::move()
{}

