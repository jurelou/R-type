#ifndef             MONSTER_HPP__
# define            MONSTER_HPP__

#include            "IClientEntity.hpp"
#include            "SFMLSprite.hpp"

class               Monster : public IClientEntity {
  public:
    Monster(int id, const Vertex& pos);
    ~Monster();
    int             getId();
    void            setPosition(const Vertex& pos, float initTime);
    void            draw(IGraphicalEngine *graphicalEngine, float elapsedTime);
    float           getInternalTime();
  private:
    Vertex          pos;
    int             id;
    sf::IntRect     currentFrame;
    float           internalTime;
    float           initTime;
    bool            direction;
};

#endif              /* !MONSTER_HPP__ */