#include      <iostream>
#include      "SFML.hpp"
#include      "SFMLMenuEvent.hpp"
#include      "SFMLGameEvent.hpp"
#include      "SFMLSoundEngine.hpp"
#include      "Game.hpp"
#include      "MenuScene.hpp"
#include      "GameScene.hpp"

Game::Game() {
  this->graphics = new SFML();
  this->sound = new SFMLSoundEngine();
  this->client = new Client();
  this->currentScene = IScene::SceneState::MENU;
  this->event[IScene::SceneState::MENU] = new SFMLMenuEvent();
  this->event[IScene::SceneState::GAME] = new SFMLGameEvent();
  this->scene[IScene::SceneState::MENU] = new MenuScene(this->graphics, this->sound, this->client);
  this->scene[IScene::SceneState::GAME] = new GameScene(this->graphics, this->sound, this->client);
  this->updateSceneInput();
}

Game::~Game()
{}

void          Game::updateSceneInput() {
  this->event[this->currentScene]->setEvent(Event::EXIT, std::bind(&IGraphicalEngine::closeWindow, this->graphics));
  this->event[this->currentScene]->setEvent(Event::UP, std::bind(&IScene::eventUp, this->scene[this->currentScene]));
  this->event[this->currentScene]->setEvent(Event::DOWN, std::bind(&IScene::eventDown, this->scene[this->currentScene]));
  this->event[this->currentScene]->setEvent(Event::LEFT, std::bind(&IScene::eventLeft, this->scene[this->currentScene]));
  this->event[this->currentScene]->setEvent(Event::RIGHT, std::bind(&IScene::eventRight, this->scene[this->currentScene]));
  this->event[this->currentScene]->setEvent(Event::ENTER, std::bind(&IScene::eventEnter, this->scene[this->currentScene]));
  this->event[this->currentScene]->setEvent(Event::ACTION, std::bind(&IScene::eventAction, this->scene[this->currentScene]));
}

void          Game::loop() {
  sf::Clock   clock;

  while (this->graphics->getWindowState()) {
    this->graphics->clearWindow();
    this->event[this->currentScene]->pollEvent(this->graphics->getWindow());
    this->event[this->currentScene]->callEvent();
    this->scene[this->currentScene]->updateScene(clock.restart().asMilliseconds());
    this->graphics->renderWindow();
    if (this->scene[this->currentScene]->getNextScene() != IScene::SceneState::NOTHING) {
      IScene::SceneState tmp = this->scene[this->currentScene]->getNextScene();
      this->currentScene = this->scene[this->currentScene]->getNextScene();
      this->scene[tmp]->resetScene();
      this->updateSceneInput();
    }
  }
}
