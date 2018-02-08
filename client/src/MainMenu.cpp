#include        <iostream>
#include        "MainMenu.hpp"

MainMenu::MainMenu(IGraphicalEngine *graphicalEngine) {
  this->graphicalEngine = graphicalEngine;
  this->nextState = IMenuScene::MenuState::NOTHING;
  this->selectedItem = 0;
  this->menuText[0] = new SFMLMenuText(resourceManager->getMenuFont(), "CREATE GAME", sf::Color::Red, this->graphicalEngine->getWindow().getSize().x * 0.35, this->graphicalEngine->getWindow().getSize().y * 0.6);
  this->menuText[1] = new SFMLMenuText(resourceManager->getMenuFont(), "JOIN GAME", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.35, this->graphicalEngine->getWindow().getSize().y * 0.7);
  // this->menuText[2] = new SFMLMenuText(resourceManager->getMenuFont(), "SELECT SKIN", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.35, this->graphicalEngine->getWindow().getSize().y * 0.8);
  this->menuAssociation[0] = MenuState::CREATE_GAME;
  this->menuAssociation[1] = MenuState::JOIN_GAME;
  // this->menuAssociation[2] = MenuState::EDIT_SKINS;
}

MainMenu::~MainMenu() {
}

void                        MainMenu::eventLeft() {
  this->menuText[this->selectedItem]->setColor(sf::Color::White);
  this->selectedItem -= 1;
  if (this->selectedItem < 0) {
    this->selectedItem = MAX_MAIN_MENU_ITEM - 1;
  }
  this->menuText[this->selectedItem]->setColor(sf::Color::Red);
}
void                        MainMenu::eventRight() {
  this->menuText[this->selectedItem]->setColor(sf::Color::White);
  this->selectedItem += 1;
  if (this->selectedItem >= MAX_MAIN_MENU_ITEM) {
    this->selectedItem = 0;
  }
  this->menuText[this->selectedItem]->setColor(sf::Color::Red);
}
void                        MainMenu::eventEnter() {
  this->nextState = this->menuAssociation[this->selectedItem];
}

void                        MainMenu::eventUp() {
  this->menuText[this->selectedItem]->setColor(sf::Color::White);
  this->selectedItem -= 1;
  if (this->selectedItem < 0) {
    this->selectedItem = MAX_MAIN_MENU_ITEM - 1;
  }
  this->menuText[this->selectedItem]->setColor(sf::Color::Red);
}
void                        MainMenu::eventDown() {
  this->menuText[this->selectedItem]->setColor(sf::Color::White);
  this->selectedItem += 1;
  if (this->selectedItem >= MAX_MAIN_MENU_ITEM) {
    this->selectedItem = 0;
  }
  this->menuText[this->selectedItem]->setColor(sf::Color::Red);
}

void                        MainMenu::eventAction() {
  this->nextState = this->menuAssociation[this->selectedItem];
}

void                        MainMenu::updateScene(float elapsedTime) {
  this->graphicalEngine->placeSpriteAtPos(resourceManager->getMenuGameLogo(), this->graphicalEngine->getWindow().getSize().x / 2 - 350 , this->graphicalEngine->getWindow().getSize().y / 5);
  for (int i = 0; i < MAX_MAIN_MENU_ITEM; i++) {
    this->graphicalEngine->drawToWindow(this->menuText[i]->getText());
  }
}

IMenuScene::MenuState       MainMenu::getNextState() {
  return this->nextState;
}

void                        MainMenu::resetState() {
  this->nextState = MenuState::NOTHING;
}