//
// Created by marmus_a on 09/01/18.
//

#include "Serializer.hpp"

namespace Protocol {

  Serializer::Serializer() {
    this->RequestFactory[LOGIN] = &Serializer::structifyLogin;
    this->RequestFactory[LISTGAME] = &Serializer::structifyListGame;
    this->RequestFactory[JOINLOBBY] = &Serializer::structifyJoinLobby;
    this->RequestFactory[JOINGAME] = &Serializer::structifyJoinGame;
    this->RequestFactory[LEAVEGAME] = &Serializer::structifyLeaveGame;
    this->RequestFactory[CREATEGAME] = &Serializer::structifyCreateGame;
    this->RequestFactory[RESPONSE] = &Serializer::structifyResponse;
    this->RequestFactory[NEWENTITY] = &Serializer::structifyNewEntity;
    this->RequestFactory[MOVEENTITY] = &Serializer::structifyMoveEntity;
    this->RequestFactory[DELETEENTITY] = &Serializer::structifyDeleteEntity;
    this->RequestFactory[PLAYERENTERED] = &Serializer::structifyPlayerEntered;
    this->RequestFactory[PLAYERACCEPTED] = &Serializer::structifyPlayerAccepted;
    this->RequestFactory[PLAYERLEAVED] = &Serializer::structifyPlayerLeaved;
    this->RequestFactory[PLAYERMOVE] = &Serializer::structifyPlayerMove;
    //this->RequestFactory[]
    this->assocRequestType[std::string("LOGIN")] = LOGIN;
    this->assocRequestType[std::string("LISTGAME")] = LISTGAME;
    this->assocRequestType[std::string("JOINLOBBY")] = JOINLOBBY;
    this->assocRequestType[std::string("JOINGAME")] = JOINGAME;
    this->assocRequestType[std::string("LEAVEGAME")] = LEAVEGAME;
    this->assocRequestType[std::string("CREATEGAME")] = CREATEGAME;
    this->assocRequestType[std::string("RESPONSE")] = RESPONSE;
    this->assocRequestType[std::string("NEWENTITY")] = NEWENTITY;
    this->assocRequestType[std::string("MOVEENTITY")] = MOVEENTITY;
    this->assocRequestType[std::string("DELETEENTITY")] = DELETEENTITY;
    this->assocRequestType[std::string("PLAYERENTERED")] = PLAYERENTERED;
    this->assocRequestType[std::string("PLAYERACCEPTED")] = PLAYERACCEPTED;
    this->assocRequestType[std::string("PLAYERLEAVED")] = PLAYERLEAVED;
    this->assocRequestType[std::string("PLAYERMOVE")] = PLAYERMOVE;
  }

  Serializer::~Serializer() {}

  IRequest* Serializer::structify(std::string &req) {
      Command commandToParse;
      std::map<std::string, std::string>* request;
      request = requestToMap(req);
      if (request->find("Type") == request->end() || this->assocRequestType.find((*request)["Type"]) == this->assocRequestType.end()) {
          std::cout << "error" << std::endl;
          return (nullptr);
      }
      commandToParse = this->assocRequestType[(*request)["Type"]];
      IRequest* res = (this->*(this->RequestFactory[commandToParse]))(*request);
      delete request;
      return res;
  }

  IRequest* Serializer::structifyLogin(std::map<std::string, std::string>& request) {
    if (request.find("login") == request.end()) {
      return (nullptr);
    }
    return (new Login(request["login"]));
  }

  IRequest *Serializer::structifyListGame(std::map<std::string, std::string>& request) {
    std::vector<std::string> gamesId;
    if (request.find("list") == request.end()) {
      return (nullptr);
    }
    std::stringstream str(request["list"]);
    std::string line;

    while (str.rdbuf()->in_avail() != 0) {
        std::getline(str, line, ',');
        gamesId.push_back(line);
      }
    return (new ListGame(gamesId));
  }

  IRequest *Serializer::structifyJoinLobby(std::map<std::string, std::string>& request) {
    if (request.find("gameId") == request.end()) {
      return (nullptr);
    }
    Protocol::MapLevel mapId = (Protocol::MapLevel)std::stoi(request["mapLvl"]);
    if (request["started"] == "0")
        return (new JoinLobby(request["gameId"], std::stoi(request["nbPlayers"]), mapId, false));
      else
        return (new JoinLobby(request["gameId"], std::stoi(request["nbPlayers"]), mapId, true));
  }

  IRequest *Serializer::structifyJoinGame(std::map<std::string, std::string>& request) {
    if (request.find("gameId") == request.end()) {
      return (nullptr);
    }
    return (new JoinGame(request["gameId"]));
  }

  IRequest *Serializer::structifyLeaveGame(std::map<std::string, std::string>& request) {
    if (request.find("gameId") == request.end()) {
      return (nullptr);
    }
    return (new LeaveGame());
  }

  IRequest *Serializer::structifyCreateGame(std::map<std::string, std::string>& request) {
    if (request.find("gameId") == request.end()
        || request.find("mapId") == request.end()) {
      return (nullptr);
    }
    Protocol::MapLevel mapId = (Protocol::MapLevel)std::stoi(request["mapId"]);
    return (new CreateGame(request["gameId"], mapId));
  }

  IRequest *Serializer::structifyResponse(std::map<std::string, std::string>& request) {
    if (request.find("value") == request.end()) {
      return (nullptr);
    }
    if (request["value"] == "0"){
        return (new Response(false));
      }
    return (new Response(true));
  }

  IRequest *Serializer::structifyNewEntity(std::map<std::string, std::string> &request) {
//    NewEntity* res = new NewEntity;
    if (request.find("EntityType") == request.end()
        || request.find("Id") == request.end()
        || request.find("PosX") == request.end()
        || request.find("PosY") == request.end()) {
      return nullptr;
    }
    return new NewEntity(
            static_cast<EntityType>(std::stoi(request["EntityType"])),
            std::stoi(request["Id"]),
            Vertex(std::stof(request["PosX"]),
                   std::stof(request["PosY"])
            ));
  }


  IRequest *Serializer::structifyMoveEntity(std::map<std::string, std::string> &request) {
    if (request.find("Id") == request.end()
        || request.find("PosX") == request.end()
        || request.find("PosY") == request.end()
        || request.find("EntityType") == request.end()) {
      return nullptr;
    }
    return new MoveEntity(
            std::stoi(request["Id"]),
            Vertex(
                   std::stof(request["PosX"]),
                   std::stof(request["PosY"])
            ),
            static_cast<EntityType>(std::stoi(request["EntityType"]))
    );
  }

  IRequest *Serializer::structifyDeleteEntity(std::map<std::string, std::string> &request) {
    if (request.find("Id") == request.end()) {
      return nullptr;
    }
    return new DeleteEntity(std::stoi(request["Id"]));
  }

  IRequest *Serializer::structifyPlayerEntered(std::map<std::string, std::string> &request) {
    if (request.find("PlayerId") == request.end()) {
      return nullptr;
    }
    return new PlayerEntered(request["PlayerId"]);
  }

  IRequest *Serializer::structifyPlayerAccepted(std::map<std::string, std::string> &request) {
    if (request.find("PlayerId") == request.end()) {
      return nullptr;
    }
    return new PlayerAccepted(request["PlayerId"]);
  }

  IRequest *Serializer::structifyPlayerLeaved(std::map<std::string, std::string> &request) {
    if (request.find("PlayerId") == request.end()) {
      return nullptr;
    }
    return new PlayerAccepted(request["PlayerId"]);
  }

  IRequest *Serializer::structifyPlayerMove(std::map<std::string, std::string> &request) {
    if (request.find("Move") == request.end()) {
      return nullptr;
    }
    return new PlayerMove(static_cast<PlayerAction>(std::stoi(request["Move"])));
  }

  std::map<std::string, std::string>* Serializer::requestToMap(const std::string &req) {
    std::map <std::string, std::string>* res = new std::map<std::string, std::string>();
    std::stringstream request(req);
    std::string line;


    while (request.rdbuf()->in_avail() != 0) {
      std::getline(request, line, ';');
      if (line.find(':') != std::string::npos) {
        (*res)[line.substr(0, line.find(':'))] = line.substr(line.find(':') + 1);
      }
    }
    return (res);
  }

}