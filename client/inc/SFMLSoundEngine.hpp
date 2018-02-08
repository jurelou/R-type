#ifndef         SFMLSOUNDENGINE_HPP__
# define        SFMLSOUNDENGINE_HPP__

#include        "ISoundEngine.hpp"

class           SFMLSoundEngine : public ISoundEngine {
  public:
    SFMLSoundEngine();
    ~SFMLSoundEngine();
    void        playSound(ISound &sound);
    void        playMusic(ISound &music);
  private:
    sf::Sound   currentSound;
    sf::Sound   currentMusic;

};

#endif          /* !SFMLSOUNDENGINE_HPP__ */