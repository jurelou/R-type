//
// Created by louis on 10/01/18.
//

#include "ABullet.hpp"

ABullet::ABullet(const Vertex& pos, const Vertex& dir): AEntity(Protocol::BULLET, pos, dir)
{
    std::cout << "New ABullet" << std::endl;
}