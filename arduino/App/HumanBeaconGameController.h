#include <Arduino.h>

class HVsZSettings;
class LedController;
class MenuController;
class MenuPage;

class HumanBeaconGameController {
public:
  HumanBeaconGameController(LedController* lc, MenuController* mc);
  void start(HVsZSettings* settings);
  void update(unsigned int remainingTime);
private:
  byte remainingLevel;
  byte loadRate;
  MenuPage* showBaseMenu(unsigned int remainingTime);
  HVsZSettings* settings;
  MenuController* menuController;
  LedController* ledController;
};
