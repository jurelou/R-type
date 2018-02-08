#ifndef       JOIN_GAME_MENU_HPP__
# define      JOIN_GAME_MENU_HPP__

#include      <SFML/Graphics.hpp>
#include      "SFMLMenuText.hpp"
#include      "IMenuScene.hpp"
#include      "Loading.hpp"
#include      "Client.hpp"

#define       MAX_JOIN_GAME_MENU_ITEM 2

class         JoinGameMenu : public IMenuScene {
  public:
    JoinGameMenu(IGraphicalEngine *graphicalEngine, Client *client);
    ~JoinGameMenu();
    void                        eventUp();
    void                        eventDown();
    void                        eventLeft();
    void                        eventRight();
    void                        eventEnter();
    void                        eventAction();
    void                        updateGameList();
    void                        updateScene(float elapsedTime);
    IMenuScene::MenuState       getNextState();
    void                        resetState();
    IScene::SceneState          getNextScene() { return SceneState::NOTHING; };
    void                        resetScene() {};
  private:
    IGraphicalEngine            *graphicalEngine;
    Client                      *client;
    IMenuScene::MenuState       nextState;
    Loading                     loadingScreen;
    SFMLMenuText                *menuTitle;
    SFMLMenuText                *list;
    std::map<int, std::string>  gameList;
    std::map<int, SFMLMenuText *> menuText;
    std::map<int, MenuState>    menuAssociation;
    int                         selectedItem;
    int                         totalItem;

};

#endif        /* !JOIN_GAME_MENU_HPP__ */