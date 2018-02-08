#include        "Factory.hpp"
#include        "Monster.hpp"
#include        "Bullet.hpp"
#include        "Human.hpp"
#include        "Obstacle.hpp"

Factory::Factory() {
  this->nbPlayer = 0;
  this->colorPlayer[0] = new sf::Color(255, 0, 0);
  this->colorPlayer[1] = new sf::Color(0, 255, 0);
  this->colorPlayer[2] = new sf::Color(0, 0, 255);
  this->colorPlayer[3] = new sf::Color(255, 255, 0);
  this->colorPlayer[4] = new sf::Color(255, 0, 255);
  this->colorPlayer[5] = new sf::Color(0, 255, 255);
}

Factory::~Factory()
{}

IClientEntity   *Factory::getNewInstance(Protocol::EntityType type, int id, const Vertex& pos) {
  switch (type) {
    case Protocol::EntityType::MONSTER:
      return new Monster(id, pos);
      break;
    case Protocol::EntityType::HUMAN:
      this->nbPlayer += 1;
      return new Human(id, pos, *this->colorPlayer[this->nbPlayer - 1]);
      break;
    case Protocol::EntityType::BULLET:
      return new Bullet(id, pos);
      break;
    case Protocol::EntityType::OBSTACLE:
      return new Obstacle(id, pos);
      break;
    default:
      break;
  };
}