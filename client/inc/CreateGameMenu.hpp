#ifndef       CREATE_GAME_MENU_HPP__
# define      CREATE_GAME_MENU_HPP__

#include      <SFML/Graphics.hpp>
#include      "SFMLMenuText.hpp"
#include      "IMenuScene.hpp"
#include      "Client.hpp"

#define       MAX_CREATE_GAME_MENU_ITEM 4
#define       MAX_DIFFICULTY 4

class         CreateGameMenu : public IMenuScene {
  public:
    CreateGameMenu(IGraphicalEngine *graphicalEngine, Client *client);
    ~CreateGameMenu();
    void                        eventUp();
    void                        eventDown();
    void                        eventLeft();
    void                        eventRight();
    void                        eventEnter();
    void                        eventAction();
    void                        getUserInput();
    void                        updateScene(float elapsedTime);
    IMenuScene::MenuState       getNextState();
    void                        resetState();
    IScene::SceneState          getNextScene() { return SceneState::NOTHING; };
    void                        resetScene() {};
  private:
    IGraphicalEngine            *graphicalEngine;
    Client                      *client;
    IMenuScene::MenuState       nextState;
    SFMLMenuText                *menuTitle;
    std::map<int, SFMLMenuText *>   menuText;
    std::map<int, MenuState>    menuAssociation;
    std::map<int, Protocol::MapLevel>     difficultyAssociation;
    std::map<int, SFMLMenuText *>   menuDifficultySelection;
    std::string                 roomName;
    int                         selectedItem;
    int                         selectedDifficulty;

};

#endif        /* !CREATE_GAME_MENU_HPP__ */