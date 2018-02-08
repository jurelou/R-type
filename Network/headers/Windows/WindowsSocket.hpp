#pragma once
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#ifndef __WINDOWSSOCKET_HPP__
#define	__WINDOWSSOCKET_HPP__

#include    <iostream>
#include	<winsock2.h>
#include	<ws2tcpip.h>
#include	<Windows.h>
#include    <string>
#include    <cstdlib>
#include    <cstring>
#include    <sys/types.h>
#include    <errno.h>
#include    <istream>
#include    <signal.h>
#include    <sstream>
#include    <stdio.h>
#include    <stdlib.h>
#include    <list>

#include    "ISocket.hpp"

typedef _W64 unsigned int ssize_t;
# define    UNDEFINED 0
# define    BUFF_SIZE       2048

class	    WindowsSocket : public ISocket
{
public:
    virtual ~WindowsSocket();
    WindowsSocket();

    bool	Connect(const std::string& host, const std::string& port);
    bool	ConnectFd(int fd);

    int		recv(char **data);
    int		sendv(const std::string& data);

    int		getSocket() const;
    struct sockaddr_in            getSource() const;
    void	setUDP(const bool& val);
    bool	isUDP() const;
    void	setHost(const std::string& ip);
    const std::string&	getHost() const;
    struct sockaddr_in		_addr;
private:
    struct hostent		* _server;
    int				_socket;
    std::string			_host;
    std::string			_port;

    bool				_close;
    bool				_udp;
};

#endif	/*!__WINDOWSSOCKET_HPP__*/