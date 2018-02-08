//
// Created by marmus_a on 19/01/18.
//

#ifndef R_TYPE_IENTITY_HPP
#define R_TYPE_IENTITY_HPP

#include <list>
#include "Protocol.hpp"
#include "IComponent.hpp"

class IEntity {
public:
  virtual void init() = 0;
  virtual int getId() = 0;
  virtual Protocol::EntityType getType() = 0;
  virtual const std::list<IComponent *> &getComponents() const = 0;
  virtual void setDelete(bool del) = 0;
  virtual bool isRemovable() = 0;
};
#endif //R_TYPE_IENTITY_HPP