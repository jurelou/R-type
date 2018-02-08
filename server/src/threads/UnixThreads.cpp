//
// Created by abachelet on 10/01/18.
//

#include "UnixThreads.hpp"

UnixThreads::UnixThreads(FuncPtr ptr, void *arg) : hThread(ptr, arg)
{
}

UnixThreads::~UnixThreads()
{
}

void            UnixThreads::join()
{
  hThread.join();
}

bool UnixThreads::isJoinable()
{  return (hThread.joinable()); }