//
// Created by louis on 14/01/18.
//

#include "Bullet.hpp"

Bullet::Bullet(int source, const Vertex& pos, const Vertex& dir, double speed): Entity(Protocol::BULLET)
{
    // TODO std::cout << "COnstructing bullet from:"<<source << " pos: " << pos <<" dir:" << dir <<std::endl;
    _source = source;
    this->_components.push_back(new Movable(pos, dir, speed));
}

void Bullet::init()
{}


int        Bullet::getSource() const
{ return _source; }
