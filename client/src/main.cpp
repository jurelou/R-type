#include    "IResourceManager.hpp"
#include    "SFMLResourceManager.hpp"
#include    "Game.hpp"

IResourceManager   *resourceManager = new SFMLResourceManager();

int         main(int ac, char *av[]) {
  Game      game;

  game.loop();
  return (0);
}