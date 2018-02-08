//
// Created by marmus_a on 19/01/18.
//

#ifndef R_TYPE_PAPILLON_HPP
#define R_TYPE_PAPILLON_HPP

#include "Monster.hpp"

class Papillon : public Monster {
public:
    Papillon(const Vertex& pos, const Vertex&dir);
    virtual ~Papillon();
};


#endif //R_TYPE_PAPILLON_HPP
