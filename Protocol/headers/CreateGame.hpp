//
// Created by marmus_a on 10/01/18.
//

#ifndef R_TYPE_CREATEGAME_HPP
#define R_TYPE_CREATEGAME_HPP

#include "ARequest.hpp"

namespace Protocol {

  class CreateGame : public ARequest {
  public:
    CreateGame();
    CreateGame(const std::string& gameId, MapLevel mapId);
    virtual ~CreateGame();

    std::string           gameId;
    MapLevel                   mapId;
    virtual std::string*  stringify();
#ifdef SERVER
        virtual bool          run(Server *s, ISocket* userSockets);
#else
        virtual bool          run(Client *c);
#endif
    private:
        Protocol::MapLevel  convertToEnum(int i);
        int                 convertToInt(Protocol::MapLevel lvl);
  };

}

#endif //R_TYPE_CREATEGAME_HPP
