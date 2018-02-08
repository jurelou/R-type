#include        <iostream>
#include        "MenuScene.hpp"
#include        "MainMenu.hpp"
#include        "CreateGameMenu.hpp"
#include        "JoinGameMenu.hpp"
#include        "EditSkinsMenu.hpp"
#include        "LoginMenu.hpp"
#include        "LobbyMenu.hpp"

MenuScene::MenuScene(IGraphicalEngine *graphicalEngine, ISoundEngine *soundEngine, Client *client) : background("./assets/menu-background.jpg", graphicalEngine->getWindow().getSize().x, graphicalEngine->getWindow().getSize().y) {
  this->graphicalEngine = graphicalEngine;
  this->soundEngine = soundEngine;
  this->client = client;
  this->nextScene = SceneState::NOTHING;
  this->currentState = IMenuScene::MenuState::LOGIN;
  this->menuMap[IMenuScene::MenuState::LOGIN] = new LoginMenu(this->graphicalEngine, this->client);
  this->menuMap[IMenuScene::MenuState::MAIN_MENU] = new MainMenu(this->graphicalEngine);
  // this->menuMap[IMenuScene::MenuState::EDIT_SKINS] = new EditSkinsMenu(this->graphicalEngine);
  this->menuMap[IMenuScene::MenuState::CREATE_GAME] = new CreateGameMenu(this->graphicalEngine, this->client);
  this->menuMap[IMenuScene::MenuState::JOIN_GAME] = new JoinGameMenu(this->graphicalEngine, this->client);
  this->menuMap[IMenuScene::MenuState::LOBBY] = new LobbyMenu(this->graphicalEngine, this->client);
  this->soundEngine->playMusic(resourceManager->getMenuMusic());
}

MenuScene::~MenuScene()
{}

void            MenuScene::eventUp() {
  this->soundEngine->playSound(resourceManager->getMenuSoundEffect());
  this->menuMap[this->currentState]->eventUp();
}

void            MenuScene::eventDown() {
  this->soundEngine->playSound(resourceManager->getMenuSoundEffect());
  this->menuMap[this->currentState]->eventDown();
}

void            MenuScene::eventLeft() {
  this->soundEngine->playSound(resourceManager->getMenuSoundEffect());
  this->menuMap[this->currentState]->eventLeft();
}

void            MenuScene::eventRight() {
  this->soundEngine->playSound(resourceManager->getMenuSoundEffect());
  this->menuMap[this->currentState]->eventRight();
}

void            MenuScene::eventEnter() {
  this->soundEngine->playSound(resourceManager->getMenuSoundEffect());
  this->menuMap[this->currentState]->eventEnter();
}

void            MenuScene::eventAction() {
  this->soundEngine->playSound(resourceManager->getMenuSoundEffect());
  this->menuMap[this->currentState]->eventAction();
}

IScene::SceneState MenuScene::getNextScene() {
  return this->nextScene;
}

void            MenuScene::resetScene() {
  this->nextScene = IScene::SceneState::NOTHING;
  this->currentState = IMenuScene::MenuState::MAIN_MENU;
}

void            MenuScene::updateScene(float elapsedTime) {
  this->background.setScreenSize(this->graphicalEngine->getWindow().getSize().x, this->graphicalEngine->getWindow().getSize().y);
  this->background.update(this->graphicalEngine->getWindow(), elapsedTime);
  if (this->menuMap[this->currentState]->getNextState() == IMenuScene::MenuState::GOTO_GAME) {
    this->nextScene = SceneState::GAME;
    this->currentState = IMenuScene::MenuState::MAIN_MENU;
  } else if (this->menuMap[this->currentState]->getNextState() != IMenuScene::MenuState::NOTHING) {
    IMenuScene::MenuState tmp = this->currentState;
    this->currentState = this->menuMap[this->currentState]->getNextState();
    this->menuMap[tmp]->resetState();
  }
  this->menuMap[this->currentState]->updateScene(elapsedTime);
}
