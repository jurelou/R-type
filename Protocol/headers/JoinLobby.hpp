//
// Created by marmus_a on 10/01/18.
//


#ifndef R_TYPE_JOINLOBBY_HPP
#define R_TYPE_JOINLOBBY_HPP

#include "../ARequest.hpp"

namespace Protocol {

  class JoinLobby : public ARequest {
  public:
    JoinLobby();
    JoinLobby(const std::string& gameId, int nbPlayers, Protocol::MapLevel mapLevel, bool started);
    virtual ~JoinLobby();

    std::string           gameId;
    int   nbPlayers;
    Protocol::MapLevel    mapLevel;
    bool                  started;
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

#endif //R_TYPE_JOINLOBBY_HPP
