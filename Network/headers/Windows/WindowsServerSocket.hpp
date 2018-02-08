#ifndef __WINDOWSSERVERSOCKET_HPP__
#define __WINDOWSSERVERSOCKET_HPP__

#include    <sys/types.h>
#include    <sys/socket.h>
#include    <sys/select.h>
#include    <netinet/in.h>
#include    <arpa/inet.h>
#include    <map>
#include    <sstream>
#include    <list>

#include    "IServerSocket.hpp"
#include    "WindowsSocket.hpp"
#include    "Protocol.hpp"
#include    "Serializer.hpp"

class       WindowsServerSocket : public IServerSocket
{
public:
    WindowsServerSocket(Server *s);
    virtual	~WindowsServerSocket();

    bool    init(std::string const & listenHost, std::string const &listenPort);
    ISocket *Accept(void * sockType);
    void    launch();
    std::map<int, ISocket *>   getClientsSocketMap() const;
    std::map<std::string, ISocket *>   getClientsSocketUdpMap() const;
    TcpUdpPair                getUserPair(int sock) const;
private:
    Server          *_server;
    Protocol::Serializer      _serializer;

    struct sockaddr_in		_addr;
    int				_socketTcp;
    int				_socketUdp;
    int             _remote;

    void		    addNewPeer(void * sock);
    int		        Select();
    void		    callBack(std::list<int>::iterator& it);
    fd_set			_readFd;

    std::list<std::pair<ISocket*, ISocket*>>      _userList;
    std::list<int>                      _clientsList;
    std::map<int, ISocket *>	        _clientsSocketMap;
    std::map<std::string, ISocket *>	_clientsSocketUdpMap;

};

#endif /*!__WINDOWSSERVERSOCKET_HPP__*/