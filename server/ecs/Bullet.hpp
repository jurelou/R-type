//
// Created by louis on 14/01/18.
//

#ifndef CPP_RTYPE_BULLET_HPP
#define CPP_RTYPE_BULLET_HPP

#include "Entity.hpp"

class       Bullet: public Entity
{
public:
    Bullet(int src, const Vertex& pos, const Vertex& dir, double speed);
    void init();

    int        getSource() const;
private:
    int         _source;

};
#endif //CPP_RTYPE_Bullet_HPP
