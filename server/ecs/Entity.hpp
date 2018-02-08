//
// Created by marmus_a on 11/01/18.
//

#ifndef R_TYPE_ENTITY_HPP
#define R_TYPE_ENTITY_HPP

#include <iostream>
#include <list>
#include "Protocol.hpp"
#include "IComponent.hpp"

#include "Movable.hpp"
#include "Shootable.hpp"
#include "Controlable.hpp"
#include "IEntity.hpp"

class Entity : public IEntity {

public:
    Entity(Protocol::EntityType type);
    virtual ~Entity();
    virtual void init();
    virtual int getId();
    virtual Protocol::EntityType getType();
    virtual const std::list<IComponent *>& getComponents() const;
    virtual void    setDelete(bool del);
    virtual bool    isRemovable();
protected:
    std::list<IComponent *> _components;
private:
    int id;
    Protocol::EntityType    _type;
    bool                    _delete;
};

#endif //R_TYPE_ENTITY_HPP
