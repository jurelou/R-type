//
// Created by marmus_a on 13/01/18.
//

#include "Movable.hpp"

const Vertex &Movable::getStart() {
    return (this->start);
}

const Vertex &Movable::getDirection() {
    return (this->direction);
}

Movable::~Movable()
{}

Movable::Movable(const Vertex &pos, const Vertex &dir, const float& speed) : AMovable(pos, 10)
{
    this->moving = true;
    this->end = dir;
    this->speed = speed;
    this->start = pos;
    distance = sqrt(pow(dir.x - start.x, 2) + pow(dir.y - start.y, 2));
    direction.set((dir.x - start.x) / distance, (dir.y - start.y) / distance);
}

void        Movable::updatePos()
{
    this->pos.y += this->direction.y * this->speed * 0.5;
    this->pos.x += this->direction.x * this->speed * 0.5;
}

bool        Movable::isMoving()
{return this->moving; }

void        Movable::setMoving(bool move)
{ this->moving = move; }

const float&       Movable::getSpeed() const
{ return this->speed; }

const float&       Movable::getDistance() const
{ return this->distance; }

const Vertex& Movable::getEnd()
{ return this->end; }