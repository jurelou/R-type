#include        "Loading.hpp"

Loading::Loading()
{}

Loading::~Loading()
{}

void            Loading::setText(IFont& font, int x, int y) {
  sf::FloatRect textRect;

  this->text.setFont(font.getFont());
  this->text.setString("LOADING ...");
  this->text.setCharacterSize(50);
  textRect = this->text.getLocalBounds();
  this->text.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
  this->text.setPosition(x / 2, y / 2);
}

void            Loading::setSizes(int x, int y) {
  this->rectangle.setSize(sf::Vector2f(x * 0.8, y * 0.8));
  this->rectangle.setOrigin(x * 0.4, y * 0.4);
  this->rectangle.setPosition(x / 2, y / 2);
  this->rectangle.setFillColor(sf::Color(83, 83, 83, 220));
}

void            Loading::setLoading(IGraphicalEngine *graphicalEngine) {
  graphicalEngine->drawToWindow(rectangle);
  graphicalEngine->drawToWindow(text);
  graphicalEngine->renderWindow();
}