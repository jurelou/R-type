//
// Created by louis on 15/01/18.
//

#ifndef CPP_RTYPE_OBSTACLE_HPP
#define CPP_RTYPE_OBSTACLE_HPP

#include "Entity.hpp"
#include "IComponent.hpp"

class       Obstacle: public Entity
{
public:
    Obstacle(const Vertex& pos);
    void init();
};
#endif //CPP_RTYPE_OBSTACLE_HPP
