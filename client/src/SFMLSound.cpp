#include        "SFMLSound.hpp"

SFMLSound::SFMLSound(const std::string& name) {
  this->sound.loadFromFile(name);
}

SFMLSound::~SFMLSound()
{}

sf::SoundBuffer&  SFMLSound::getSound() {
  return this->sound;
}

void              SFMLSound::setSound(sf::SoundBuffer &sound) {
  this->sound = sound;
}
