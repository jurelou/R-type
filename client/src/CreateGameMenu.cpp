#include          <iostream>
#include          "CreateGameMenu.hpp"

CreateGameMenu::CreateGameMenu(IGraphicalEngine *graphicalEngine, Client *client) {
  this->graphicalEngine = graphicalEngine;
  this->client = client;
  this->nextState = IMenuScene::MenuState::NOTHING;
  this->selectedItem = 0;
  this->selectedDifficulty = 0;
  this->menuTitle = new SFMLMenuText(resourceManager->getMenuFont(), "CREATE GAME", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.3, this->graphicalEngine->getWindow().getSize().y * 0.25, 45);
  this->menuDifficultySelection[0] = new SFMLMenuText(resourceManager->getMenuFont(), "EASY", sf::Color::Red, this->graphicalEngine->getWindow().getSize().x * 0.4, this->graphicalEngine->getWindow().getSize().y * 0.6, 25);
  this->menuDifficultySelection[1] = new SFMLMenuText(resourceManager->getMenuFont(), "NORMAL", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.55, this->graphicalEngine->getWindow().getSize().y * 0.6, 25);
  this->menuDifficultySelection[2] = new SFMLMenuText(resourceManager->getMenuFont(), "HARD", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.70, this->graphicalEngine->getWindow().getSize().y * 0.6, 25);
  this->menuDifficultySelection[3] = new SFMLMenuText(resourceManager->getMenuFont(), "LEGENDARY", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.80, this->graphicalEngine->getWindow().getSize().y * 0.6, 25);
  this->menuText[0] = new SFMLMenuText(resourceManager->getMenuFont(), "ROOM NAME", sf::Color::Red, this->graphicalEngine->getWindow().getSize().x * 0.1, this->graphicalEngine->getWindow().getSize().y * 0.5);
  this->menuText[1] = new SFMLMenuText(resourceManager->getMenuFont(), "DIFFICULTY", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.1, this->graphicalEngine->getWindow().getSize().y * 0.6);
  this->menuText[2] = new SFMLMenuText(resourceManager->getMenuFont(), "LAUNCH", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.3, this->graphicalEngine->getWindow().getSize().y * 0.8);
  this->menuText[3] = new SFMLMenuText(resourceManager->getMenuFont(), "RETURN", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.6, this->graphicalEngine->getWindow().getSize().y * 0.8);
  this->menuAssociation[0] = MenuState::NOTHING;
  this->menuAssociation[1] = MenuState::NOTHING;
  this->menuAssociation[2] = MenuState::NOTHING;
  this->menuAssociation[3] = MenuState::MAIN_MENU;
  this->difficultyAssociation[0] = Protocol::MapLevel::EASY;
  this->difficultyAssociation[1] = Protocol::MapLevel::MEDIUM;
  this->difficultyAssociation[2] = Protocol::MapLevel::HARD;
  this->difficultyAssociation[3] = Protocol::MapLevel::LEGENDARY;
}

CreateGameMenu::~CreateGameMenu()
{}

void                        CreateGameMenu::eventLeft() {
  if (this->selectedItem == 1 && this->selectedDifficulty > 0) {
    this->menuDifficultySelection[this->selectedDifficulty]->setColor(sf::Color::White);
    this->selectedDifficulty -= 1;
    this->menuDifficultySelection[this->selectedDifficulty]->setColor(sf::Color::Red);
  }
}
void                        CreateGameMenu::eventRight() {
  if (this->selectedItem == 1 && this->selectedDifficulty < MAX_DIFFICULTY - 1) {
    this->menuDifficultySelection[this->selectedDifficulty]->setColor(sf::Color::White);
    this->selectedDifficulty += 1;
    this->menuDifficultySelection[this->selectedDifficulty]->setColor(sf::Color::Red);
  }
}
void                        CreateGameMenu::eventEnter() { /* NO NEED TO BE IMPLEMENTED */ }

void                        CreateGameMenu::eventUp() {
  this->menuText[this->selectedItem]->setColor(sf::Color::White);
  this->selectedItem -= 1;
  if (this->selectedItem < 0) {
    this->selectedItem = MAX_CREATE_GAME_MENU_ITEM - 1;
  }
  this->menuText[this->selectedItem]->setColor(sf::Color::Red);
}
void                        CreateGameMenu::eventDown() {
  this->menuText[this->selectedItem]->setColor(sf::Color::White);
  this->selectedItem += 1;
  if (this->selectedItem >= MAX_CREATE_GAME_MENU_ITEM) {
    this->selectedItem = 0;
  }
  this->menuText[this->selectedItem]->setColor(sf::Color::Red);
}

void                        CreateGameMenu::eventAction() {
  this->nextState = this->menuAssociation[this->selectedItem];
  if (this->selectedItem == 2 && this->roomName.size() != 0) {
    if (client->SendCreateGame(this->roomName, this->difficultyAssociation[this->selectedDifficulty]) == true) {
      this->nextState = MenuState::MAIN_MENU;
    } else {
      this->nextState = MenuState::LOGIN;
    }
  }
}

void                        CreateGameMenu::getUserInput() {
  sf::Event                 event;

  while (this->graphicalEngine->getWindow().pollEvent(event)) {
    if (event.type == sf::Event::TextEntered) {
      if (event.text.unicode < 128 && event.text.unicode != 32 && event.text.unicode != 10 && event.text.unicode != 8) {
        this->roomName += static_cast<char>(event.text.unicode);
      }

      if (event.text.unicode == 8) {
        this->roomName = this->roomName.substr(0, this->roomName.size() - 1);
      } 
    }
  }
}

void                        CreateGameMenu::updateScene(float elapsedTime) {
  this->graphicalEngine->drawToWindow(this->menuTitle->getText());
  for (int i = 0; i < MAX_CREATE_GAME_MENU_ITEM; i++) {
    this->graphicalEngine->drawToWindow(this->menuText[i]->getText());
  }

  for (int i = 0; i < MAX_DIFFICULTY; i++) {
    this->graphicalEngine->drawToWindow(this->menuDifficultySelection[i]->getText());
  }

  if (this->selectedItem == 0) {
    this->getUserInput();
    this->menuText[this->selectedItem]->setString("ROOM NAME      " + this->roomName);
  }
}

IMenuScene::MenuState       CreateGameMenu::getNextState() {
  return this->nextState;
}

void                        CreateGameMenu::resetState() {
  this->roomName = "";
  this->nextState = MenuState::NOTHING;
}