#include        "Human.hpp"

Human::Human(int id, const Vertex& pos, sf::Color& color) : currentFrame(64, 0, 64, 128) {
  this->id = id;
  this->pos = pos;
  this->color = color;
}

Human::~Human()
{}

int             Human::getId() {
  return this->id;
}

void            Human::setPosition(const Vertex& pos, float initTime) {
  if (this->pos.x - pos.x < 0) {
    if (this->currentFrame.left > 64 && this->currentFrame.left < 320) {
      this->currentFrame.left += 64;
    }
  } else if (this->pos.x - pos.x > 0) {
    this->currentFrame.left = 0;
  } else {
    this->currentFrame.left = 64;
  }
  this->pos = pos;
  this->initTime = initTime;
}

float           Human::getInternalTime() {
  return this->initTime;
}

void            Human::draw(IGraphicalEngine *graphicalEngine, float elapsedTime) {
  graphicalEngine->placeSpriteAtPos(resourceManager->getPlayerSprite(), pos.x, pos.y, 32, 32, this->currentFrame, this->color);
}