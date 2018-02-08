//
// Created by abachelet on 10/01/18.
//

#ifndef __UNIXTHREADS_HPP__
#define __UNIXTHREADS_HPP__

#include	<thread>
#include	"IThreads.hpp"

class           UnixThreads : public IThread
{
public:
    typedef void* (*FuncPtr)(void*);

    UnixThreads(FuncPtr, void *arg);
    virtual ~UnixThreads();
    virtual void	join();
    virtual bool isJoinable();

private:
    std::thread	hThread;
};

#endif //__UNIXTHREADS_HPP__
