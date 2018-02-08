#ifndef                 GAMESCENE_HPP__
# define                GAMESCENE_HPP__

#include                "IScene.hpp"
#include                "ISoundEngine.hpp"
#include                "Client.hpp"
#include                "MovableBackground.hpp"
#include                "EntityManager.hpp"
#include                "Protocol.hpp"

class                   GameScene : public IScene {
  public:
    GameScene(IGraphicalEngine *graphicalEngine, ISoundEngine *soundEngine, Client *client);
    ~GameScene();
    void                eventUp();
    void                eventDown();
    void                eventLeft();
    void                eventRight();
    void                eventEnter();
    void                eventAction();
    void                updateScene(float elapsedTime);
    IScene::SceneState  getNextScene();
    void                resetScene();
  private:
    IGraphicalEngine    *graphicalEngine;
    ISoundEngine        *soundEngine;
    Client              *client;
    EntityManager       *entityManager;
    MovableBackground   background;
    IScene::SceneState  nextScene;
};

#endif                  /* !GAMESCENE_HPP__ */