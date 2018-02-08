#ifndef         HUMAN_HPP__
# define        HUMAN_HPP__

#include        "IClientEntity.hpp"

class           Human : public IClientEntity {
  public:
    Human(int id, const Vertex& pos, sf::Color& color);
    ~Human();
    int         getId();
    void        draw(IGraphicalEngine *graphicalEngine, float elapsedTime);
    void        setPosition(const Vertex& pos, float initTime);
    float       getInternalTime();
  private:
    Vertex      pos;
    int         id;
    sf::IntRect currentFrame;
    float       initTime;
    sf::Color   color;
};

#endif          /* !HUMAN_HPP__ */