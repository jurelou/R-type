#include      <iostream>
#include      "MovableBackground.hpp"

MovableBackground::MovableBackground(const std::string& name, float x, float y) {
  this->bgSpeed = 0.05;
  this->bgTex.loadFromFile(name);
  this->bgTex.setSmooth(true);
  this->bgTex.setRepeated(true);
  this->bgSprite.setTexture(this->bgTex);
  this->bgSprite.setPosition(0, 0);
  this->bgY = 0;
  this->x = x;
  this->y = y;
  this->bgSprite.setTextureRect(sf::IntRect(this->bgY, 0, x, y));
}

MovableBackground::~MovableBackground() {}

void          MovableBackground::update(sf::RenderWindow &window, float elapsedTime) {
  this->bgY += this->bgSpeed * elapsedTime;
  this->bgSprite.setTextureRect(sf::IntRect(this->bgY, 0, x, y));
  window.draw(this->bgSprite);
}

void          MovableBackground::setScreenSize(float x, float y) {
  this->x = x;
  this->y = y;
}
