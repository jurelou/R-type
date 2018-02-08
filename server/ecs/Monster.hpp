//
// Created by louis on 14/01/18.
//

#ifndef CPP_RTYPE_MONSTER_HPP
#define CPP_RTYPE_MONSTER_HPP

#include "Entity.hpp"
#include "IComponent.hpp"

class       Monster: public Entity
{
public:
    Monster(const Vertex& pos, const Vertex& dir, double speed, double reload);
    void init();
};
#endif //CPP_RTYPE_MONSTER_HPP
