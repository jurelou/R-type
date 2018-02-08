#ifndef         LOGINMENU_HPP__
# define        LOGINMENU_HPP__

#define         MAX_LOGIN_MENU_ITEM 4

#include        <SFML/Graphics.hpp>
#include        "SFMLMenuText.hpp"
#include        "Loading.hpp"
#include        "IMenuScene.hpp"
#include        "Client.hpp"

class           LoginMenu : public IMenuScene {
  public:
    LoginMenu(IGraphicalEngine *graphicalEngine, Client *client);
    ~LoginMenu();
    void                    eventUp();
    void                    eventDown();
    void                    eventLeft();
    void                    eventRight();
    void                    eventEnter();
    void                    eventAction();
    void                    updateScene(float elapsedTime);
    IMenuScene::MenuState   getNextState();
    void                    getUserInput();
    void                    resetState();
    IScene::SceneState          getNextScene() { return SceneState::NOTHING; };
    void                        resetScene() {};
  private:
    IGraphicalEngine              *graphicalEngine;
    IMenuScene::MenuState         nextState;
    Client                        *client;
    Loading                       loadingScreen;
    std::map<int, SFMLMenuText *> menuText;
    std::map<int, MenuState>      menuAssociation;
    std::map<int, std::string>    serverCred;
    std::map<int, std::string>    baseText;
    int                           selectedItem;
};

#endif                      /* !LOGINMENU_HPP__ */