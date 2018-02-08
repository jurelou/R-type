#ifndef                 LOADING_HPP__
# define                LOADING_HPP__

#include                <SFML/Graphics.hpp>
#include                "IGraphicalEngine.hpp"
#include                "IFont.hpp"

class                   Loading {
  public:
    Loading();
    ~Loading();
    void                setLoading(IGraphicalEngine *engine);
    void                setText(IFont& font, int x, int y);
    void                setSizes(int x, int y);
  public:
    sf::Text            text;
    sf::RectangleShape  rectangle;
};

#endif                  /*! LOADING_HPP__ */