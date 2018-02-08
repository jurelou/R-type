#ifndef           FACTORY_HPP__
# define          FACTORY_HPP__

#include          "IClientEntity.hpp"
#include          "Protocol.hpp"
#include          "Vertex.hpp"

class             Factory {
  public:
    Factory();
    ~Factory();
    IClientEntity *getNewInstance(Protocol::EntityType type, int id, const Vertex& pos);
  private:
    std::map<int, sf::Color *>  colorPlayer;
    int           nbPlayer;
};

#endif            /* !FACTORY_HPP__ */