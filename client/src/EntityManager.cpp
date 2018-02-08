#include        <iostream>
#include        "EntityManager.hpp"
#include        "Monster.hpp"

EntityManager::EntityManager() {
  this->currentTime = 0;
  this->hasEntity = false;
  this->shouldGoToMenu = false;
}

EntityManager::~EntityManager()
{}

void            EntityManager::setNewEntity(Protocol::EntityType type, int id, const Vertex &pos) {
  this->hasEntity = true;
  this->entityList.push_back(this->entityFactory.getNewInstance(type, id, pos));
}

void            EntityManager::moveEntity(Protocol::EntityType type, int id, const Vertex &pos) {
  for (auto it: this->entityList) {
    if (it->getId() == id) {
      it->setPosition(pos, this->currentTime);
      return;
    }
  }
  this->setNewEntity(type, id, pos);
}

void            EntityManager::deleteEntity(int id) {
  for (auto it = this->entityList.begin(); it != this->entityList.end(); it++) {
    if ((*it)->getId() == id || this->currentTime - (*it)->getInternalTime() > 5000) {
      this->entityList.erase(it);
      return;
    }
  }
}

void            EntityManager::deleteInactiveEntity() {
  for (auto it = this->entityList.begin(); it != this->entityList.end(); it++) {
    if (this->currentTime - (*it)->getInternalTime() > 5000) {
      this->entityList.erase(it);
      return;
    }
  }
}

bool            EntityManager::shouldIGoToMenu() {
  if (this->shouldGoToMenu) {
    this->shouldGoToMenu = false;
    return true;
  } else {
    return false;
  }
}

void            EntityManager::updateEntities(IGraphicalEngine *graphicalEngine, float elapsedTime) {
  if (this->hasEntity && this->entityList.size() == 0) {
    this->shouldGoToMenu = true;
  }
  for (auto it: this->entityList) {
    it->draw(graphicalEngine, elapsedTime);
  }
  this->deleteInactiveEntity();
  this->currentTime += elapsedTime;
}