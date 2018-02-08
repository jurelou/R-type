#include        "Bullet.hpp"

Bullet::Bullet(int id, const Vertex& pos) : currentFrame(0, 0, 32, 32) {
  this->id = id;
  this->pos = pos;
}

Bullet::~Bullet()
{}

int             Bullet::getId() {
  return this->id;
}

void            Bullet::setPosition(const Vertex& pos, float initTime) {
  this->pos = pos;
  this->initTime = initTime;
}

float           Bullet::getInternalTime() {
  return this->initTime;
}

void            Bullet::draw(IGraphicalEngine *graphicalEngine, float elapsedTime) {
  this->internalTime += elapsedTime;
  if (this->internalTime >= 100) {
    if (currentFrame.left >= 32 * 7) {
      currentFrame.left = 0;
    } else {
      currentFrame.left += 32;
    }
    this->internalTime = 0;
  }
  graphicalEngine->placeSpriteAtPos(resourceManager->getBulletSprite(), pos.x, pos.y, 32, 32, currentFrame);
}