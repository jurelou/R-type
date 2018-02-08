#ifndef         MENUSCENE_HPP__
# define        MENUSCENE_HPP__

#include        <map>
#include        "IMenuScene.hpp"
#include        "ISoundEngine.hpp"
#include        "IScene.hpp"
#include        "MovableBackground.hpp"
#include        "SFMLSprite.hpp"
#include        "SFMLSound.hpp"
#include        "Client.hpp"

class           MenuScene : public IScene {
  public:
    MenuScene(IGraphicalEngine *graphicalEngine, ISoundEngine *soundEngine, Client *client);
    ~MenuScene();
    void        eventUp();
    void        eventDown();
    void        eventLeft();
    void        eventRight();
    void        eventEnter();
    void        eventAction();
    void        updateScene(float elapsedTime);
    IScene::SceneState  getNextScene();
    void                resetScene();
  private:
    IGraphicalEngine    *graphicalEngine;
    ISoundEngine        *soundEngine;
    Client              *client;
    std::map<IMenuScene::MenuState, IMenuScene *> menuMap;
    IMenuScene::MenuState   currentState;
    MovableBackground       background;
    IScene::SceneState      nextScene;
};

#endif                  /* !MENUSCENE_HPP__ */