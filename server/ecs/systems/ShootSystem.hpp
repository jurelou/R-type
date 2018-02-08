//
// Created by louis on 15/01/18.
//

#ifndef CPP_RTYPE_SHOOTSYSTEM_HPP
#define CPP_RTYPE_SHOOTSYSTEM_HPP

#include    "ISystem.hpp"

class       ShootSystem : public ISystem
{
public:
    ShootSystem(Spawner *spawner);
    bool update(Entity *unit);
private:
    Spawner *_spawner;
};

#endif //CPP_RTYPE_SHOOTSYSTEM_HPP
