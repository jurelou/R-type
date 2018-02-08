#ifndef         LOBBYMENU_HPP__
# define        LOBBYMENU_HPP__

#include        <SFML/Graphics.hpp>
#include        "SFMLMenuText.hpp"
#include        "IMenuScene.hpp"
#include        "Client.hpp"

#define         MAX_LOBBY_MENU_ITEM 2

class           LobbyMenu : public IMenuScene {
  public:
    LobbyMenu(IGraphicalEngine *graphicalEngine, Client *client);
    ~LobbyMenu();
    void                    eventUp();
    void                    eventDown();
    void                    eventLeft();
    void                    eventRight();
    void                    eventEnter();
    void                    eventAction();
    void                    updateScene(float elapsedTime);
    IMenuScene::MenuState   getNextState();
    void                    resetState();
    void                    updatePlayerList();
    IScene::SceneState          getNextScene() { return SceneState::NOTHING; };
    void                        resetScene() {};
  private:
    IGraphicalEngine        *graphicalEngine;
    Client                  *client;
    SFMLMenuText            *menuTitle;
    SFMLMenuText            *players;
    IMenuScene::MenuState           nextState;
    std::map<int, SFMLMenuText *>   menuText;
    std::vector<std::string>    playersOfLobby;
    int                         selectedItem;
};

#endif          /* !LOBBYMENU_HPP__ */