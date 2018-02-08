//
// Created by abachelet on 10/01/18.
//

#include "../../header/threads/UnixThreads.hpp"

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
