//
// Created by marmus_a on 11/01/18.
//

#include "Entity.hpp"


Entity::Entity(Protocol::EntityType type) {
    static int nextId = 0;
    this->id = nextId;
    nextId++;
    _type = type;
    _delete = false;
  }

  Entity::~Entity() {
  }

  void Entity::init() {

  }


  int Entity::getId()
  { return (this->id);  }

Protocol::EntityType Entity::getType()
{ return _type; }

const std::list<IComponent *>& Entity::getComponents() const
{ return _components; }

void    Entity::setDelete(bool del)
{ this->_delete = del; }

bool    Entity::isRemovable()
{ return _delete; }