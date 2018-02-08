#ifndef         IGRAPHICAL_ENGINE_HPP__
# define        IGRAPHICAL_ENGINE_HPP__

#include        <SFML/Graphics.hpp>
#include        "ISprite.hpp"

class           IGraphicalEngine {
  public:
    virtual     void  placeSpriteAtPos(ISprite &sprite, float x, float y) = 0;
    virtual     void  placeSpriteAtPos(ISprite &sprite, float x, float y, float ox, float oy) = 0;
    virtual     void  placeSpriteAtPos(ISprite &sprite, float x, float y, float ox, float oy, sf::IntRect& currentFrame) = 0;
    virtual     void  placeSpriteAtPos(ISprite &sprite, float x, float y, float ox, float oy, sf::IntRect& currentFrame, sf::Color& color) = 0;
    virtual     void  drawBackground(ISprite &sprite) = 0;
    virtual     sf::RenderWindow& getWindow() = 0;
    virtual     void  clearWindow() = 0;
    virtual     void  renderWindow() = 0;
    virtual     void  closeWindow() = 0;
    virtual     bool  getWindowState() = 0;
    virtual     void  drawToWindow(const sf::Drawable& drawable) = 0;
};

#endif          /* !IGRAPHICAL_ENGINE_HPP__ */