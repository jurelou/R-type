#ifndef         IFONT_HPP__
# define        IFONT_HPP__

#include        <SFML/Graphics.hpp>

class           IFont {
  public:
    virtual     void            setFont(sf::Font &font) = 0;
    virtual     sf::Font&       getFont() = 0;
};

#endif          /* !IFONT_HP__ */