
#include "Server.hpp"
#include "Serializer.hpp"
#include    <netinet/tcp.h>

Server::Server(const std::string &port)
{
    _ssocket = new SocketMonitor(this);
    _serializer = new Protocol::Serializer();
    Game *g = new Game("default_game", Protocol::EASY);
    _games.push_back(g);


    if (_ssocket->init("", port) == true)
        _ssocket->launch();
}

Server::~Server()
{
  delete _serializer;
}

SocketMonitor   *Server::getSocketMonitor() const
{ return _ssocket; }

const std::list<Game *> &Server::getGamesList()
{ return _games; }

int     Server::getNbPlayers() const
{ return _players.size(); }

int     Server::getNbGames() const
{ return _games.size(); }

Game    *Server::getGameById(std::string id) const
{
    for (auto it: _games) {
        if (it->getId() == id)
            return it;
    }
    return NULL;
}

void    Server::deleteGameById(std::string id)
{
    for (auto it = _games.begin(); it != _games.end(); it++)
    {
        if ((*it)->getId() == id)
            _games.erase(it);
        else
            it++;
    }
}

void    Server::createGame(std::string id, Protocol::MapLevel lvl, ISocket* userSockets)
{
    for (auto it: _games){
        if (it->getId() == id) {
            std::string *packet = Protocol::Response(false).stringify();
            userSockets->sendv(*packet);
            return ;
        }
    }
    Game *game = new Game(id, lvl);
    _games.push_back(game);
    std::string *packet = Protocol::Response(true).stringify();
    userSockets->sendv(*packet);
}

bool    Server::userAlreadyExists(const std::string& id, ISocket* sockets) const
{
    if (_players.size() > 0) {
        for (auto it: _players) {
            if (it->getId() == id){
                    return (true);
            }
        }
    }
    return (false);
}


void    Server::createPlayer(std::string id, ISocket* userSockets)
{
    ISocket *newTcp;


    newTcp = userSockets;
    if (userAlreadyExists(id, userSockets) == true){
        std::cout << "user " << id << " already exists." << std::endl;
        std::string *packet = Protocol::Response(false).stringify();
        userSockets->sendv(*packet);
    } else {
        std::cout << "user " << id << " WILL BE ADDED" << std::endl;
        _players.push_back(new Player(id, newTcp, nullptr));
        std::string *packet = Protocol::Response(true).stringify();
        userSockets->sendv(*packet);
    }
}
void    Server::sendAllGames(ISocket* userSockets) const
{
    std::vector<std::string>  gameNameList;
    for (auto it : _games){
        gameNameList.push_back(it->getId());
    }
    std::string *packet = Protocol::ListGame(gameNameList).stringify();
    userSockets->sendv(*packet);
}

void    Server::addPlayerToLobby(std::string gid, ISocket* userSockets) {
    for (auto itp: _players) {
        if (itp->getSocketTcp() == userSockets) {
            for (auto itg: _games) {
                if (itg->getId() == gid && itg->isStarted() == false) {
                    itp->setStatus(Protocol::INLOBBY);
                    itg->addPlayer(itp);
                    std::cout << "Player " << itp->getId() << " Joined lobby: " << itg->getId() << std::endl;
                    std::string *packet = Protocol::JoinLobby(itg->getId(), itg->getNbPlayers(), itg->getGameLevel(), itg->isStarted()).stringify();
                    userSockets->sendv(*packet);

                    for (auto i : itg->getPlayers()){

                        std::string *packet2 = Protocol::PlayerEntered(i->getId()).stringify();
                        itp->getSocketTcp()->sendv(*packet2);
                        std::this_thread::sleep_for (std::chrono::milliseconds(500));
                    }


                    std::string *packet2 = Protocol::PlayerEntered(itp->getId()).stringify();
                    itg->broadcastTcp(*packet2);
                    return;
                }
            }
        }
    }
    std::string *packet = Protocol::Response(false).stringify();
    userSockets->sendv(*packet);
}

void    Server::acceptPlayerInGame(ISocket *userSockets){
    for (auto itp: _players) {
        if (itp->getSocketTcp() == userSockets) {
            for (auto itg: _games) {
                if (itg->getId() == itp->getGameId() && itg->isStarted() == false) {
                    itp->setStatus(Protocol::INGAME);

                    std::string *packet = Protocol::PlayerAccepted(itp->getId()).stringify();
                    itg->broadcastTcp(*packet);

                    for (auto itpg : itg->getPlayers()){
                        if (!(itpg->getStatus() == Protocol::INGAME))
                            return;
                    }
                    itg->start();
                    return;
                }
            }
        }
    }
}

void    Server::setPlayerOfflineBySocket(ISocket *s)
{
    std::cout << "Deleting player tcp[" << s->getSocket()<< "]"<<   _players.size()<< std::endl;
    for (auto it: _players) {
        if (it->getSocketTcp() == s) {
                it->setStatus(Protocol::OFF);
        }
    }
    _players.remove_if([](Player *p){
        if (p->getStatus() == Protocol::OFF)
            return (true);
        return (false);
    });
}

void    Server::kickPlayer(ISocket* userSockets)
{
    for (auto itp: _players) {
        if (itp->getSocketTcp() == userSockets) {
            for (auto itg: _games){
                if (itp->getGameId() == itg->getId()) {
                    itp->setStatus(Protocol::ONLINE);
                    itp->setGameId("");
                    itg->removePlayer(itp);
                    itg->purge();
                    std::string *packet = Protocol::PlayerLeaved(itp->getId()).stringify();
                    itg->broadcastTcp(*packet);
                    return;
                }
            }
        }
    }
}

void      Server::execCmd(char *data, ISocket *socket)
{
    std::string s(data);
    if (socket->isUDP() == true){
        Protocol::IRequest *req = _serializer->structify(s);
        if (req) {
            if (req->getCommand() != Protocol::LOGIN){
                std::cout << req->getCommand() << std::endl;
                getPlayerBySocket(socket)->getRequests().push(req);
            }
            else{
                req->run(this, socket);
            }
        }
        return;
    }
    Protocol::IRequest *req = _serializer->structify(s);
    if (req)
        req->run(this, socket);

    std::cout << "  --- Players online ---" << std::endl;

    for (auto it: _players){
        if (it->getSocketUdp() != nullptr) {
            if (it->getStatus() == 0)
                std::cout << "   >id:" << it->getId() << " gameId: " << it->getGameId() << " status: SPECTACTOR tcp:"
                          << it->getSocketTcp()->getSocket() << ", udp:" << ntohs(it->getSocketUdp()->getSource().sin_port) << ")"
                          << std::endl;
            if (it->getStatus() == 1)
                std::cout << "   >id:" << it->getId() << " gameId: " << it->getGameId() << " status: DEAD tcp:"
                          << it->getSocketTcp()->getSocket() << ", udp:" << ntohs(it->getSocketUdp()->getSource().sin_port) << ")"
                          << std::endl;
            if (it->getStatus() == 2)
                std::cout << "   >id:" << it->getId() << " gameId: " << it->getGameId() << " status: INGAME tcp:"
                          << it->getSocketTcp()->getSocket() << ", udp:" << ntohs(it->getSocketUdp()->getSource().sin_port) << ")"
                          << std::endl;
            if (it->getStatus() == 3)
                std::cout << "   >id:" << it->getId() << " gameId: " << it->getGameId() << " status: ONLINE tcp:"
                          << it->getSocketTcp()->getSocket() << ", udp:" << ntohs(it->source.sin_port) << ")"
                          << std::endl;
            if (it->getStatus() == 5)
                std::cout << "   >id:" << it->getId() << " gameId: " << it->getGameId() << " status: OFFLINE tcp:"
                          << it->getSocketTcp()->getSocket() << ", udp:" << ntohs(it->source.sin_port) << ")"
                          << std::endl;
            if (it->getStatus() == 6)
                std::cout << "   >id:" << it->getId() << " gameId: " << it->getGameId() << " status: LOBBY tcp:"
                          << it->getSocketTcp()->getSocket() << ", udp:" << ntohs(it->source.sin_port) << ")"
                          << std::endl;
        } else {
            if (it->getStatus() == 0)
                std::cout << "   >id:" << it->getId() << " gameId: " << it->getGameId() << " status: SPECTACTOR tcp:"
                          << it->getSocketTcp()->getSocket() << ", udp:"  << ")"
                          << std::endl;
            if (it->getStatus() == 1)
                std::cout << "   >id:" << it->getId() << " gameId: " << it->getGameId() << " status: DEAD tcp:"
                          << it->getSocketTcp()->getSocket() << ", udp:"  << ")"
                          << std::endl;
            if (it->getStatus() == 2)
                std::cout << "   >id:" << it->getId() << " gameId: " << it->getGameId() << " status: INGAME tcp:"
                          << it->getSocketTcp()->getSocket() << ", udp:" << ")"
                          << std::endl;
            if (it->getStatus() == 3)
                std::cout << "   >id:" << it->getId() << " gameId: " << it->getGameId() << " status: ONLINE tcp:"
                          << it->getSocketTcp()->getSocket() << ", udp:"  << ")"
                          << std::endl;
            if (it->getStatus() == 5)
                std::cout << "   >id:" << it->getId() << " gameId: " << it->getGameId() << " status: OFFLINE tcp:"
                          << it->getSocketTcp()->getSocket() << ", udp:"  << ")"
                          << std::endl;
            if (it->getStatus() == 6)
                std::cout << "   >id:" << it->getId() << " gameId: " << it->getGameId() << " status: LOBBY tcp:"
                          << it->getSocketTcp()->getSocket() << ", udp:"  << ")"
                          << std::endl;
        }
    }
    std::cout << "  --- Games online ---" << std::endl;
    for (auto it: _games){
        if (it->isStarted() == true)
                std::cout << "   >id:" << it->getId() << " A COMMENCE players:#[";
            if (it->isStarted() == false)
                std::cout << "   >id:" << it->getId() << " A  PAS COMMENCE players:[";
            for (auto itp: it->getPlayers())
            {
                if (itp->getStatus() == Protocol::INGAME)
                    std::cout << "(" << itp->getId() << "; INGAME)";
                if (itp->getStatus() == Protocol::INLOBBY)
                    std::cout << "(" << itp->getId() << "; INLOBBY)";
                if (itp->getStatus() == Protocol::SPECTACTOR)
                    std::cout << "(" << itp->getId() << "; SPEC)";
            }
        std::cout << "] lvl:" << it->getGameLevel() << std::endl;
    }
    std::cout << "  ----------------------" << std::endl;

  _games.remove_if([](Game *game) {
    if (game->isStarted() && game->getThread() && game->getThread()->isJoinable()) {
      game->getThread()->join();
      return (true);
    }
    return (false);
  });
}

void        Server::addUDPtoplayer(std::string id, ISocket *userSockets)
{
    for (auto it: _players){
        if (it->getId() == id) {
            it->setUdpSocket(userSockets);
            it->source = userSockets->getSource();
            std::cout << "User :" << it->getId() << " GO SOCKET UDP WTH:" << ntohs(it->getSocketUdp()->getSource().sin_port) << std::endl;
            it->setStatus(Protocol::ONLINE);

            std::string *packet = Protocol::Response(true).stringify();
            userSockets->sendv(*packet);
            return;
        }
    }
    std::string *packet = Protocol::Response(false).stringify();
    userSockets->sendv(*packet);
}

void        Server::receiveUdp(ISocket *udp)
{
    for (auto it : _players)
    {
        std::cout << ">"<<it->getSocketUdp()->getSocket() << std::endl;
    }
}

Player *Server::getPlayerBySocket(ISocket *socket) {
    for (auto player : _players) {
        if (player->source.sin_port == socket->getSource().sin_port && player->getStatus() != Protocol::OFF) {
            return player;
        }
    }
    return nullptr;
}