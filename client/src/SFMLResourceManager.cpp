#include          <iostream>
#include          "SFMLResourceManager.hpp"

SFMLResourceManager::SFMLResourceManager()
  : menuMusic("./assets/menu-music.wav"), menuSoundEffect("./assets/menu-sound-effect.wav"),
    gameMusic("./assets/game-music.wav"), menuBackground("./assets/menu-background.jpg"),
    menuGameLogo("./assets/logo.png"),    menuFont("./assets/menu-font.ttf"),
    monsterSprite("./assets/monster.png"), bulletSprite("./assets/bullet.png"),
    playerSprite("./assets/player.png") {
  std::cout << "construction" << std::endl;
}

SFMLResourceManager::~SFMLResourceManager()
{}

ISound&           SFMLResourceManager::getMenuMusic() {
  return this->menuMusic;
}

ISound&           SFMLResourceManager::getMenuSoundEffect() {
  return this->menuSoundEffect;
}

ISound&           SFMLResourceManager::getGameMusic() {
  return this->gameMusic;
}

ISprite&          SFMLResourceManager::getMenuBackground() {
  return this->menuBackground;
}

ISprite&          SFMLResourceManager::getMonsterSprite() {
  return this->monsterSprite;
}

ISprite&          SFMLResourceManager::getBulletSprite() {
  return this->bulletSprite;
}

ISprite&          SFMLResourceManager::getPlayerSprite() {
  return this->playerSprite;
}

ISprite&          SFMLResourceManager::getMenuGameLogo() {
  return this->menuGameLogo;
}

IFont&            SFMLResourceManager::getMenuFont() {
  return this->menuFont;
}