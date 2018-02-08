
#ifndef     __UNIXSOCKET__HPP__
# define    __UNIXSOCKET__HPP__

#include    <iostream>
#include    <string>
#include    <cstdlib>
#include    <cstring>
#include    <netinet/in.h>
#include    <sys/socket.h>
#include    <sys/select.h>
#include    <sys/time.h>
#include    <sys/types.h>
#include    <sys/ioctl.h>
#include    <curses.h>
#include    <errno.h>
#include    <istream>
#include    <netdb.h>
#include    <signal.h>
#include    <sstream>
#include    <stdio.h>
#include    <stdlib.h>
#include    <term.h>
#include    <unistd.h>
#include    <list>

#include    "ISocket.hpp"

# define    UNDEFINED 0
# define    BUFF_SIZE       2048

class	    UnixSocket : public ISocket
{
public:
    virtual ~UnixSocket();
    UnixSocket();

    bool	Connect(const std::string& host, const std::string& port);
    bool	ConnectFd(int fd);

    int		recv(char **data);
    int		sendv(const std::string& data);
    void    setBlocking(bool _);
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


#endif      /* __UNIXSOCKET__HPP__ */
