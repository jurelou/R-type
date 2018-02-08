#ifndef         BULLET_HPP__
# define        BULLET_HPP__

#include        "IClientEntity.hpp"

class           Bullet : public IClientEntity {
  public:
    Bullet(int id, const Vertex& pos);
    ~Bullet();
    int         getId();
    void        draw(IGraphicalEngine *graphicalEngine, float elapsedTime);
    void        setPosition(const Vertex& pos, float initTime);
    float       getInternalTime();
  private:
    Vertex      pos;
    int         id;
    sf::IntRect     currentFrame;
    float           internalTime;
    float       initTime;
};

#endif          /* !BULLET_HPP__ */