
#include "WindowServerSocket.hpp"

WindowServerSocket::WindowServerSocket(Server *s)
{
    //_packet = new PacketManager(s);
    this->_socketTcp = UNDEFINED;
    this->_socketUdp = UNDEFINED;
    _server = s;
}

WindowServerSocket::~WindowServerSocket()
{
  if (this->_socketTcp != UNDEFINED)
    close(this->_socketTcp);
}


bool	WindowServerSocket::init(const std::string& host, const std::string& _port)
{
  int	i;
  std::stringstream ss;
  ss << _port;
  ss >> _remote;
  ss.clear();
  bzero((char *) &(this->_addr), sizeof(this->_addr));

  _addr.sin_family = AF_INET;
  _addr.sin_addr.s_addr = INADDR_ANY;
  _addr.sin_port = htons(_remote);
  _socketTcp = socket(AF_INET, SOCK_STREAM, 0);
  if (this->_socketTcp <= 0) {
    std::cerr << "socket TCP failed" << std::endl;
    return false;
  }
  i = bind( this->_socketTcp, (struct sockaddr *) &this->_addr, sizeof(this->_addr));
  if (i < 0) {
    std::cerr << "bind TCP failed" << std::endl;
    close(this->_socketTcp);
    return false;
  }
  if (listen(_socketTcp, 5) < 0) {
    std::cerr << "listen TCP failed" << std::endl;
    return false;
  }


  this->_addr.sin_port = htons(_remote);
  this->_socketUdp = socket(AF_INET, SOCK_DGRAM, 0);
  if (this->_socketUdp <= 0) {
    std::cerr << "socket UDP failed" << std::endl;
    return false;
  }
  i = bind(this->_socketUdp, (struct sockaddr *) &this->_addr, sizeof(this->_addr));
  if (i < 0) {
    std::cerr << "bind UDP failed" << std::endl;
    close(this->_socketUdp);
    return false;
  }
  ISocket *udp = new MySocket();
  udp->setUDP(true);
  udp->ConnectFd(_socketUdp);
  this->_clientsSocketMap[((UnixSocket *)(udp))->getSocket()] = udp;
  return true;
}

void	WindowServerSocket::launch()
{
  std::cout << "Server listening on port "<< _remote << std::endl;
  _clientsList.push_back(_socketTcp);
  _clientsList.push_back(_socketUdp);
  while (true)
  {
    int nbSocksReady = this->Select();
      std::cout << nbSocksReady << std::endl;
    for (auto it = _clientsList.begin(); nbSocksReady > 0 && it != _clientsList.end(); it++)
      if (FD_ISSET((*it), &_readFd))
      {
        nbSocksReady--;
        if ((*it) == _socketTcp)
          this->addNewPeer(&(*it));
        else
          this->callBack(it);
      }
  }
}

int		WindowServerSocket::Select()
{
    int		nbSocksReady;
    int		maxFd;

    maxFd = 0;
    FD_ZERO(&_readFd);
    for (auto it  :_clientsList)
    {
        if (maxFd < it)
            maxFd = it;
        FD_SET((it), &_readFd);
    }
    if ((nbSocksReady = select(maxFd + 1, &_readFd, NULL, NULL, 0)) == -1)
    {
        std::cerr << "Server select() error: " << std::endl;
        return -1;
    }
    return nbSocksReady;
}

void	WindowServerSocket::addNewPeer(void * peer)
{
    static int id = 0;
    std::ostringstream os;
    ISocket *sockTcp = this->Accept(peer);
    ISocket *sockUdp = new UnixSocket();
    sockUdp->setUDP(true);
    os << this->_remote;
    sockUdp->Connect(sockTcp->getHost(), "");
    this->_userList.push_back(std::pair<ISocket*, ISocket*>(sockTcp, sockUdp));
    this->_clientsList.push_back(((UnixSocket *)(sockTcp))->getSocket());
    this->_clientsSocketMap[((UnixSocket *)(sockTcp))->getSocket()] = sockTcp;
    this->_clientsList.push_back(((UnixSocket *)(sockUdp))->getSocket());
    this->_clientsSocketMap[((UnixSocket *)(sockUdp))->getSocket()] = sockUdp;
    this->_clientsSocketUdpMap[sockUdp->getHost()] = sockUdp;
    std::cout << "new Client !(" << sockTcp->getSocket() <<";" << sockUdp->getSocket()<< ")"<<std::endl;
    id++;
}

TcpUdpPair     WindowServerSocket::getUserPair(int sock) const
{
    if (sock) {
        for (auto it : _userList) {
            if (it.second->getSocket() == sock || it.first->getSocket() == sock) {
                return (std::pair<ISocket *, ISocket *>(it.first, it.second));
            }
        }
    }
    return (std::pair<ISocket*, ISocket*>(nullptr, nullptr));
}

void        WindowServerSocket::callBack(std::list<int>::iterator& it)
{
    ISocket *tmp = _clientsSocketMap[*it];
    char    *data;
    if (!tmp->recv(&data))
    {
        _server->setPlayerOfflineBySocket(tmp);
        _userList.remove(getUserPair(tmp->getSocket()));
        it = _clientsList.erase(it);
        _clientsSocketUdpMap.erase(tmp->getHost());
        _clientsSocketMap.erase(((UnixSocket*)(tmp))->getSocket());
        delete tmp;
        it--;
        return ;
    }
    if (tmp->isUDP() == true) {
        //getUserPair(tmp->getSocket()).second->sendv("mdr");
        //_server->receiveUdp(tmp);
        _server->execCmd(data, tmp);
        //tmp = this->_clientsSocketUdpMap[tmp->getHost()];
        //_server->receiveUdp(g);
    } else {
        _server->execCmd(data, tmp);
    }
}

ISocket	                *WindowServerSocket::Accept(void *sockType)
{
  int			        acceptSock;
  struct sockaddr_in	cli;
  int			        cliSize = sizeof(cli);

  acceptSock = accept(*((int *)sockType), (struct sockaddr *)&cli, (socklen_t *)&cliSize);
  if (acceptSock <= 0) {
    std::cerr << "accept failed with error: " << std::endl;
    return NULL;
  }
  ISocket *ret = new UnixSocket();
  ret->ConnectFd(acceptSock);
  ret->setHost(inet_ntoa(cli.sin_addr));
  return ret;
}

std::map<int, ISocket *>   WindowServerSocket::getClientsSocketMap() const
{ return _clientsSocketMap; }

std::map<std::string, ISocket *>   WindowServerSocket::getClientsSocketUdpMap() const
{ return _clientsSocketUdpMap; }
