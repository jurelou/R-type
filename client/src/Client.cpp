#include    <chrono>
#include    <thread>
#include "Client.hpp"
#include "Serializer.hpp"

Client::Client()
{
    _tcp = new MySocket();
    _udp = new MySocket();
    _serializer = new Protocol::Serializer();
}

bool    Client::initSocket(const std::string& host, const std::string& port)
{
    _udp->setUDP(true);
    if (_udp->Connect(host, port) == false)
        return (false);
    if (_tcp->Connect(host, port) == false)
        return (false);
    return (true);
}

Client::~Client()
{}

ISocket *Client::getSocketUdp() const
{ return _udp; }

ISocket *Client::getSocketTcp() const
{ return _tcp; }

void      Client::SetEntityManager(EntityManager *entityManager)
{
    this->_entityManager = entityManager;
}

void      Client::setGamesList(std::vector<std::string> gl)
{
    _gamesList.clear();
    _gamesList = gl;
}

std::map<std::string, int>   Client::getLobbyList() const
{ return _playerLobbyList; }

std::vector<std::string> Client::getGamesList() const
{ return _gamesList; }

void    Client::setJoinLobby(const std::string& playerId)
{
    if (!_playerLobbyList.count(playerId)) {
        _playerLobbyList[playerId] = 0;
    }
}

void    Client::setPlayerAccepted(const std::string& playerId)
{
    _playerLobbyList[playerId] = 1;
}

bool    Client::SendLoginTcp(const std::string &login)
{
    const std::string *tosend = Protocol::Login(login).stringify();
    char *data;
    _tcp->sendv(*tosend);
    _tcp->recv(&data);
    delete tosend;
    return (this->execReq(data));
}

bool    Client::SendLoginUdp(const std::string &login)
{
    const std::string *tosend = Protocol::Login(login).stringify();
    char *data;

    _udp->sendv(*tosend);
    _udp->recv(&data);
    delete tosend;
    return (this->execReq(data));
}

bool    Client::SendLogin(const std::string& login)
{
    bool t1 = this->SendLoginTcp(login);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    bool t2 = this->SendLoginUdp(login);
    if (t1 == true && t2 == true)
        return (true);
    return (false);
}

bool    Client::SendListGame()
{
    char *data;
    const std::string *tosend = Protocol::ListGame().stringify();
    _tcp->sendv(*tosend);
    _tcp->recv(&data);
    delete tosend;
    return (this->execReq(data));
}

bool        Client::SendCreateGame(const std::string& gameId, Protocol::MapLevel lvl)
{
    char *data;
    const std::string *tosend = Protocol::CreateGame(gameId, lvl).stringify();
    _tcp->sendv(*tosend);
    _tcp->recv(&data);
    delete tosend;
    return (this->execReq(data));
}

bool        Client::SendJoinLobby(const std::string& gameId)
{
    char *data;
    const std::string *tosend = Protocol::JoinLobby(gameId, 0, Protocol::EASY, true).stringify();
    _tcp->sendv(*tosend);
    _tcp->recv(&data);
    delete tosend;
    return (this->execReq(data));
}

bool        Client::UpdateUdpLobby()
{
    char *buff;
    _udp->recv(&buff);
    std::string str(buff);
    if (str.size()) {
        Protocol::IRequest *req = _serializer->structify(str);
        if (req->getCommand() != Protocol::RESPONSE)
            return (true);
    }
    return (false);
}

bool        Client::UpdateGameLoop()
{
    char    *data;

    _udp->recv(&data);

    std::string     str(data);
    if (str.length() > 0) {
        Protocol::IRequest *req = _serializer->structify(str);
        req->run(this);
    }
    return (true);
}

bool        Client::NewEntity(Protocol::EntityType type, int id, const Vertex &pos)
{
    _entityManager->setNewEntity(type, id, pos);
    return (true);
}

bool        Client::MoveEntity(Protocol::EntityType type, int id, const Vertex &pos)
{
    _entityManager->moveEntity(type, id, pos);
    return (true);
}

bool        Client::DeleteEntity(int id)
{
    _entityManager->deleteEntity(id);
    return (true);
}

bool        Client::UpdateTcpLobby()
{
  char *buff1;
  _tcp->recv(&buff1);

  std::string str1(buff1);
  if (str1.size()){
      Protocol::IRequest *req = _serializer->structify(str1);
      req->run(this);
  }
  return (true);
}

bool        Client::SendJoinGame(const std::string& gameId)
{
    char *data;
    const std::string *tosend = Protocol::JoinGame(gameId).stringify();
    _tcp->sendv(*tosend);
    _tcp->recv(&data);
    delete tosend;
    return (this->execReq(data));
}

bool        Client::SendPlayerMove(Protocol::PlayerAction action)
{
    const std::string *tosend = Protocol::PlayerMove(action).stringify();
    _udp->sendv(*tosend);
    delete tosend;
    return (true);
}

bool        Client::SendExitGame()
{
    char *data;
    const std::string *tosend = Protocol::LeaveGame().stringify();
    _tcp->sendv(*tosend);
    return (true);
}

bool        Client::execReq(char *data)
{
    std::string s(data);
    Protocol::IRequest *req = _serializer->structify(s);
    if (req){
        return (req->run(this));
    }
    return true;
}

Protocol::Serializer  *Client::getSerializer(){
    return _serializer;
}
