#include        "SFMLMenuText.hpp"

SFMLMenuText::SFMLMenuText(IFont& font, const std::string& string, const sf::Color& color, int x, int y) {
  this->text.setFont(font.getFont());
  this->text.setString(string);
  this->text.setColor(color);
  this->text.setPosition(x, y);
}

SFMLMenuText::SFMLMenuText(IFont& font, const std::string& string, const sf::Color& color, int x, int y, int size) {
  this->text.setFont(font.getFont());
  this->text.setString(string);
  this->text.setColor(color);
  this->text.setPosition(x, y);
  this->text.setCharacterSize(size);
}

SFMLMenuText::~SFMLMenuText()
{}

void            SFMLMenuText::setFont(const sf::Font& font) {
  this->text.setFont(font);
}

void            SFMLMenuText::setColor(const sf::Color& color) {
  this->text.setColor(color);
}

void            SFMLMenuText::setString(const std::string& string) {
  this->text.setString(string);
}

void            SFMLMenuText::setPosition(int x, int y) {
  this->text.setPosition(x, y);
}

sf::Text&       SFMLMenuText::getText() {
  return this->text;
}