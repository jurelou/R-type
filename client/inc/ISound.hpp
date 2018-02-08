#ifndef         ISOUND_HPP__
# define        ISOUND_HPP__

#include        <SFML/Audio.hpp>

class           ISound {
  public:
    virtual     void setSound(sf::SoundBuffer &sound) = 0;
    virtual     sf::SoundBuffer&  getSound() = 0;
};

#endif          /* !ISOUND_HPP__ */