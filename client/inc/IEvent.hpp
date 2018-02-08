#ifndef         EVENT_HPP__
# define        EVENT_HPP__

#include        <functional>
#include        <SFML/Graphics.hpp>

enum            Event {
  UP = 0,
  DOWN,
  LEFT,
  RIGHT,
  ENTER,
  EXIT,
  ACTION,
  NO_EVENT,
};

typedef                             std::function<void ()> eventCallback;

class           IEvent {
  public:
    virtual     void pollEvent(sf::RenderWindow& window) = 0;
    virtual     void setEvent(Event type, eventCallback callback) = 0;
    virtual     void callEvent() = 0;
};

#endif          /* !EVENT_HPP__ */