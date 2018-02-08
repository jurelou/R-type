#ifndef         SFMLMENUTEXT_HPP__
# define        SFMLMENUTEXT_HPP__

#include        <SFML/Graphics.hpp>
#include        "IFont.hpp"

class           SFMLMenuText {
  public:
    SFMLMenuText(IFont& font, const std::string& string, const sf::Color& color, int x, int y);
    SFMLMenuText(IFont& font, const std::string& string, const sf::Color& color, int x, int y, int size);
    ~SFMLMenuText();
    void        setFont(const sf::Font& font);
    void        setString(const std::string& string);
    void        setColor(const sf::Color& color);
    void        setPosition(int x, int y);
    sf::Text&   getText();
  private:
    sf::Text    text;
};

#endif          /* !SFMLMENUTEXT_HPP__ */