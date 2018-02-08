//
// Created by louis on 15/01/18.
//

#include "Shootable.hpp"

Shootable::Shootable(double fRate)
{
    _fRate = fRate;
    _timer = new Clock();
    _timer->start();
}

Shootable::~Shootable()
{}

const double&   Shootable::getFireRate() const
{ return _fRate; }

bool                    Shootable::canShoot() const
{
    if (_timer->getElapsedSeconds() >= _fRate){
        return (true);
    }
    return (false);
}

void    Shootable::shoot()
{ _timer->start(); }