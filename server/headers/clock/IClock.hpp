//
// Created by louis on 15/01/18.
//

#ifndef CPP_RTYPE_ICLOCK_HPP
#define CPP_RTYPE_ICLOCK_HPP

class   IClock
{
public:
    virtual ~IClock() {}
    virtual void   start() = 0;
    virtual void   reset() = 0;
    virtual double getElapsedSeconds() = 0;
};

#endif //CPP_RTYPE_ICLOCK_HPP
