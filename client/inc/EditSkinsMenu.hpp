// #ifndef       EDIT_SKINS_MENU_HPP__
// # define      EDIT_SKINS_MENU_HPP__

// #include      <SFML/Graphics.hpp>
// #include      "IMenuScene.hpp"

// #define       MAX_EDIT_SKINS_MENU_ITEM 1

// class         EditSkinsMenu : public IMenuScene {
//   public:
//     EditSkinsMenu(IGraphicalEngine *graphicalEngine);
//     ~EditSkinsMenu();
//     void                        eventUp();
//     void                        eventDown();
//     void                        eventLeft();
//     void                        eventRight();
//     void                        eventEnter();
//     void                        eventAction();
//     void                        updateScene(float elapsedTime);
//     IMenuScene::MenuState       getNextState();
//     void                        resetState();
//   private:
//     IGraphicalEngine            *graphicalEngine;
//     IMenuScene::MenuState       nextState;
//     sf::Text                    menuTitle;
//     std::map<int, sf::Text>     menuText;
//     std::map<int, MenuState>    menuAssociation;
//     int                         selectedItem;

// };

// #endif        /* !EDIT_SKINS_MENU_HPP__ */