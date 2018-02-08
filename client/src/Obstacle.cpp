#include        "Obstacle.hpp"

Obstacle::Obstacle(int id, const Vertex& pos) {
  this->id = id;
  this->pos = pos;
  this->rectangle.setSize(sf::Vector2f(32, 32));
  this->rectangle.setFillColor(sf::Color(0, 255, 255));
  this->rectangle.setOrigin(16, 16);
}

Obstacle::~Obstacle()
{}

int             Obstacle::getId() {
  return this->id;
}

void            Obstacle::setPosition(const Vertex& pos, float initTime) {
  this->pos = pos;
}

float           Obstacle::getInternalTime() {
  return this->initTime;
}

void            Obstacle::draw(IGraphicalEngine *graphicalEngine, float elapsedTime) {
  //
}