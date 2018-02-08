//
// Created by louis on 09/01/18.
//

#include "Game.hpp"
#include "MoveSystem.hpp"
#include "ControlSystem.hpp"
#include "ShootSystem.hpp"
#include "CollisionSystem.hpp"

Game::Game(const std::string& id, Protocol::MapLevel lvl)
{
    _started = false;
    _id = id;
    _lvl = lvl;
    _thread = NULL;
}

Game::~Game()
{}

void    Game::start()
{
    for (auto it : _players){
        it->setStatus(Protocol::INGAME);
        it->setGameId(this->_id);
    }
    _thread = new Thread(routine, (void*) this);
}


const bool&    Game::isStarted() const
{ return _started; }

const std::string&  Game::getId() const
{ return _id; }

const std::list<Player *>& Game::getPlayers() const
{ return _players; }

void        Game::addPlayer(Player *p)
{
    p->setGameId(this->_id);
    p->setStatus(Protocol::INLOBBY);
    _players.push_back(p);
}


void        Game::purge()
{
    _players.remove_if([](Player *p){
        if (p->getStatus() == Protocol::INGAME || p->getStatus() == Protocol::INLOBBY)
            return (true);
        return (false);
    });
}

Protocol::MapLevel  Game::getGameLevel() const
{ return _lvl; }

int             Game::getNbPlayers() const
{ return _players.size(); }


void        Game::broadcastTcp(const std::string& data)
{
    for (auto it : _players){
        if (it->getStatus() != Protocol::OFF)
            it->getSocketTcp()->sendv(data);
    }
}

void        Game::init()
{
    _spawner = new Spawner(this);
    _started = true;
    _spawner->init(_players, _lvl);
    _systems.push_back(new ControlSystem(_spawner));
    _systems.push_back(new MoveSystem(_spawner));
    _systems.push_back(new ShootSystem(_spawner));
    _systems.push_back(new CollisionSystem(_spawner));
}

bool    Game::loop()
{
    for (auto entity : _spawner->getEntities())
    {
        for (auto system : _systems){
            system->update(entity.second);
        }
    }
    return(_spawner->update());
}

void                Game::removePlayer(Player *p)
{
    _players.remove_if([](Player *p){
        if (p->getStatus() == Protocol::ONLINE )
            return (true);
        return (false);
    });
}

Thread *Game::getThread() const
{    return _thread; }

void     *routine(void *data)
{
    Game    *game = static_cast<Game*>(data);

    game->init();
    std::chrono::time_point<std::chrono::steady_clock> fpsTimer(std::chrono::steady_clock::now());
    std::chrono::duration<int32_t, std::ratio<1, 60>> FPS{};;

    while (true)
        {
            FPS = std::chrono::duration_cast<std::chrono::duration<int32_t, std::ratio<1, 60>>>(std::chrono::steady_clock::now() - fpsTimer);
            if (FPS.count() >= 1){

                fpsTimer = std::chrono::steady_clock::now();
                if (game->loop() == false)
                    return nullptr;

            }
        }
}
