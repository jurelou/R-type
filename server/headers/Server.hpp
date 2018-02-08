#ifndef             __SERVER__HPP__
#define             __SERVER__HPP__

#include            <list>
#include            <vector>
#include            "Game.hpp"
#include            "Player.hpp"
#include            "CrossPlatformSockets.hpp"

class               Server
{
  public:
    Server(const std::string &remote);
    ~Server();

    SocketMonitor   *getSocketMonitor() const;
    const std::list<Game *> &getGamesList();
    void    execCmd(char *data, ISocket *s);
    int     getNbPlayers() const;
    int     getNbGames() const;

    void    acceptPlayerInGame(ISocket *userSockets);

    Game    *getGameById(std::string id) const;
    void    deleteGameById(std::string id);
    void        receiveUdp(ISocket *udp);
    void        addTCPtoCli(Protocol::IRequest *req, ISocket *socket);
    // commandes
    void    createPlayer(std::string id, ISocket* userSockets);
    void    sendAllGames(ISocket* userSockets) const;
    void    setPlayerOfflineBySocket(ISocket *s);
    void    createGame(std::string id, Protocol::MapLevel lvl, ISocket* userSockets);
    void    addPlayerToLobby(std::string gid, ISocket* userSockets);
    void    kickPlayer(ISocket* s);
    void    addUDPtoplayer(std::string id, ISocket *userSockets);
    Player *getPlayerBySocket(ISocket *socket);
    Protocol::Serializer & getSerializer();
private:
    SocketMonitor           *_ssocket;
    Protocol::Serializer    *_serializer;

    std::list<Game *>       _games;
    std::list<Player*>     _players;

    bool    userAlreadyExists(const std::string& id, ISocket* sockets) const;
};

#endif              /* __SERVER__HPP__ */

