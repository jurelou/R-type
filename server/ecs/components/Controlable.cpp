//
// Created by louis on 15/01/18.
//

#include "Controlable.hpp"

Controlable::~Controlable()
{}

Controlable::Controlable(const Vertex &pos, Player *player) : AMovable(pos, 15)
{
    this->player = player;
    this->speed = 1.;
}

Player *Controlable::getPlayer() const {
    return (this->player);
}

double Controlable::getSpeed() const {
    return (this->speed);
}
