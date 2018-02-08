//
// Created by louis on 09/01/18.
//

#ifndef CPP_RTYPE_PLAYER_H
#define CPP_RTYPE_PLAYER_H

#include    <iostream>
#include    <string>
#include    "ISocket.hpp"
#include    "Protocol.hpp"
//#include    "IRequest.hpp"
#include    "SafeQueue.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

namespace Protocol {
  class IRequest;
}

class   Player {
public:
    Player(const std::string& id, ISocket *_tcp, ISocket *_udp);
    ~Player();

    const std::string& getId() const;
    const Protocol::PlayerStatus& getStatus() const;
    void        setGameId(const std::string& gid);
    const std::string& getGameId() const;
    void    setStatus(Protocol::PlayerStatus s);
    ISocket     *getSocketTcp() const;
    ISocket     *getSocketUdp() const;
    SafeQueue<Protocol::IRequest *>&  getRequests();
    void        setUdpSocket(ISocket *s);

    struct sockaddr_in            source;
private:
    SafeQueue<Protocol::IRequest *>       _requests;
    std::string     _gameId;
    std::string     _username;
    Protocol::PlayerStatus  _status;
    ISocket         *_socketTcp;
    ISocket         *_socketUdp;
};

#endif //CPP_RTYPE_PLAYER_H
