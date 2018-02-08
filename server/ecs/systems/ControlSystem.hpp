//
// Created by louis on 15/01/18.
//

#ifndef CPP_RTYPE_CONTROLSYSTEM_HPP
#define CPP_RTYPE_CONTROLSYSTEM_HPP

#include    "ISystem.hpp"
#include    "PlayerMove.hpp"

class       ControlSystem : public ISystem
{
public:
    ControlSystem(Spawner *spawner);
    bool update(Entity *unit);

protected:
    Spawner *_spawner;
};

#endif //CPP_RTYPE_CONTROLSYSTEM_HPP
