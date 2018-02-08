#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#include    <sys/types.h>
#include    "CrossPlatformSockets.hpp"
#include	"EntityManager.hpp"

#include    "IRequest.hpp"	

namespace Protocol{
   class   Serializer;
}


class Client
{
private:
    Protocol::Serializer    *_serializer;
    Protocol::IRequest    *req;
    EntityManager       *_entityManager;

    ISocket     *_tcp;
    ISocket     *_udp;
    std::vector<std::string>    _gamesList;
    std::map<std::string, int>    _playerLobbyList;
public:
  Client();
  ~Client();

  ISocket *getSocketUdp() const;
  ISocket *getSocketTcp() const;
  bool    initSocket(const std::string&, const std::string&);
  bool      execReq(char *data);
  void      SetEntityManager(EntityManager *entityManager);
  void      setGamesList(std::vector<std::string> gl);
  void      setJoinLobby(const std::string& player);
  void      setPlayerAccepted(const std::string& player);
  std::vector<std::string> getGamesList() const;
  std::map<std::string, int>  getLobbyList() const;
  bool    SendListGame();
  bool    SendLogin(const std::string &login);
  bool    SendLoginUdp(const std::string &login);
  bool    UpdateUdpLobby();
  bool    UpdateTcpLobby();
  bool    SendLoginTcp(const std::string &login);
  bool    SendCreateGame(const std::string& gameId, Protocol::MapLevel lvl);
  bool        NewEntity(Protocol::EntityType type, int id, const Vertex &pos);
  bool        MoveEntity(Protocol::EntityType type, int id, const Vertex &pos);
  bool        SendPlayerMove(Protocol::PlayerAction action);
  bool        DeleteEntity(int id);
  bool        SendJoinGame(const std::string& gameId);
  bool        SendJoinLobby(const std::string& gameId);
  bool        SendExitGame();
  bool        UpdateGameLoop();
  Protocol::Serializer  *getSerializer();

};

#endif /*_CLIENT_HPP_*/

