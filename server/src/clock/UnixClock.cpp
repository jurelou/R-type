//
// Created by louis on 15/01/18.
//

#include <iostream>
#include "UnixClock.hpp"

UnixClock::UnixClock()
{
}

UnixClock::~UnixClock()
{}

void   UnixClock::start()
{
    _current = std::chrono::steady_clock::now();

}

void UnixClock::reset()
{ start(); }

double UnixClock::getElapsedSeconds()
{
    _begin = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(_begin - _current);
    return (time_span.count());
}