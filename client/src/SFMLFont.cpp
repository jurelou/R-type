#include        "SFMLFont.hpp"

SFMLFont::SFMLFont(const std::string& fontName) {
  this->font.loadFromFile(fontName);
}

SFMLFont::~SFMLFont()
{}

sf::Font&       SFMLFont::getFont() {
  return this->font;
}

void            SFMLFont::setFont(sf::Font& font) {
  this->font = font;
}
