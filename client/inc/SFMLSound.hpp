#ifndef         SFMLSOUND_HPP__
# define        SFMLSOUND_HPP__

#include        "ISound.hpp"

class           SFMLSound : public ISound {
  public:
    SFMLSound(const std::string& name);
    ~SFMLSound();
    sf::SoundBuffer&  getSound();
    void              setSound(sf::SoundBuffer &sound);
  private:
    sf::SoundBuffer   sound;
};

#endif          /* !SFMLSOUND_HPP__ */