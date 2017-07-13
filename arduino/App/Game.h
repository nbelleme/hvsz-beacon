#include "LedController.h"
#include "MenuController.h"
#include "NfcController.h"
/**
 * The Game represents any kind of game
 */
class Game {
public:
  Game();
  virtual void init() = 0;
  LedController* getLedController();
  MenuController* getMenuController();
  NfcController* getNfcController();
protected:
  LedController* ledController;
  MenuController* menuController;
  NfcController* nfcController;
};
