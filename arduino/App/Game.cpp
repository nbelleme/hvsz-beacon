#include "Game.h"

Game::Game() {
  ledController = new LedController();
  menuController = new MenuController();
  nfcController = new NfcController();
}

LedController* Game::getLedController() {
  return this->ledController;
}

MenuController* Game::getMenuController() {
  return this->menuController;
}

NfcController* Game::getNfcController() {
  return this->nfcController;
}
