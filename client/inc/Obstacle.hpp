#ifndef         OBSTACLE_HPP__
# define        OBSTACLE_HPP__

#include        "IClientEntity.hpp"

class           Obstacle : public IClientEntity {
  public:
    Obstacle(int id, const Vertex& pos);
    ~Obstacle();
    int         getId();
    void        draw(IGraphicalEngine *graphicalEngine, float elapsedTime);
    void        setPosition(const Vertex& pos, float initTime);
    float       getInternalTime();
  private:
    Vertex      pos;
    int         id;
    sf::RectangleShape rectangle;
    float       initTime;
};

#endif          /* !OBSTACLE_HPP__ */