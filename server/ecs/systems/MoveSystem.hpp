//
// Created by louis on 15/01/18.
//

#ifndef CPP_RTYPE_MOVESYSTEM_HPP
#define CPP_RTYPE_MOVESYSTEM_HPP

#include    "ISystem.hpp"

class       MoveSystem : public ISystem
{
public:
    MoveSystem(Spawner *spawner);
    bool update(Entity *unit);
private:
    Spawner     *_spawner;
};

#endif //CPP_RTYPE_MOVESYSTEM_HPP
