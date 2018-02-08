#include        <iostream>
#include        "SFMLSprite.hpp"
#include        "GameScene.hpp"

GameScene::GameScene(IGraphicalEngine *graphicalEngine, ISoundEngine *soundEngine, Client *client) : background("./assets/game-background.jpg", graphicalEngine->getWindow().getSize().x, graphicalEngine->getWindow().getSize().y) {
  this->graphicalEngine = graphicalEngine;
  this->soundEngine = soundEngine;
  this->client = client;
  this->entityManager = new EntityManager();
  this->nextScene = IScene::SceneState::NOTHING;
  this->client->SetEntityManager(this->entityManager);
}

GameScene::~GameScene()
{}

void            GameScene::eventUp() {
  client->SendPlayerMove(Protocol::PlayerAction::UP);
}

void            GameScene::eventDown() {
  client->SendPlayerMove(Protocol::PlayerAction::DOWN);
}

void            GameScene::eventLeft() {
  client->SendPlayerMove(Protocol::PlayerAction::LEFT);
}

void            GameScene::eventRight() {
  client->SendPlayerMove(Protocol::PlayerAction::RIGHT);
}

void            GameScene::eventAction() {
  client->SendPlayerMove(Protocol::PlayerAction::SHOOT);
}

void            GameScene::eventEnter() { /* NO IMPLEMENTATION NEEDED */ }

IScene::SceneState  GameScene::getNextScene() {
  return this->nextScene;
}

void            GameScene::resetScene() {
  this->nextScene = IScene::SceneState::NOTHING;
}

void            GameScene::updateScene(float elapsedTime) {
  this->background.setScreenSize(this->graphicalEngine->getWindow().getSize().x, this->graphicalEngine->getWindow().getSize().y);
  this->background.update(this->graphicalEngine->getWindow(), elapsedTime);
  entityManager->updateEntities(this->graphicalEngine, elapsedTime);
  client->UpdateGameLoop();
  if (entityManager->shouldIGoToMenu()) {
    this->nextScene = IScene::SceneState::MENU;
    client->getSocketUdp()->setBlocking(true);
    client->getSocketTcp()->setBlocking(true);
  }
}
