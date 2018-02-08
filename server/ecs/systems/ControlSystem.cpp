//
// Created by louis on 15/01/18.
//

#include "ControlSystem.hpp"
#include "MoveEntity.hpp"

ControlSystem::ControlSystem(Spawner *spawner)
{
  _spawner =spawner;
}

bool ControlSystem::update(Entity *unit)
{
    for (auto itc: unit->getComponents())
    {
        auto controlable = dynamic_cast<Controlable*>(itc);
        if (controlable){
            Protocol::IRequest *request;
            while ((request = controlable->getPlayer()->getRequests().pop())) {
                auto playerMove = dynamic_cast<Protocol::PlayerMove *>(request);
                Vertex pos = controlable->getPos();
                if (playerMove) {
                    switch (playerMove->move) {
                      case Protocol::UP: if (pos.y > 10) pos.y -= controlable->getSpeed();
                        break;
                      case Protocol::DOWN: if (pos.y < 1270) pos.y += controlable->getSpeed();
                        break;
                      case Protocol::LEFT: if (pos.x > 10) pos.x -= controlable->getSpeed();
                        break;
                      case Protocol::RIGHT: if (pos.x < 1270) pos.x += controlable->getSpeed();
                        break;
                      case Protocol::SHOOT: _spawner->addWaitingBullet(unit);
                      default:
                        break;
                    }
                  controlable->setPos(pos);
                }
            }
            const std::string *packet = Protocol::MoveEntity(unit->getId(), controlable->getPos(), unit->getType()).stringify();
            _spawner->broadcastUdp(*packet);
          delete packet;
        }
    }
}

