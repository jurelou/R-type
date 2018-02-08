#ifndef               SFMLRESOURCEMANAGER_HPP__
# define              SFMLRESOURCEMANAGER_HPP__

#include              <SFML/Graphics.hpp>
#include              "IResourceManager.hpp"
#include              "SFMLSound.hpp"
#include              "SFMLSprite.hpp"
#include              "SFMLFont.hpp"

class                 SFMLResourceManager : public IResourceManager {
  public:
    SFMLResourceManager();
    ~SFMLResourceManager();
    ISound&           getMenuMusic();
    ISound&           getMenuSoundEffect();
    ISound&           getGameMusic();
    ISprite&          getMenuBackground();
    ISprite&          getMenuGameLogo();
    ISprite&          getMonsterSprite();
    ISprite&          getBulletSprite();
    ISprite&          getPlayerSprite();
    IFont&            getMenuFont();
  private:
    SFMLSound         menuMusic;
    SFMLSound         menuSoundEffect;
    SFMLSound         gameMusic;
    SFMLSprite        menuBackground;
    SFMLSprite        menuGameLogo;
    SFMLSprite        monsterSprite;
    SFMLSprite        bulletSprite;
    SFMLSprite        playerSprite;
    SFMLFont          menuFont;
};

#endif                /* !SFMLRESOURCEMANAGER_HPP__ */