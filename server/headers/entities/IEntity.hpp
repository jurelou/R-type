//
// Created by louis on 10/01/18.
//

#ifndef CPP_RTYPE_IENTITY_HPP
#define CPP_RTYPE_IENTITY_HPP

class       IEntity{
public:
    virtual const Vertex&   getPos() const = 0;
    virtual void            setPos(Vertex v) = 0;

    virtual void    move() = 0;
};

#endif //CPP_RTYPE_IENTITY_HPP
