//
// Created by louis on 09/01/18.
//

#ifndef CPP_RTYPE_GAME_H
#define CPP_RTYPE_GAME_H

#include    <iostream>
#include    <vector>
#include    <chrono>
#include    <map>
#include    <list>
#include    <string>
#include    "Protocol.hpp"
#include    "CrossPlatformThreads.hpp"
#include    "Player.hpp"

/*#include "Monster.hpp"
#include "Bullet.hpp"
#include "Vertex.hpp"
#include "Human.hpp"*/
//#include "Spawner.hpp"
//#include "ISystem.hpp"

//#include "MoveSystem.hpp"
//#include "ControlSystem.hpp"
//#include "ShootSystem.hpp"
class MoveSystem;
class ShootSystem;
class ControlSystem;
class Spawner;
class ISystem;
class MoveSystem;


class   Game {
public:
    Game(const std::string& id, Protocol::MapLevel lvl);
    ~Game();

    void        start();
    void        init();
    bool        loop();
    void                addPlayer(Player *p);
    void                removePlayer(Player *p);

    const bool&         isStarted() const;
    int          getNbPlayers() const;

    const std::string&  getId() const;
    const std::list<Player *>& getPlayers() const;

    void                purge();
    Protocol::MapLevel  getGameLevel() const;

    void        broadcastTcp(const std::string& data);
    Thread      *getThread() const;
private:
    bool                _started;
    std::string         _id;
    Protocol::MapLevel  _lvl;
    std::list<Player *> _players;
    Thread             *_thread;

    Spawner                 *_spawner;
    std::vector<ISystem *>  _systems;
    MoveSystem  *ms;
};

void     *routine(void *data);

#endif //CPP_RTYPE_GAME_H