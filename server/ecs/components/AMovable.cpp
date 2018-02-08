//
// Created by louis on 20/01/18.
//

#include "AMovable.hpp"

AMovable::AMovable(const Vertex& pos, double boundingCircle)
{
    this->pos = pos;
    this->boundingCircle = boundingCircle;
}

AMovable::~AMovable()
{}

const Vertex &AMovable::getPos()
{ return (this->pos); }

void        AMovable::setPos(const Vertex& pos)
{ this->pos = pos; }

void        AMovable::setPos(const float& a, const float& b)
{
    this->pos.x = a;
    this->pos.y = a;
}

double   AMovable::getBoundingCircle() const
{ return boundingCircle; }
