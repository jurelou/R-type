//
// Created by louis on 20/01/18.
//

#include "CollisionSystem.hpp"

CollisionSystem::CollisionSystem(Spawner *spawner)
{ _spawner = spawner; }

bool CollisionSystem::update(Entity *unit)
{
    auto entities = _spawner->getEntities();
    for (auto component: unit->getComponents()) {
      auto movable = dynamic_cast<AMovable *>(component);
      if (movable) {
        for (auto it: entities) {
          for (auto iter:it.second->getComponents()) {
            auto entity = dynamic_cast<AMovable *>(iter);

            if (entity && it.second->getId() != unit->getId()) {
                double dist = std::sqrt(std::pow(movable->getPos().x - entity->getPos().x, 2) +
                                 std::pow(movable->getPos().y - entity->getPos().y, 2));
                if (dist < (movable->getBoundingCircle() + entity->getBoundingCircle())) {
                  auto bullet = dynamic_cast<Bullet *>(unit);
                  if (bullet) {
                    if (entities[bullet->getSource()]->getType() == Protocol::HUMAN && it.second->getType() == Protocol::MONSTER
                        || entities[bullet->getSource()]->getType() == Protocol::MONSTER && it.second->getType() == Protocol::HUMAN
                            || _spawner->getGame()->getGameLevel() == Protocol::LEGENDARY && (entities[bullet->getSource()]->getType() == Protocol::HUMAN && it.second->getType() == Protocol::HUMAN)) {
                      unit->setDelete(true);
                      it.second->setDelete(true);
                      if (it.second->getType() == Protocol::HUMAN){
                          auto human = dynamic_cast<Human *>(it.second);
                          if (human){
                              auto player = static_cast<Controlable *>(human->getComponents().front())->getPlayer();
                              player->setStatus(Protocol::DEAD);
                          }
                      }
                    }
                  }
              }
            }
          }
        }
      }
    }
}

