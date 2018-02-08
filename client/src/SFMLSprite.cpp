#include        <iostream>
#include        "SFMLSprite.hpp"

SFMLSprite::SFMLSprite(const std::string& spriteName)
{
  this->texture.loadFromFile(spriteName);
}

SFMLSprite::~SFMLSprite()
{}

sf::Texture&     SFMLSprite::getSprite()
{
  return this->texture;
}

void            SFMLSprite::setSprite(sf::Texture &sprite)
{
  this->texture = sprite;
}
