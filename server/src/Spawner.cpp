//
// Created by louis on 14/01/18.
//

#include "Spawner.hpp"
#include "Serializer.hpp"
#include <random>

Spawner::Spawner(Game *game)
{
    _serializer = new Protocol::Serializer();
    _game = game;
    _monsterFrequency = -1;
    _monsterSpawn = new Clock();
    _monsterSpawn->start();
}

Spawner::~Spawner()
{
    delete _serializer;
}

void        Spawner::easy()
{
    Vertex pos(10, generateRandomHeight());
    Vertex dir(MAX_WIDTH / 2,generateRandomHeight());
    _monsterFrequency = 3;
    std::string *query;

    pos.set(MAX_WIDTH, generateRandomHeight());
    dir.set(0, generateRandomHeight());
    auto m3 = new Monster(pos, dir, 5, 2);
    query = Protocol::NewEntity(m3->getType(), m3->getId(), pos).stringify();
    _entities.insert(std::make_pair(m3->getId(), m3));
    broadcastUdp(*query);

    pos.set(MAX_WIDTH, generateRandomHeight());
    dir.set(0, generateRandomHeight());
    auto m4 = new Monster(pos, dir, 5, 2);
    query = Protocol::NewEntity(m4->getType(), m4->getId(), pos).stringify();
    _entities.insert(std::make_pair(m4->getId(), m4));
    broadcastUdp(*query);
}

void        Spawner::legendary()
{
    Vertex pos(10, generateRandomHeight());
    Vertex dir(0,generateRandomHeight());
    _monsterFrequency = 0.5;
    std::string *query;

    pos.set(MAX_WIDTH, generateRandomHeight());
    dir.set(0, generateRandomWidth());
    auto m2 = new Monster(pos, dir, 50, 1);
    query = Protocol::NewEntity(m2->getType(), m2->getId(), pos).stringify();
    _entities.insert(std::make_pair(m2->getId(), m2));
    broadcastUdp(*query);

    pos.set(MAX_WIDTH, generateRandomHeight());
    dir.set(0, generateRandomWidth());
    auto m3 = new Monster(pos, dir, 30, 1);
    query = Protocol::NewEntity(m3->getType(), m3->getId(), pos).stringify();
    _entities.insert(std::make_pair(m3->getId(), m3));
    broadcastUdp(*query);
}

void        Spawner::init(std::list<Player *> players, Protocol::MapLevel lvl){
    _lvl = lvl;
    _players = players;

    if (lvl == Protocol::LEGENDARY){
        legendary();
    } else if (lvl == Protocol::EASY){
        easy();
    }
    Vertex pos(20, generateRandomHeight());
    for (auto it: players) {
        auto p = new Human(pos, it);
        _entities.insert(std::make_pair(p->getId(), p));
        std::string *query = Protocol::NewEntity(Protocol::HUMAN, p->getId(), pos).stringify();
        broadcastUdp(*query);

    }
}

bool        Spawner::update()
{
    int deadcpt = 0;

    for (auto a : _game->getPlayers()){
        if (a->getStatus() == Protocol::INGAME || a->getStatus() == Protocol::INLOBBY)
            deadcpt++;
    }
    if (deadcpt == 0)
        return (false);
    for (auto it = _entities.begin(); it != _entities.end();)
    {
        if (it->second->isRemovable() == true){
            std::string     *query = Protocol::DeleteEntity(it->second->getId()).stringify();
            broadcastUdp(*query);
            it = _entities.erase(it);
        }
        else
            it++;
    }
    for (auto it : waitingBullets){
        for (auto i: it->getComponents())
        {
            auto movable = dynamic_cast<Movable *>(i);
            if (movable) {
                std::string     *query = Protocol::NewEntity(it->getType(), it->getId(), movable->getPos()).stringify();
                broadcastUdp(*query);
                _entities.insert(std::make_pair(it->getId(), it));
            }
        }
    }
    waitingBullets.clear();
    if (_monsterFrequency != -1 && _monsterSpawn->getElapsedSeconds() >= _monsterFrequency){
        Vertex begin(MAX_WIDTH,generateRandomHeight());
        Vertex end(0,0);
        Monster *m;
        if (_lvl == Protocol::EASY || _lvl == Protocol::MEDIUM){
            end.set(200,generateRandomHeight());
            m = new Monster(begin, end, 5, 2);
        }
        else{
            end.set(0,generateRandomHeight());
            begin.set(MAX_WIDTH - 300, generateRandomHeight());
            m = new Monster(begin, end, 30, 0.3);
        }

        _entities.insert(std::make_pair(m->getId(), m));
        std::string     *query = Protocol::NewEntity(m->getType(), m->getId(), begin).stringify();
        broadcastUdp(*query);
        _monsterSpawn->reset();
    }
    return (true);
}

const std::unordered_map<int, Entity *>&    Spawner::getEntities() const
{ return _entities; }

int    Spawner::generateRandomWidth()
{    return std::rand() % (MAX_WIDTH - 100) + 100; }

int    Spawner::generateRandomHeight()
{    return std::rand() % (MAX_HEIGHT - 70) + 70; }

void        Spawner::addWaitingBullet(Entity *unit)
{
    for (auto it: unit->getComponents())
    {
        auto movable = dynamic_cast<Movable *>(it);
        if (movable) {
            if (_lvl == Protocol::EASY || _lvl == Protocol::MEDIUM){
                waitingBullets.push_back(new Bullet(unit->getId(), movable->getPos(), movable->getEnd(), 15));
            } else{
                waitingBullets.push_back(new Bullet(unit->getId(), movable->getPos(), movable->getEnd(), 70));
            }
        }

        auto controlable = dynamic_cast<Controlable *>(it);
        if (controlable) {
            Vertex  end(MAX_WIDTH,controlable->getPos().y);
                waitingBullets.push_back(new Bullet(unit->getId(), controlable->getPos(), end, 70));
        }
    }
}

void        Spawner::broadcastUdp(const std::string& msg)
{
    for (auto it: _players){
        if (it->getStatus() != Protocol::OFFLINE && it->getStatus() != Protocol::OFF){
            ::sendto(it->getSocketUdp()->getSocket(), msg.c_str(), msg.size(), 0, (struct sockaddr *)&it->source, sizeof(it->source));
        }

    }
}

Game *Spawner::getGame() const{
  return (_game);
}
