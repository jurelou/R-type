//
// Created by louis on 14/01/18.
//

#ifndef CPP_RTYPE_HUMAN_HPP
#define CPP_RTYPE_HUMAN_HPP

#include "Entity.hpp"
#include "Player.hpp"
class       Human: public Entity
{
public:
    Human(const Vertex& pos, Player *player);
    void init();
};
#endif //CPP_RTYPE_HUMAN_HPP
