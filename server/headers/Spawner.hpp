//
// Created by louis on 14/01/18.
//

#ifndef CPP_RTYPE_SPAWNER_HPP
#define CPP_RTYPE_SPAWNER_HPP

#include <unordered_map>

#include "Entity.hpp"
#include "Player.hpp"
#include "Server.hpp"

#include "CrossPlatformClock.hpp"

#include "Monster.hpp"
#include "Bullet.hpp"
#include "Human.hpp"
#include "Obstacle.hpp"

namespace Protocol {
  class Serializer;
}

#define MAX_HEIGHT  720
#define MAX_WIDTH   1280

class       Game;
//class       Player;

class       Spawner
{
public:
    Spawner(Game *game);
    ~Spawner();

    void        init(std::list<Player *> players, Protocol::MapLevel lvl);
    bool        update();

    const std::unordered_map<int, Entity *>& getEntities() const;

    void        addWaitingBullet(Entity *unit);
    Vertex&   findPositionFromId(int id);
    Vertex&   findDirectionFromId(int id);
    Game *      getGame() const;
    void        broadcastUdp(const std::string& msg);
private:
    Game                *_game;
    Protocol::MapLevel  _lvl;
    std::unordered_map<int, Entity *>   _entities;
    std::list<Bullet *>     waitingBullets;
    Protocol::Serializer* _serializer;

    Clock   *clock;
    std::list<Player *>     _players;
    int    generateRandomWidth();
    int    generateRandomHeight();

    Clock               *_monsterSpawn;
    double  _monsterFrequency;

    void        legendary();
    void        easy();
};
#endif //CPP_RTYPE_SPAWNER_HPP
