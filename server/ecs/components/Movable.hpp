//
// Created by marmus_a on 13/01/18.
//

#ifndef R_TYPE_MOVABLE_HPP
#define R_TYPE_MOVABLE_HPP

#include    <cmath>
#include    <math.h>
#include    "AMovable.hpp"

class Movable : public AMovable{

public:
    Movable(const Vertex& pos, const Vertex& dir, const float& speed);
    virtual ~Movable();

    const Vertex& getStart();
    const Vertex& getDirection();
    const Vertex& getEnd();

    bool        isMoving();
    void        setMoving(bool move);
    void        updatePos();

    const float&       getSpeed() const;
    const float&       getDistance() const;

protected:
    Vertex end;

    Vertex  start;
    float   distance;
    float   speed;
    Vertex  direction;
    bool    moving;
};

#endif //R_TYPE_MOVABLE_HPP
