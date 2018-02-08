//
// IMutex.hpp for IMutex in /home/abachelet/Documents/Rendu/Tek3/cpp_rtype/server/headers/mutex
// 
// Made by Adrien Bachelet
// Login   <adrien.bachelet@epitech.eu>
// 
// Started on  Thu Jan 11 17:55:17 2018 Adrien Bachelet
// Last update Thu Jan 11 17:55:39 2018 Adrien Bachelet
//


#ifndef __IMUTEX_HPP__
#define __IMUTEX_HPP__

class           IMutex
{
public:
    virtual bool try_lock() = 0;
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

#endif //__IMUTEX_HPP__
