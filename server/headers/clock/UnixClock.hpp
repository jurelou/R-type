//
// Created by louis on 15/01/18.
//

#ifndef CPP_RTYPE_UNIXCLOCK_HPP
#define CPP_RTYPE_UNIXCLOCK_HPP

#include <chrono>
#include "IClock.hpp"

class UnixClock : public IClock
{
public:
    UnixClock();
    virtual ~UnixClock();
    virtual void   start();
    virtual void   reset();
    virtual double getElapsedSeconds();
private:
    std::chrono::steady_clock::time_point _begin;
    std::chrono::steady_clock::time_point _current;
};
#endif //CPP_RTYPE_UNIXCLOCK_HPP
