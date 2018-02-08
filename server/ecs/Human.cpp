//
// Created by louis on 14/01/18.
//

#include "Human.hpp"

Human::Human(const Vertex& pos, Player * player) : Entity(Protocol::EntityType::HUMAN)
{
    Vertex  dir(0,0);
    this->_components.push_back(new Controlable(pos, player));
}
void Human::init()
{}
