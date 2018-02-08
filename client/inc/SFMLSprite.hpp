#ifndef             SFMLSPRITE_HPP__
# define            SFMLSPRITE_HPP__

#include            <SFML/Graphics.hpp>
#include            "ISprite.hpp"

class               SFMLSprite : public ISprite {
  public:
    SFMLSprite(const std::string& spritename);
    ~SFMLSprite();
    sf::Texture&    getSprite();
    void            setSprite(sf::Texture &sprite);
  private:
    sf::Texture     texture;
};

#endif              /* !SFMLSPRITE_HPP__ */