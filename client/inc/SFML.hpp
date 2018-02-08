#ifndef               SFML_HPP__
# define              SFML_HPP__

#include              <SFML/Graphics.hpp>
#include              "IGraphicalEngine.hpp"

class                 SFML : public IGraphicalEngine {
  public:
    SFML();
    ~SFML();
    void              placeSpriteAtPos(ISprite &sprite, float x, float y);
    void              placeSpriteAtPos(ISprite &sprite, float x, float y, float ox, float oy);
    void              placeSpriteAtPos(ISprite &sprite, float x, float y, float ox, float oy, sf::IntRect& currentFrame);
    void              placeSpriteAtPos(ISprite &sprite, float x, float y, float ox, float oy, sf::IntRect& currentFrame, sf::Color& color);
    sf::RenderWindow& getWindow();
    void              clearWindow();
    void              renderWindow();
    void              closeWindow();
    bool              getWindowState();
    void              drawToWindow(const sf::Drawable& drawable);
    void              drawBackground(ISprite &sprite);
  private:
    sf::RenderWindow  window;
    sf::Font          menuFont;
};

#endif                /* !SFML_HPP__ */