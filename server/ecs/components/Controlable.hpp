//
// Created by louis on 15/01/18.
//

#ifndef CPP_RTYPE_CONTROLABLE_HPP
#define CPP_RTYPE_CONTROLABLE_HPP

#include "Player.hpp"
#include "AMovable.hpp"

class Controlable : public AMovable{

public:
    Controlable(const Vertex& pos, Player * player);
    virtual ~Controlable();

    Player *getPlayer() const;
    double getSpeed() const;

protected:
    Player *player;
    double  speed;
};
#endif //CPP_RTYPE_CONTROLABLE_HPP
