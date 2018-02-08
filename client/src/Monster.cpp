#include        <iostream>
#include        "Monster.hpp"

Monster::Monster(int id, const Vertex& pos) : currentFrame(0, 0, 64, 64) {
  this->id = id;
  this->pos = pos;
}

Monster::~Monster()
{}

int             Monster::getId() {
  return this->id;
}

float           Monster::getInternalTime() {
  return this->initTime;
}

void            Monster::setPosition(const Vertex& pos, float initTime) {
  this->pos = pos;
  this->initTime = initTime;
}

void            Monster::draw(IGraphicalEngine *graphicalEngine, float elaspedTime) {
  this->internalTime += elaspedTime;
  if (this->internalTime >= 150) {
    if (currentFrame.left >= 64 * 7) {
      currentFrame.left = 0;
    } else {
      currentFrame.left += 64;
    }
    this->internalTime = 0;
  }
  graphicalEngine->placeSpriteAtPos(resourceManager->getMonsterSprite(), pos.x, pos.y, 16, 16, currentFrame);
}