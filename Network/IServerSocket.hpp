#ifndef		__ISERVERSOCKET__HPP__
#define		__ISERVERSOCKET__HPP__

#include <iostream>
#include <string>
#include "ISocket.hpp"
#include    "Server.hpp"

class IServerSocket
{
public:
	virtual				~IServerSocket() {};
	virtual bool		init(const  std::string& listenHost,  const  std::string& listenPort) = 0;
	virtual ISocket		*Accept(void *sockType) = 0;
	virtual void		launch() = 0;
};

#endif
