#ifndef         ICLIENTENTITY_HPP__
# define        ICLIENTENTITY_HPP__

#include        "Vertex.hpp"
#include        "IGraphicalEngine.hpp"
#include        "IResourceManager.hpp"

extern          IResourceManager   *resourceManager;

class           IClientEntity {
  public:
    virtual     void  setPosition(const Vertex& pos, float currentTime) = 0;
    virtual     int   getId() = 0;
    virtual     void  draw(IGraphicalEngine *graphicalEngine, float elapsedTime) = 0;
    virtual     float getInternalTime() = 0;
};

#endif          /* !ICLIENTENTITY_HPP__ */