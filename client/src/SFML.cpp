#include        <iostream>
#include        "SFML.hpp"

SFML::SFML() : window(sf::VideoMode(1280, 720), "R-Type", sf::Style::Titlebar | sf::Style::Close) {
  this->window.setKeyRepeatEnabled(false);
}

SFML::~SFML()
{}

void            SFML::placeSpriteAtPos(ISprite &sprite, float x, float y) {
  sf::Sprite    sp;

  sp.setTexture(sprite.getSprite());
  sp.setPosition(x, y);
  this->window.draw(sp);
}

void            SFML::placeSpriteAtPos(ISprite &sprite, float x, float y, float ox, float oy) {
  sf::Sprite    sp;

  sp.setTexture(sprite.getSprite());
  sp.setOrigin(ox, oy);
  sp.setPosition(x, y);
  this->window.draw(sp);
}

void            SFML::placeSpriteAtPos(ISprite &sprite, float x, float y, float ox, float oy, sf::IntRect& currentFrame) {
  sf::Sprite    sp;

  sp.setTexture(sprite.getSprite());
  sp.setOrigin(ox, oy);
  sp.setTextureRect(currentFrame);
  sp.setPosition(x, y);
  this->window.draw(sp);
}

void            SFML::placeSpriteAtPos(ISprite &sprite, float x, float y, float ox, float oy, sf::IntRect& currentFrame, sf::Color& color) {
  sf::Sprite    sp;

  sp.setTexture(sprite.getSprite());
  sp.setOrigin(ox, oy);
  sp.setTextureRect(currentFrame);
  sp.setPosition(x, y);
  sp.setColor(color);
  this->window.draw(sp);
}

void            SFML::drawBackground(ISprite &sprite) {
  sf::Sprite    sp;

  sp.setTexture(sprite.getSprite());
  sp.setPosition(0, 0);
  sp.setScale(this->window.getSize().x / sp.getLocalBounds().width, this->window.getSize().y / sp.getLocalBounds().height);
  this->window.draw(sp);
}

sf::RenderWindow&   SFML::getWindow() {
  return this->window;
}

void            SFML::clearWindow() {
  this->window.clear();
}

void            SFML::renderWindow() {
  this->window.display();
}

void            SFML::closeWindow() {
  this->window.close();
}

bool            SFML::getWindowState() {
  return this->window.isOpen();
}

void            SFML::drawToWindow(const sf::Drawable& drawable) {
  this->window.draw(drawable);
}
