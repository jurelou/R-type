//
// Created by abachelet on 10/01/18.
//

#ifndef CPP_RTYPE_ITHREADS_HPP
#define CPP_RTYPE_ITHREADS_HPP

class           IThread
{
public:
    virtual     ~IThread() {};
    virtual void join() = 0;

    typedef void* (*FuncPtr)(void*);
};

#endif //CPP_RTYPE_ITHREADS_HPP
