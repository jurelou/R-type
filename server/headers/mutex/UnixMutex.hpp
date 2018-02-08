//
// UnixMutex.hpp for UnixMutex in /home/abachelet/Documents/Rendu/Tek3/cpp_rtype/server/headers/mutex
// 
// Made by Adrien Bachelet
// Login   <adrien.bachelet@epitech.eu>
// 
// Started on  Thu Jan 11 17:55:53 2018 Adrien Bachelet
// Last update Thu Jan 11 17:55:57 2018 Adrien Bachelet
//

#ifndef __UNIXMUTEX_HPP__
#define __UNIXMUTEX_HPP__

#include	<mutex>
#include	"IMutex.hpp"

class		UnixMutex : public IMutex
{
public:
  UnixMutex();
  virtual	~UnixMutex();
  virtual bool	try_lock();
  virtual void	lock();
  virtual void	unlock();

private:
  std::mutex	hmutex;
};

#endif		//__UNIXMUTEX_HPP__
