#include        <iostream>
#include        "LoginMenu.hpp"

LoginMenu::LoginMenu(IGraphicalEngine *graphicalEngine, Client *client) {
  this->graphicalEngine = graphicalEngine;
  this->nextState = IMenuScene::MenuState::NOTHING;
  this->selectedItem = 0;
  this->loadingScreen.setText(resourceManager->getMenuFont(), this->graphicalEngine->getWindow().getSize().x, this->graphicalEngine->getWindow().getSize().y);
  this->loadingScreen.setSizes(this->graphicalEngine->getWindow().getSize().x, this->graphicalEngine->getWindow().getSize().y);
  this->client = client;
  this->menuText[0] = new SFMLMenuText(resourceManager->getMenuFont(), "SERVER IP", sf::Color::Red, this->graphicalEngine->getWindow().getSize().x * 0.2, this->graphicalEngine->getWindow().getSize().y * 0.3);
  this->menuText[1] = new SFMLMenuText(resourceManager->getMenuFont(), "SERVER PORT", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.2, this->graphicalEngine->getWindow().getSize().y * 0.4);
  this->menuText[2] = new SFMLMenuText(resourceManager->getMenuFont(), "USERNAME", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.2, this->graphicalEngine->getWindow().getSize().y * 0.5);
  this->menuText[3] = new SFMLMenuText(resourceManager->getMenuFont(), "LAUNCH", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.4, this->graphicalEngine->getWindow().getSize().y * 0.75);
  this->menuAssociation[0] = IMenuScene::MenuState::NOTHING;
  this->menuAssociation[1] = IMenuScene::MenuState::NOTHING;
  this->menuAssociation[2] = IMenuScene::MenuState::NOTHING;
  this->menuAssociation[3] = IMenuScene::MenuState::MAIN_MENU;
  this->baseText[0] = "SERVER IP      ";
  this->baseText[1] = "SERVER PORT    ";
  this->baseText[2] = "USERNAME       ";
}

LoginMenu::~LoginMenu()
{}

void                              LoginMenu::eventUp() {
  this->menuText[this->selectedItem]->setColor(sf::Color::White);
  this->selectedItem -= 1;
  if (this->selectedItem < 0) {
    this->selectedItem = MAX_LOGIN_MENU_ITEM - 1;
  }
  this->menuText[this->selectedItem]->setColor(sf::Color::Red);
}

void                              LoginMenu::eventDown() {
  this->menuText[this->selectedItem]->setColor(sf::Color::White);
  this->selectedItem += 1;
  if (this->selectedItem >= MAX_LOGIN_MENU_ITEM) {
    this->selectedItem = 0;
  }
  this->menuText[this->selectedItem]->setColor(sf::Color::Red);
}

void                              LoginMenu::eventLeft() { /* NO NEED TO BE IMPLEMENTED */ }

void                              LoginMenu::eventRight() { /* NO NEED TO BE IMPLEMENTED */ }

void                              LoginMenu::eventEnter() {
  if (this->selectedItem == 3) {
    for (int i = 0; i < 3; i++) {
      if (this->serverCred[i].size() == 0)
        return;
    }
    client->initSocket(this->serverCred[0], this->serverCred[1]);
    if (client->SendLogin(this->serverCred[2]) == true)
      this->nextState = IMenuScene::MenuState::MAIN_MENU;
  }
}

void                              LoginMenu::eventAction() {
  if (this->selectedItem == 3) {
    for (int i = 0; i < 3; i++) {
      if (this->serverCred[i].size() == 0)
        return;
    }
    this->loadingScreen.setLoading(this->graphicalEngine);
    client->initSocket(this->serverCred[0], this->serverCred[1]);
    if (client->SendLogin(this->serverCred[2]) == true)
      this->nextState = IMenuScene::MenuState::MAIN_MENU;
  }
}

void                              LoginMenu::getUserInput() {
  sf::Event                 event;

  while (this->graphicalEngine->getWindow().pollEvent(event)) {
    if (event.type == sf::Event::TextEntered) {
      if (event.text.unicode < 128 && event.text.unicode != 32 && event.text.unicode != 10 && event.text.unicode != 8) {
        this->serverCred[this->selectedItem] += static_cast<char>(event.text.unicode);
      }

      if (event.text.unicode == 8) {
        this->serverCred[this->selectedItem] = this->serverCred[this->selectedItem].substr(0, this->serverCred[this->selectedItem].size() - 1);
      } 
    }
  }
}

void                              LoginMenu::updateScene(float elapstedTime) {
  for (int i = 0; i < MAX_LOGIN_MENU_ITEM; i++) {
    this->graphicalEngine->drawToWindow(this->menuText[i]->getText());
  }

  if (this->selectedItem == 0 || this->selectedItem == 1 || this->selectedItem == 2) {
    this->getUserInput();
    this->menuText[this->selectedItem]->setString(this->baseText[this->selectedItem] + this->serverCred[this->selectedItem]);
  }
}

IMenuScene::MenuState             LoginMenu::getNextState() {
  return this->nextState;
}

void                              LoginMenu::resetState() {
  this->nextState = IMenuScene::MenuState::NOTHING;
}