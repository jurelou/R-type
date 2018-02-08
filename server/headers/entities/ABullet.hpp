//
// Created by louis on 10/01/18.
//

#ifndef CPP_RTYPE_ABULLET_HPP
#define CPP_RTYPE_ABULLET_HPP

#include "AEntity.hpp"

class       ABullet : public AEntity{
public:
    ABullet(const Vertex& pos, const Vertex& dir);
};


#endif //CPP_RTYPE_ABULLET_HPP
