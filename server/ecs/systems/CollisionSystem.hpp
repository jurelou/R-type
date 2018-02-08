//
// Created by louis on 20/01/18.
//

#ifndef _COLLISIONSYSTEM_HPP
#define _COLLISIONSYSTEM_HPP

#include    "ISystem.hpp"

class       CollisionSystem : public ISystem
{
public:
    CollisionSystem(Spawner *spawner);
    bool update(Entity *unit);

private:
    Spawner     *_spawner;
};

#endif //_COLLISIONSYSTEM_HPP
