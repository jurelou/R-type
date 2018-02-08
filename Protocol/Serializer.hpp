
// Created by marmus_a on 09/01/18.
//

#ifndef R_TYPE_SERIALIZER_HPP
#define R_TYPE_SERIALIZER_HPP

#include <map>
#include <iostream>
#include <sstream>

#if defined(_WIN32) || defined(_WIN64)

#include "IRequest.hpp"

#endif

#include "Protocol.hpp"
#include "CreateGame.hpp"
#include "JoinGame.hpp"
#include "JoinLobby.hpp"
#include "LeaveGame.hpp"
#include "Login.hpp"
#include "Response.hpp"
#include "ListGame.hpp"
#include "NewEntity.hpp"
#include "MoveEntity.hpp"
#include "DeleteEntity.hpp"
#include "PlayerEntered.hpp"
#include "PlayerAccepted.hpp"
#include "PlayerLeaved.hpp"
#include "PlayerMove.hpp"

/* TODO
 *
 * Type:LOGIN;login:toto; // SERVER OK
 * Type:LISTGAME;list:toto,tutu,tata,; 
 * Type:JOINLOBBY;gameId:toto;
 * Type:JOINGAME;gameId:toto;
 * Type:CREATEGAME;gameId:toto;mapId:4;
 * Type:RESPONSE;value:0;
 */
namespace Protocol {

  class Serializer
  {
  public:
    Serializer();
    ~Serializer();
    
    IRequest*     structify(std::string& req);

  private:
    typedef IRequest* (Serializer::*structifyer)(std::map<std::string, std::string>& request);
    std::map<Command, structifyer>  RequestFactory;
    std::map<std::string, Command>  assocRequestType;
    std::map<std::string, std::string>*  requestToMap(const std::string& req);

    IRequest*     structifyLogin(std::map<std::string, std::string>& request);
    IRequest*     structifyListGame(std::map<std::string, std::string>& request);
    IRequest*     structifyJoinLobby(std::map<std::string, std::string>& request);
    IRequest*     structifyJoinGame(std::map<std::string, std::string>& request);
    IRequest*     structifyLeaveGame(std::map<std::string, std::string>& request);
    IRequest*     structifyCreateGame(std::map<std::string, std::string>& request);
    IRequest*     structifyResponse(std::map<std::string, std::string>& request);
    IRequest*     structifyNewEntity(std::map<std::string, std::string>& request);
    IRequest*     structifyMoveEntity(std::map<std::string, std::string>& request);
    IRequest*     structifyDeleteEntity(std::map<std::string, std::string>& request);
    IRequest*     structifyPlayerEntered(std::map<std::string, std::string>& request);
    IRequest*     structifyPlayerAccepted(std::map<std::string, std::string>& request);
    IRequest*     structifyPlayerLeaved(std::map<std::string, std::string>& request);
    IRequest*     structifyPlayerMove(std::map<std::string, std::string>& request);
  };

};

#endif //R_TYPE_SERIALIZER_HPP
