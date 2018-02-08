#ifndef         ENTITYMANAGER_HPP__
# define        ENTITYMANAGER_HPP__

#include        <map>
#include        "Protocol.hpp"
#include        "Factory.hpp"
#include        "Vertex.hpp"
#include        "IClientEntity.hpp"

class           EntityManager {
  public:
    EntityManager();
    ~EntityManager();
    void        setNewEntity(Protocol::EntityType type, int id, const Vertex &pos);
    void        moveEntity(Protocol::EntityType type, int id, const Vertex &pos);
    void        deleteEntity(int id);
    void        updateEntities(IGraphicalEngine *graphicalEngine, float elapsedTime);
    void        deleteInactiveEntity();
    bool        shouldIGoToMenu();
  private:
    Factory     entityFactory;
    std::vector<IClientEntity *>  entityList;
    float       currentTime;
    bool        hasEntity;
    bool        shouldGoToMenu;
};

#endif          /* !ENTITYMANAGER_HPP__ */