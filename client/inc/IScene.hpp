#ifndef         ISCENE_HPP__
# define        ISCENE_HPP__

#include        "IGraphicalEngine.hpp"
#include        "IResourceManager.hpp"

extern          IResourceManager   *resourceManager;

class           IScene {
  public:
    enum SceneState {
      MENU,
      GAME,
      NOTHING,
    };
    virtual     void eventUp() = 0;
    virtual     void eventDown() = 0;
    virtual     void eventLeft() = 0;
    virtual     void eventRight() = 0;
    virtual     void eventEnter() = 0;
    virtual     void eventAction() = 0;
    virtual     void updateScene(float elapsedTime) = 0;
    virtual     IScene::SceneState getNextScene() = 0;
    virtual     void resetScene() = 0;
};

#endif          /* !ISCENE_HPP__ */