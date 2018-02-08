#ifndef                             SFMLMENUEVENT_HPP__
# define                            SFMLMENUEVENT_HPP__

#include                            <functional>
#include                            "IEvent.hpp"

class                               SFMLMenuEvent : public IEvent {
  public:
    SFMLMenuEvent();
    ~SFMLMenuEvent();
    void                            pollEvent(sf::RenderWindow& window);
    void                            setEvent(Event type, eventCallback callback);
    void                            callEvent();
    void                            setKeyPressed(int keycode);
  private:
    Event                               currentEvent;
    std::map<Event, eventCallback>      eventMap;
};

#endif          /* !SFMLMENUEVENT_HPP__ */