#ifndef           SFMLGAMEEVENT_HPP__
# define          SFMLGAMEEVENT_HPP__

#include          <functional>
#include          "IEvent.hpp"

class             SFMLGameEvent : public IEvent {
  public:
    SFMLGameEvent();
    ~SFMLGameEvent();
    void                            pollEvent(sf::RenderWindow& window);
    void                            setEvent(Event type, eventCallback callback);
    void                            callEvent();
    void                            setKeyPressed(int keycode);
    void                            getKeyDown();
  private:
    Event                           currentEvent;
    std::map<Event, eventCallback>  eventMap;
};

#endif            /* !SFMLGAMEEVENT_HPP__ */