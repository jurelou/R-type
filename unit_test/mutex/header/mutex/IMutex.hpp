//
// IMutex.hpp for IMutex in /home/abachelet/Documents/Rendu/Tek3/save_rtype/unit_test/mutex/header/mutex
// 
// Made by Adrien Bachelet
// Login   <adrien.bachelet@epitech.eu>
// 
// Started on  Thu Jan 11 16:23:17 2018 Adrien Bachelet
// Last update Thu Jan 11 17:33:15 2018 Adrien Bachelet
//

#ifndef		__CPP_RTYPE_IMUTEX_HPP__
#define		__CPP_RTYPE_IMUTEX_HPP__

class		IMutex
{
public:
  virtual bool	try_lock() = 0;
  virtual void	lock() = 0;
  virtual void	unlock() = 0;
};

#endif		//__CPP_RTYPE_IMUTEX_HPP__
