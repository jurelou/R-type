#include        "LobbyMenu.hpp"
#include "Serializer.hpp"

LobbyMenu::LobbyMenu(IGraphicalEngine *graphicalEngine, Client *client) {
  this->graphicalEngine = graphicalEngine;
  this->client = client;
  this->nextState = IMenuScene::MenuState::NOTHING;
  this->selectedItem = 0;
  this->menuTitle = new SFMLMenuText(resourceManager->getMenuFont(), "GAME LOBBY", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.3, this->graphicalEngine->getWindow().getSize().y * 0.25, 45);
  this->menuText[0] = new SFMLMenuText(resourceManager->getMenuFont(), "READY ?", sf::Color::Red, this->graphicalEngine->getWindow().getSize().x * 0.3, this->graphicalEngine->getWindow().getSize().y * 0.8);
  this->menuText[1] = new SFMLMenuText(resourceManager->getMenuFont(), "RETURN", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.6, this->graphicalEngine->getWindow().getSize().y * 0.8);
  this->players = new SFMLMenuText(resourceManager->getMenuFont(), "", sf::Color::White, 0, 0, 25);
}

LobbyMenu::~LobbyMenu()
{}

void            LobbyMenu::eventUp() {
  this->menuText[this->selectedItem]->setColor(sf::Color::White);
  this->selectedItem -= 1;
  if (this->selectedItem < 0) {
    this->selectedItem = MAX_LOBBY_MENU_ITEM - 1;
  }
  this->menuText[this->selectedItem]->setColor(sf::Color::Red);
}

void            LobbyMenu::eventDown() {
  this->menuText[this->selectedItem]->setColor(sf::Color::White);
  this->selectedItem += 1;
  if (this->selectedItem >= MAX_LOBBY_MENU_ITEM) {
    this->selectedItem = 0;
  }
  this->menuText[this->selectedItem]->setColor(sf::Color::Red);
}

void            LobbyMenu::eventLeft() {}
void            LobbyMenu::eventRight() {}
void            LobbyMenu::eventAction() {
  if (this->selectedItem == 0) {
    client->SendJoinGame("1");
  }
}
void            LobbyMenu::eventEnter() {
  if (this->selectedItem == 0) {
    client->SendJoinGame("1");
  }
}

void            LobbyMenu::updatePlayerList() {
  sf::Vector2f  v;

  v.x = this->graphicalEngine->getWindow().getSize().x * 0.4;
  v.y = this->graphicalEngine->getWindow().getSize().y * 0.4;
  for (auto it: client->getLobbyList()) {
    this->players->setString(it.first);
    this->players->setColor(it.second == 1 ? sf::Color::Green : sf::Color::Red);
    this->players->setPosition(v.x, v.y);
    this->graphicalEngine->drawToWindow(this->players->getText());
    v.y += 30;
  }
}

void            LobbyMenu::resetState() {
  this->nextState = IMenuScene::MenuState::NOTHING;
}

void            LobbyMenu::updateScene(float elapsedTime) {
  this->graphicalEngine->drawToWindow(this->menuTitle->getText());
  for (int i = 0; i < MAX_LOBBY_MENU_ITEM; i++) {
    this->graphicalEngine->drawToWindow(this->menuText[i]->getText());
  }
  client->UpdateTcpLobby();
  this->updatePlayerList();
  if (client->UpdateUdpLobby()) {
    this->nextState = IMenuScene::MenuState::GOTO_GAME;
  }
}

IMenuScene::MenuState   LobbyMenu::getNextState() {
  return this->nextState;
}
