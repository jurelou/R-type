//
// Created by louis on 15/01/18.
//

#include "Obstacle.hpp"

Obstacle::Obstacle(const Vertex& pos): Entity(Protocol::EntityType::OBSTACLE)
{
    Vertex  dir(0, pos.y);

    this->_components.push_back(new Movable(pos, dir, 1));
}

void Obstacle::init()
{
}


