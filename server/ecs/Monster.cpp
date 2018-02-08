//
// Created by louis on 14/01/18.
//

#include "Monster.hpp"

Monster::Monster(const Vertex& pos, const Vertex& dir, double speed, double reload): Entity(Protocol::EntityType::MONSTER)
{
    this->_components.push_back(new Movable(pos, dir, speed));
    this->_components.push_back(new Shootable(reload));
}

void Monster::init()
{}