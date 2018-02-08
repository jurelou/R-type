//
// Created by louis on 10/01/18.
//

#ifndef CPP_RTYPE_BULLET_HPP
#define CPP_RTYPE_BULLET_HPP

#include "ABullet.hpp"

class   Bullet : public ABullet
{
public:
    Bullet(const Vertex& pos, const Vertex& dir);

};

#endif //CPP_RTYPE_BULLET_HPP
