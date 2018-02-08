#include        <iostream>
#include        "SFMLMenuEvent.hpp"

SFMLMenuEvent::SFMLMenuEvent() {
  this->currentEvent = Event::NO_EVENT;
}

SFMLMenuEvent::~SFMLMenuEvent()
{}

void            SFMLMenuEvent::pollEvent(sf::RenderWindow& window) {
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
}

void            SFMLMenuEvent::setKeyPressed(int keycode) {
  switch (keycode) {
    case sf::Keyboard::Up:
      this->currentEvent = Event::UP;
      return;
    case sf::Keyboard::Down:
      this->currentEvent = Event::DOWN;
      return;
    case sf::Keyboard::Left:
      this->currentEvent = Event::LEFT;
      return;
    case sf::Keyboard::Right:
      this->currentEvent = Event::RIGHT;
      return;
    case sf::Keyboard::Space:
      this->currentEvent = Event::ACTION;
      return;
    case sf::Keyboard::Return:
      this->currentEvent = Event::ENTER;
      return;
    default:
      return;
  }
}

void            SFMLMenuEvent::callEvent() {
  if (this->eventMap.find(this->currentEvent) != this->eventMap.end()) {
    this->eventMap[this->currentEvent]();
  }
  this->currentEvent = Event::NO_EVENT;
}

void            SFMLMenuEvent::setEvent(Event type, eventCallback callback) {
  this->eventMap[type] = callback;
}
