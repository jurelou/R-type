#ifndef         ISOUNDENGINE_HPP__
# define        ISOUNDENGINE_HPP__

#include        "ISound.hpp"

class           ISoundEngine {
  public:
    virtual     void playSound(ISound &sound) = 0;
    virtual     void playMusic(ISound &music) = 0;
};

#endif          /* ISOUNDENGINE_HPP__ */