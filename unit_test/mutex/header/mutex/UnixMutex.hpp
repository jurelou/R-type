//
// UnixMutex.hpp for UnixMutex in /home/abachelet/Documents/Rendu/Tek3/save_rtype/unit_test/mutex/header/mutex
// 
// Made by Adrien Bachelet
// Login   <adrien.bachelet@epitech.eu>
// 
// Started on  Thu Jan 11 16:26:58 2018 Adrien Bachelet
// Last update Thu Jan 11 16:48:43 2018 Adrien Bachelet
//

#ifndef		__UNIXMUTEX_HPP__
#define		__UNIXMUTEX_HPP__

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
