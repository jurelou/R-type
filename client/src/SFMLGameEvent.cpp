#include        <iostream>
#include        "SFMLGameEvent.hpp"

SFMLGameEvent::SFMLGameEvent() {
  this->currentEvent = Event::NO_EVENT;
}

SFMLGameEvent::~SFMLGameEvent()
{}

void            SFMLGameEvent::pollEvent(sf::RenderWindow& window) {
  sf::Event     event;

  while (window.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed:
        this->currentEvent = Event::EXIT;
        return;
      case sf::Event::KeyPressed:
        this->setKeyPressed(event.key.code);
        return;
      default:
        this->currentEvent = Event::NO_EVENT;
        return;
    }
  }
  this->getKeyDown();
}

void            SFMLGameEvent::setKeyPressed(int keycode) {
  if (keycode == sf::Keyboard::Space) {
    this->currentEvent = Event::ACTION;
  }
}

void            SFMLGameEvent::getKeyDown() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { 
    this->currentEvent = Event::LEFT; 
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { 
    this->currentEvent = Event::RIGHT; 
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { 
    this->currentEvent = Event::UP; 
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { 
    this->currentEvent = Event::DOWN; 
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) { 
    this->currentEvent = Event::ENTER;
  }
}

void            SFMLGameEvent::callEvent() {
  if (this->eventMap.find(this->currentEvent) != this->eventMap.end()) {
    this->eventMap[this->currentEvent]();
  }
  this->currentEvent = Event::NO_EVENT;
}

void            SFMLGameEvent::setEvent(Event type, eventCallback callback) {
  this->eventMap[type] = callback;
}