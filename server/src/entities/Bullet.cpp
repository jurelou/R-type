//
// Created by louis on 10/01/18.
//

#include "Bullet.hpp"

Bullet::Bullet(const Vertex& pos, const Vertex& dir) : ABullet(pos, dir)
{
    std::cout << "New bullet" << std::endl;

}