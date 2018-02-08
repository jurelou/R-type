#ifndef           MOVABLEBACKGROUND_HPP__
# define          MOVABLEBACKGROUND_HPP__

#include          <SFML/Graphics.hpp>

class             MovableBackground {
  public:
    MovableBackground(const std::string& name, float x, float y);
    ~MovableBackground();
    void          update(sf::RenderWindow &window, float elapsedTime);
    void          setScreenSize(float x, float y);
  private:
    float               bgSpeed;
    float               bgY;
    sf::Texture         bgTex;
    sf::Sprite          bgSprite;
    float               x;
    float               y;
};

#endif            /* !MOVABLEBACKGROUND_HPP__ */