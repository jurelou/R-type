#ifndef                         MAINMENU_HPP__
# define                        MAINMENU_HPP__

#include                        <SFML/Graphics.hpp>
#include                        "SFMLMenuText.hpp"
#include                        "IMenuScene.hpp"
#include                        "SFMLSprite.hpp"

#define                         MAX_MAIN_MENU_ITEM 2

class                           MainMenu : public IMenuScene {
  public:
    MainMenu(IGraphicalEngine *graphicalEngine);
    ~MainMenu();
    void                        eventUp();
    void                        eventDown();
    void                        eventLeft();
    void                        eventRight();
    void                        eventEnter();
    void                        eventAction();
    void                        updateScene(float elapsedTime);
    IMenuScene::MenuState       getNextState();
    void                        resetState();
    IScene::SceneState          getNextScene() { return SceneState::NOTHING; };
    void                        resetScene() {};
  private:
    IGraphicalEngine            *graphicalEngine;
    IMenuScene::MenuState       nextState;
    std::map<int, SFMLMenuText *>   menuText;
    std::map<int, MenuState>    menuAssociation;
    int                         selectedItem;
};

#endif                          /* !MAINMENU_HPP_ */