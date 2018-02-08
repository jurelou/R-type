//
// Created by louis on 20/01/18.
//

#ifndef _AMOVABLE_HPP
#define _AMOVABLE_HPP

#include "IComponent.hpp"

class   AMovable : public IComponent{

public:
    AMovable(const Vertex& pos, double boudingCircle);
    virtual ~AMovable();

    virtual const Vertex& getPos();
    virtual void        setPos(const Vertex& pos);
    virtual void        setPos(const float& a, const float& b);

    virtual double   getBoundingCircle() const;
protected:
    Vertex pos;
    double  boundingCircle;

};

#endif //_AMOVABLE_HPP
