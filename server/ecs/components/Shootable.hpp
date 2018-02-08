//
// Created by louis on 15/01/18.
//

#ifndef CPP_RTYPE_SHOOTABLE_HPP
#define CPP_RTYPE_SHOOTABLE_HPP

#include "IComponent.hpp"
#include "CrossPlatformClock.hpp"

class   Shootable : public IComponent
{
public:
    Shootable(double fRate);
    ~Shootable();

    const double&   getFireRate() const;
    bool    canShoot() const;
    void    shoot();
private:
    double _fRate;
    Clock   *_timer;
};
#endif //CPP_RTYPE_SHOOTABLE_HPP
