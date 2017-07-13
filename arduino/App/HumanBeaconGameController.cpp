#include "HumanBeaconGameController.h"
#include "HVsZSettings.h"
#include "LedController.h"
#include "MenuController.h"
#include "HVsZUtils.h"

using namespace hvsz;

HumanBeaconGameController::HumanBeaconGameController(LedController* lc, MenuController* mc) {
  this->ledController = lc;
  this->menuController = mc;
}

void HumanBeaconGameController::start(HVsZSettings* settings) {
  this->settings = settings;
  this->remainingLevel = 100;
  this->loadRate = 0;
  this->menuController->setMenuContent(showBaseMenu(settings->getGameTime()), 2);

}

void HumanBeaconGameController::update(unsigned int remainingTime) {
  this->menuController->setMenuContent(showBaseMenu(remainingTime), 2);
}

/**
 * This is the base human menu
 */
MenuPage* HumanBeaconGameController::showBaseMenu(unsigned int remainingTime) {
  String remainTimeStr = "Time:";
  remainTimeStr += (byte)(remainingTime / 60);
  remainTimeStr += ":";
  byte remainingSeconds = remainingTime % 60;
  if (remainingSeconds < 10) {
    remainTimeStr += "0";
  }
  remainTimeStr += remainingSeconds;
  return new MenuPage[1] {
    MenuPage(1, new String[2]{beaconTypeFromEnum(BeaconType::HumanSZ),remainTimeStr})
  };
}
