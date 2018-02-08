//
// UnixMutex.cpp for UnixMutex in /home/abachelet/Documents/Rendu/Tek3/save_rtype/unit_test/mutex/src/mutex
// 
// Made by Adrien Bachelet
// Login   <adrien.bachelet@epitech.eu>
// 
// Started on  Thu Jan 11 16:30:52 2018 Adrien Bachelet
// Last update Thu Jan 11 16:40:23 2018 Adrien Bachelet
//

#include	"../../header/mutex/UnixMutex.hpp"

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
