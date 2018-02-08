//
// UnixMutex.cpp for UnixMutex in /home/abachelet/Documents/Rendu/Tek3/cpp_rtype/server/src/mutex
// 
// Made by Adrien Bachelet
// Login   <adrien.bachelet@epitech.eu>
// 
// Started on  Thu Jan 11 17:56:29 2018 Adrien Bachelet
// Last update Thu Jan 11 17:56:36 2018 Adrien Bachelet
//

#include	"UnixMutex.hpp"

UnixMutex::UnixMutex() : hmutex()
{
}

UnixMutex::~UnixMutex()
{
}

bool		UnixMutex::try_lock()
{
    return (hmutex.try_lock());
}

void		UnixMutex::lock()
{
    hmutex.lock();
}

void		UnixMutex::unlock()
{
    hmutex.unlock();
}
