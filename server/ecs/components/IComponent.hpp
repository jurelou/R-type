//
// Created by louis on 15/01/18.
//

#ifndef CPP_RTYPE_ICOMPONENT_HPP
#define CPP_RTYPE_ICOMPONENT_HPP

#include "Vertex.hpp"

enum    ComponentType{
    MOVABLE,
    SHOOTABLE
};

class   IComponent
{
public:
    virtual     ~IComponent() {};
};

#endif //CPP_RTYPE_ICOMPONENT_HPP
