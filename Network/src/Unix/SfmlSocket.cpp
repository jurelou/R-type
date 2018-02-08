//
// Created by louis on 11/01/18.
//


#include <netinet/in.h>
#include <arpa/inet.h>
#include "SfmlSocket.hpp"

SfmlSocket::SfmlSocket()
{
    std::cout << "Creating SFML socket" << std::endl;
    _close = true;
    _udp = false;
    _host = "";
    _socket = UNDEFINED;
}

SfmlSocket::~SfmlSocket()
{
    if (_udp == true){
        this->socketUDP->unbind();
        this->socketUDPRead->unbind();
    } else {
        this->socketTCP->disconnect();
    }
}

void	SfmlSocket::setHost(std::string const & host)
{  _host = host; }

std::string const& SfmlSocket::getHost() const
{
    return _host;
}

void	SfmlSocket::setUDP(bool const & val)
{
    if (_socket == UNDEFINED)
        _udp = val;
}

struct sockaddr_in            SfmlSocket::getSource() const
{ return _addr; }

bool	SfmlSocket::Connect(const std::string& host, const std::string& port)
{
    _portt = stoi(port);
    std::stringstream ss;

    ss << port;
    ss >> usport;
    _host = host;
    if (_udp == false){
        this->socketTCP = new sf::TcpSocket();
        sf::Socket::Status status = this->socketTCP->connect(host, usport);
        if (status != sf::Socket::Done)
            return (false);
    } else {
        _s = host;
        socketUDP = new sf::UdpSocket();
    }
    return (true);
}


bool    SfmlSocket::ConnectFd(int fd)
{
    (void)fd;
    return (true);
}

int	    	SfmlSocket::recv(char **data)
{
    std::size_t res;
    res = 0;
    *data = new char[BUFF_SIZE];
    memset(*data, 0, BUFF_SIZE);
    if (_udp == false){
        if (socketTCP->receive(*data, BUFF_SIZE, res) != sf::Socket::Done) {
            return (0);
        }
    } else {
        sf::IpAddress sender;
        unsigned short port;
        if (socketUDP->receive(*data, BUFF_SIZE, res, sender, port) != sf::Socket::Done) {
            return (0);
        }
    }
    return (res);
}

int		SfmlSocket::sendv(const std::string& data)
{
    if (_udp == false ) {
        socketTCP->send(data.c_str(), data.length());
    } else {
        sf::IpAddress recipient = _host;
        if ((socketUDP->send(data.c_str(), data.length() + 1, recipient, _portt)) != sf::Socket::Status::Done)
            return (1);
    }
    return (0);
}

int             SfmlSocket::getSocket() const
{   return (0); }

bool			SfmlSocket::isUDP() const
{ return _udp; }

void            SfmlSocket::setBlocking(bool _)
{
    if (_udp == false){
        socketTCP->setBlocking(_);
    } else {
        socketUDP->setBlocking(_);
    }
}
