#ifndef               GAME_HPP__
# define              GAME_HPP__

#include              <map>
#include              <SFML/Graphics.hpp>
#include              "IGraphicalEngine.hpp"
#include              "ISoundEngine.hpp"
#include              "ISprite.hpp"
#include              "IEvent.hpp"
#include              "IScene.hpp"
#include              "Client.hpp"

class                 Game {
  public:
    Game();
    ~Game();
    void              loop();
    void              updateSceneInput();
  private:
    IGraphicalEngine  *graphics;
    ISoundEngine      *sound;
    std::map<IScene::SceneState, IScene *>            scene;
    std::map<IScene::SceneState, IEvent *>            event;
    Client            *client;
    IScene::SceneState  currentScene;
};

#endif                /* !GAME_HPP__ */