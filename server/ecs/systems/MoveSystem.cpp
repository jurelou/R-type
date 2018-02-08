//
// Created by louis on 15/01/18.
//

#include "MoveSystem.hpp"
#include "Serializer.hpp"

MoveSystem::MoveSystem(Spawner *spawner)
{ _spawner = spawner; }

bool MoveSystem::update(Entity *unit)
{
    for (auto itc: unit->getComponents())
    {
        auto movable = dynamic_cast<Movable*>(itc);
        if (movable){
            if (movable->isMoving() == true)
            {
                movable->updatePos();
                std::string     *query = Protocol::MoveEntity(unit->getId(), movable->getPos(), unit->getType()).stringify();
                _spawner->broadcastUdp(*query);
                if (sqrt(pow(movable->getPos().x - movable->getStart().x ,2) + pow(movable->getPos().y - movable->getStart().y, 2)) >= movable->getDistance())
                {
                    std::string     *query = Protocol::DeleteEntity(unit->getId()).stringify();
                    _spawner->broadcastUdp(*query);
                    movable->setMoving(false);
                    unit->setDelete(true);
                    return (false);
                }

            }
        }

    }
    return (true);
}
