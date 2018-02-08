#include        <iostream>
#include        "SFMLSoundEngine.hpp"

SFMLSoundEngine::SFMLSoundEngine() {
  this->currentSound.setVolume(70);
}

SFMLSoundEngine::~SFMLSoundEngine()
{}

void            SFMLSoundEngine::playSound(ISound &sound) {
  this->currentSound.setBuffer(sound.getSound());
  this->currentSound.play();
}

void            SFMLSoundEngine::playMusic(ISound &music) {
  this->currentMusic.setBuffer(music.getSound());
  this->currentMusic.play();
  this->currentMusic.setLoop(true);
}