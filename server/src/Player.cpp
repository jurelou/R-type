//
// Created by louis on 09/01/18.
//

#include "Player.hpp"

Player::Player(const std::string& id, ISocket *_tcp, ISocket *_udp)
{
    _username = id;
    _status = Protocol::OFFLINE;
    _gameId = "";
    _socketTcp = _tcp;
    _socketUdp = nullptr;
}

Player::~Player()
{}

const std::string& Player::getId() const
{ return _username; }

const Protocol::PlayerStatus& Player::getStatus() const
{ return _status; }

const std::string& Player::getGameId() const
{ return _gameId; }

ISocket     *Player::getSocketTcp() const
{ return _socketTcp; }

ISocket     *Player::getSocketUdp() const
{ return _socketUdp; }

void    Player::setStatus(Protocol::PlayerStatus s)
{ _status = s; }

void        Player::setGameId(const std::string& gid)
{ _gameId = gid; }

void        Player::setUdpSocket(ISocket *s)
{
    _socketUdp = s;
}

SafeQueue<Protocol::IRequest *> &Player::getRequests()
{return this->_requests;}
