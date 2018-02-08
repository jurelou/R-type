#ifndef         ISPRITE_HPP_
# define        ISPRITE_HPP_

#include        <SFML/Graphics.hpp>

class           ISprite {
  public:
    virtual     void            setSprite(sf::Texture &sprite) = 0;
    virtual     sf::Texture&    getSprite() = 0;
};

#endif          /* !ISPRITE_HPP_ */
