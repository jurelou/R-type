#include "WindowsSocket.hpp"

WindowsSocket::WindowsSocket()
{
  std::cout << "Creating UNIX socket" << std::endl;
  _socket = UNDEFINED;
  _close = true;
  _udp = false;
  _host = "";
}

WindowsSocket::~WindowsSocket()
{
  if (!_close)
    closesocket(this->_socket);
}

void	WindowsSocket::setHost(std::string const & host)
{  _host = host; }

std::string const & WindowsSocket::getHost() const
{
  return _host;
}

void	WindowsSocket::setUDP(bool const & val)
{
  if (_socket == UNDEFINED)
    _udp = val;
  else
    std::cerr << "Socket already binded" << std::endl;
}

bool	WindowsSocket::Connect(const std::string& host, const std::string& port)
{
  std::stringstream ss;
  int iPort;

  this->_host = host;
  this->_port = port;
  ss << _port;
  ss >> iPort;

  if (_udp == false)
    this->_socket = socket(AF_INET, SOCK_STREAM, 0);
  else
    this->_socket = socket(AF_INET, SOCK_DGRAM, 0);
  if (this->_socket < 0)
    {
      std::cerr << "Socket failed" << std::endl;
      return false;
    }
  if ((this->_server = gethostbyname(this->_host.c_str())) == NULL)
    {
      std::cerr << "No host found" << std::endl;
      return false;
    }
  memset((char *)&this->_addr, 0, sizeof(this->_addr));
  this->_addr.sin_family = AF_INET;
  memcpy((char *)this->_server->h_addr, (char *)&this->_addr.sin_addr.s_addr, this->_server->h_length);
  this->_addr.sin_port = htons(iPort);
  if (_udp == false)
    if (connect(this->_socket,(struct sockaddr *) &this->_addr,sizeof(this->_addr)) < 0)
      {
	    std::cerr << "connect TCP failed" << std::endl;
	    return false;
      }
  return true;
}


bool    WindowsSocket::ConnectFd(int fd)
{
    this->_socket = fd;
    this->_close = false;
    return true;
}
int	    	WindowsSocket::recv(char **data)
{
    ssize_t ret = 0;

    if (_udp == true)
    {
        socklen_t tosize = sizeof(_addr);
        *data = new char[BUFF_SIZE];
        memset(*data, 0, BUFF_SIZE);
        if ((ret = ::recvfrom(_socket, *data, BUFF_SIZE, 0, (struct sockaddr *)&_addr, &tosize)) <= 0)
            return 0;
        std::cout << "received UDP >" << *data << "< From :" <<_socket <<std::endl;
    } else {
        *data = new char[BUFF_SIZE];
        memset(*data, 0, BUFF_SIZE);
        if ((ret = ::recv(_socket, *data, BUFF_SIZE, 0)) <= 0)
            return 0;
        std::cout << "received TCP >" << *data << "< From :" <<_socket <<std::endl;

    }
    return (ret);
}

int		WindowsSocket::sendv(const std::string& data)
{
  if (_udp == false)
    return ::send(this->_socket, data.c_str(), data.size(), 0);
  else
    return ::sendto(this->_socket, data.c_str(), data.size(), 0, (struct sockaddr *)&this->_addr, sizeof(this->_addr));
}

int             WindowsSocket::getSocket() const
{    return _socket; }

struct sockaddr_in             WindowsSocket::getSource() const
{ return _addr; }

bool			WindowsSocket::isUDP() const
{ return _udp; }
