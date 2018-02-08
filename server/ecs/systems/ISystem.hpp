//
// Created by louis on 15/01/18.
//

#ifndef CPP_RTYPE_ISYSTEM_HPP
#define CPP_RTYPE_ISYSTEM_HPP

#include "Entity.hpp"
#include "Vertex.hpp"
#include "Spawner.hpp"

class   ISystem
{
public:
    virtual ~ISystem() {};
    virtual bool update(Entity *unit) = 0;
};

#endif //CPP_RTYPE_ISYSTEM_HPP
