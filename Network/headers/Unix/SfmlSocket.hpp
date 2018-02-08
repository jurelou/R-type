//
// Created by louis on 11/01/18.
//

#ifndef CPP_RTYPE_SFMLSOCKET_HPP
#define CPP_RTYPE_SFMLSOCKET_HPP

#include    <iostream>
#include    <string>
#include    <sstream>
#include    <string.h>
#include    <SFML/Network.hpp>
#include    "ISocket.hpp"

# define    UNDEFINED 0
# define    BUFF_SIZE       200

class	    SfmlSocket : public ISocket
{
public:
    virtual ~SfmlSocket();
    SfmlSocket();

    bool	Connect(const std::string& host, const std::string& port);
    bool	ConnectFd(int fd);

    int		recv(char **data);
    int		sendv(const std::string& data);

    int		getSocket() const;

    void	setUDP(const bool& val);
    bool	isUDP() const;

    void    setBlocking(bool _);

    void	setHost(const std::string& ip);
    const std::string&	getHost() const;
    struct sockaddr_in            getSource() const;
    sf::TcpSocket*	 socketTCP;
    sf::UdpSocket*	 socketUDP;
    sf::UdpSocket*	 socketUDPRead;

private:
    int				_socket;
    struct hostent		* _server;
    std::string			_host;
    std::string			_port;
    struct sockaddr_in		_addr;

    bool				_close;
    bool				_udp;
    int             _portt;

    int			    portUDP;
    int				portTCP;
    unsigned short usport;
    sf::IpAddress   _s;

};


#endif //CPP_RTYPE_SFMLSOCKET_HPP
