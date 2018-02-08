#ifndef         SFMLFONT_HPP__
# define        SFMLFONT_HPP__

#include        <SFML/Graphics.hpp>
#include        "IFont.hpp"

class           SFMLFont : public IFont {
  public:
    SFMLFont(const std::string& fontName);
    ~SFMLFont();
    sf::Font&   getFont();
    void        setFont(sf::Font& font);
  private:
    sf::Font    font;
};

#endif          /* !SFMLFONT_HPP__ */