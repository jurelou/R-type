// #include          "EditSkinsMenu.hpp"

// EditSkinsMenu::EditSkinsMenu(IGraphicalEngine *graphicalEngine) {
//   this->graphicalEngine = graphicalEngine;
//   this->nextState = IMenuScene::MenuState::VOID;
//   this->selectedItem = 0;
//   this->menuTitle.setFont(resourceManager->getMenuFont());
//   this->menuTitle.setString("EDIT SKINS");
//   this->menuTitle.setCharacterSize(45);
//   this->menuTitle.setPosition(this->graphicalEngine->getWindow().getSize().x / 4, this->graphicalEngine->getWindow().getSize().y / 4);
//   this->menuText[0].setFont(resourceManager->getMenuFont());
//   this->menuText[0].setString("RETURN");
//   this->menuText[0].setColor(sf::Color::Red);
//   this->menuText[0].setPosition(this->graphicalEngine->getWindow().getSize().x / 4, this->graphicalEngine->getWindow().getSize().y / 2);
//   this->menuAssociation[0] = MenuState::MAIN_MENU;
// }

// EditSkinsMenu::~EditSkinsMenu()
// {}

// void                        EditSkinsMenu::eventLeft() { /* NO NEED TO BE IMPLEMENTED */ }
// void                        EditSkinsMenu::eventRight() { /* NO NEED TO BE IMPLEMENTED */ }
// void                        EditSkinsMenu::eventEnter() { /* NO NEED TO BE IMPLEMENTED */ }

// void                        EditSkinsMenu::eventUp() {
//   this->menuText[this->selectedItem].setColor(sf::Color::White);
//   this->selectedItem -= 1;
//   if (this->selectedItem < 0) {
//     this->selectedItem = MAX_EDIT_SKINS_MENU_ITEM - 1;
//   }
//   this->menuText[this->selectedItem].setColor(sf::Color::Red);
// }
// void                        EditSkinsMenu::eventDown() {
//   this->menuText[this->selectedItem].setColor(sf::Color::White);
//   this->selectedItem += 1;
//   if (this->selectedItem >= MAX_EDIT_SKINS_MENU_ITEM) {
//     this->selectedItem = 0;
//   }
//   this->menuText[this->selectedItem].setColor(sf::Color::Red);
// }

// void                        EditSkinsMenu::eventAction() {
//   this->nextState = this->menuAssociation[this->selectedItem];
// }

// void                        EditSkinsMenu::updateScene(float elapsedTime) {
//   this->graphicalEngine->drawToWindow(this->menuTitle);
//   for (int i = 0; i < MAX_EDIT_SKINS_MENU_ITEM; i++) {
//     this->graphicalEngine->drawToWindow(this->menuText[i]);
//   }
// }

// IMenuScene::MenuState       EditSkinsMenu::getNextState() {
//   return this->nextState;
// }

// void                        EditSkinsMenu::resetState() {
//   this->nextState = MenuState::VOID;
// }