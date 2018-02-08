//
// Created by louis on 15/01/18.
//

#include "ShootSystem.hpp"

ShootSystem::ShootSystem(Spawner *pwn)
{
    _spawner = pwn;
}

bool ShootSystem::update(Entity *unit)
{
    for (auto itc: unit->getComponents()) {
        auto shootable = dynamic_cast<Shootable *>(itc);
        if (shootable) {
            if (shootable->canShoot()){
                _spawner->addWaitingBullet(unit);
                shootable->shoot();
            }
        }
    }
    return (false);
}