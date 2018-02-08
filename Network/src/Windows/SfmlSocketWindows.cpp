//
// Created by louis on 11/01/18.
//


#include "SfmlSocketWindows.hpp"

SfmlSocketWindows::SfmlSocketWindows()
{
    std::cout << "Creating SFML socket" << std::endl;
    _close = true;
    _socket = UNDEFINED;
    _udp = false;
    _host = "";
}

SfmlSocketWindows::~SfmlSocketWindows()
{
    if (_udp == true){
        this->socketUDP->unbind();
        this->socketUDPRead->unbind();
    }else {
        this->socketTCP->disconnect();
    }
}

void	SfmlSocketWindows::setHost(std::string const & host)
{  _host = host; }

std::string const& SfmlSocketWindows::getHost() const
{
    return _host;
}

void	SfmlSocketWindows::setUDP(bool const & val)
{
    if (_socket == UNDEFINED)
        _udp = val;
}

struct sockaddr_in            SfmlSocketWindows::getSource() const
{ return _addr; }

bool	SfmlSocketWindows::Connect(const std::string& host, const std::string& port)
{
    _portt = stoi(port);
    std::stringstream ss;
    std::stringstream stream;

    ss << port;
    stream << host;
    stream >> _s;
    ss >> usport;
    if (_udp == false){
        this->socketTCP = new sf::TcpSocket();
        sf::Socket::Status status = this->socketTCP->connect(host, usport);
        if (status != sf::Socket::Done)
            return (false);
    } else {
        socketUDP = new sf::UdpSocket();
    }
    return (true);
}


bool    SfmlSocketWindows::ConnectFd(int fd)
{
    (void)fd;
    return (true);
}

int	    	SfmlSocketWindows::recv(char **data)
{
    std::size_t res;
    res = 0;
    *data = new char[BUFF_SIZE];
    memset(*data, 0, BUFF_SIZE);
    if (_udp == false){
        if (socketTCP->receive(*data, BUFF_SIZE, res) != sf::Socket::Done) {
            return (0);
        }
        std::cout << "recv tcp:"<<*data << std::endl;
    } else {
        sf::IpAddress sender;
        unsigned short port;
        if (socketUDP->receive(*data, BUFF_SIZE, res, sender, port) != sf::Socket::Done) {
            return (0);
        }
        std::cout << "recv udp:"<<*data << std::endl;
    }
    return (res);
}

int		SfmlSocketWindows::sendv(const std::string& data)
{
    if (_udp == false ) {
        socketTCP->send(data.c_str(), data.length());
    } else {
        if ((socketUDP->send(data.c_str(), data.length() + 1, _host, _portt)) != sf::Socket::Status::Done)
            return (1);
    }
    return (0);
}

int             SfmlSocketWindows::getSocket() const
{   return (0); }

bool			SfmlSocketWindows::isUDP() const
{ return _udp; }

void            SfmlSocketWindows::setBlocking(bool _)
{
    if (_udp == false){
        socketTCP->setBlocking(_);
    } else {
        socketUDP->setBlocking(_);
    }
}