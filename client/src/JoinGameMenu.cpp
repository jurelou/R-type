#include          "JoinGameMenu.hpp"

JoinGameMenu::JoinGameMenu(IGraphicalEngine *graphicalEngine, Client *client) {
  this->client = client;
  this->graphicalEngine = graphicalEngine;
  this->nextState = IMenuScene::MenuState::NOTHING;
  this->selectedItem = 0;
  this->loadingScreen.setText(resourceManager->getMenuFont(), this->graphicalEngine->getWindow().getSize().x, this->graphicalEngine->getWindow().getSize().y);
  this->loadingScreen.setSizes(this->graphicalEngine->getWindow().getSize().x, this->graphicalEngine->getWindow().getSize().y);
  this->menuTitle = new SFMLMenuText(resourceManager->getMenuFont(), "JOIN GAME", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.3, this->graphicalEngine->getWindow().getSize().y / 4, 45);
  this->menuText[0] = new SFMLMenuText(resourceManager->getMenuFont(), "REFRESH", sf::Color::Red, this->graphicalEngine->getWindow().getSize().x * 0.3, this->graphicalEngine->getWindow().getSize().y * 0.8);
  this->menuText[1] = new SFMLMenuText(resourceManager->getMenuFont(), "RETURN", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.6, this->graphicalEngine->getWindow().getSize().y * 0.8);
  this->menuAssociation[0] = MenuState::NOTHING;
  this->menuAssociation[1] = MenuState::MAIN_MENU;
  this->totalItem = MAX_JOIN_GAME_MENU_ITEM;
}

JoinGameMenu::~JoinGameMenu()
{}

void                        JoinGameMenu::eventLeft() { /* NO NEED TO BE IMPLEMENTED */ }
void                        JoinGameMenu::eventRight() { /* NO NEED TO BE IMPLEMENTED */ }
void                        JoinGameMenu::eventEnter() { /* NO NEED TO BE IMPLEMENTED */ }

void                        JoinGameMenu::eventUp() {
  this->menuText[this->selectedItem]->setColor(sf::Color::White);
  this->selectedItem -= 1;
  if (this->selectedItem < 0) {
    this->selectedItem = this->totalItem - 1;
  }
  this->menuText[this->selectedItem]->setColor(sf::Color::Red);
}
void                        JoinGameMenu::eventDown() {
  this->menuText[this->selectedItem]->setColor(sf::Color::White);
  this->selectedItem += 1;
  if (this->selectedItem >= this->totalItem) {
    this->selectedItem = 0;
  }
  this->menuText[this->selectedItem]->setColor(sf::Color::Red);
}

void                        JoinGameMenu::eventAction() {
  if (this->selectedItem == 0) {
    this->updateGameList();
  } else if (this->selectedItem >= 2) {
    std::cout << this->gameList[this->selectedItem - 2] << std::endl;
    std::cout << client->SendJoinLobby(this->gameList[this->selectedItem - 2]) << std::endl;
    client->getSocketUdp()->setBlocking(false);
    client->getSocketTcp()->setBlocking(false);
    this->nextState = MenuState::LOBBY;
  } else {
    this->nextState = this->menuAssociation[this->selectedItem];
  }
}

void                        JoinGameMenu::updateGameList() {
  sf::Vector2f              v;
  int                       i = 0;

  this->selectedItem = 0;
  this->loadingScreen.setLoading(this->graphicalEngine);
  v.x = this->graphicalEngine->getWindow().getSize().x * 0.4;
  v.y = this->graphicalEngine->getWindow().getSize().y * 0.4;
  if (client->SendListGame() == false) {
    this->nextState = MenuState::LOGIN;
    return;
  }
  this->gameList.clear();
  this->menuText.clear();
  this->menuText[0] = new SFMLMenuText(resourceManager->getMenuFont(), "REFRESH", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.3, this->graphicalEngine->getWindow().getSize().y * 0.8);
  this->menuText[1] = new SFMLMenuText(resourceManager->getMenuFont(), "RETURN", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.6, this->graphicalEngine->getWindow().getSize().y * 0.8);
  for (auto it: client->getGamesList()) {
    this->gameList[i] = it;
    this->menuText[i + 2] = new SFMLMenuText(resourceManager->getMenuFont(), it, sf::Color::White, v.x, v.y, 25);
    v.y += 30;
    i += 1;
  }
  this->totalItem = MAX_JOIN_GAME_MENU_ITEM + this->gameList.size();
}

void                        JoinGameMenu::updateScene(float elapsedtime) {
  this->graphicalEngine->drawToWindow(this->menuTitle->getText());
  for (int i = 0; i < this->totalItem; i++) {
    this->graphicalEngine->drawToWindow(this->menuText[i]->getText());
  }
}

IMenuScene::MenuState       JoinGameMenu::getNextState() {
  return this->nextState;
}

void                        JoinGameMenu::resetState() {
  this->menuText.clear();
  this->gameList.clear();
  this->menuText[0] = new SFMLMenuText(resourceManager->getMenuFont(), "REFRESH", sf::Color::Red, this->graphicalEngine->getWindow().getSize().x * 0.3, this->graphicalEngine->getWindow().getSize().y * 0.8);
  this->menuText[1] = new SFMLMenuText(resourceManager->getMenuFont(), "RETURN", sf::Color::White, this->graphicalEngine->getWindow().getSize().x * 0.6, this->graphicalEngine->getWindow().getSize().y * 0.8);
  this->totalItem = MAX_JOIN_GAME_MENU_ITEM;
  this->selectedItem = 0;
  this->nextState = MenuState::NOTHING;
}