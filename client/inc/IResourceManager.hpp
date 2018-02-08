#ifndef         IRESOURCEMANAGER_HPP__
# define        IRESOURCEMANAGER_HPP__

#include        "ISound.hpp"
#include        "ISprite.hpp"
#include        "IFont.hpp"

class           IResourceManager {
  public:
    virtual     ISound&    getMenuMusic() = 0;
    virtual     ISound&    getMenuSoundEffect() = 0;
    virtual     ISound&    getGameMusic() = 0;
    virtual     ISprite&   getMenuBackground() = 0;
    virtual     ISprite&   getMenuGameLogo() = 0;
    virtual     ISprite&   getMonsterSprite() = 0;
    virtual     ISprite&   getBulletSprite() = 0;
    virtual     ISprite&   getPlayerSprite() = 0;
    virtual     IFont&     getMenuFont() = 0;
};

#endif          /* !IRESOURCEMANAGER_HPP__ */