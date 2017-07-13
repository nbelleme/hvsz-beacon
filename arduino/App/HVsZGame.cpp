#include "HVsZGame.h"
#include "HVsZUtils.h"
#include "Gauge.h"
#include "BeaconUtils.h"

using namespace hvsz;

CRGB alwaysBlueColorCompute (byte level) { return CRGB::Blue; }

CRGB alwaysPurpleColorCompute (byte level) { return CRGB::Purple; }

HVsZGame::HVsZGame() {
  ledController->getVGauge2()->setColorStrategy(beacon::ColorStrategy::SingleColor);
  // Set Strategy to beacon
  ledController->setHorizontalLEDsStrategy(beacon::HLEDsStrategy::Beacon);
  ledController->getVGauge2()->overrideComputeColor(&alwaysBlueColorCompute);
  ledController->getHGauge1()->overrideComputeColor(&alwaysPurpleColorCompute);
  ledController->getHGauge2()->overrideComputeColor(&alwaysPurpleColorCompute);
  ledController->getHGauge3()->overrideComputeColor(&alwaysPurpleColorCompute);
  this->remainingTime = 600; // 10 min
  this->beaconType = BeaconType::HumanSZ;
}

void HVsZGame::init() {
  // Show base menu
  menuController->setMenuContent(showBaseMenu(), 2);
  // Create callbacks
  menuController->setMenuCallbacks(*this);
  nfcController->setNfcCallbacks(*this);
}

void HVsZGame::onMenuItemSelected(byte code) {
  switch (code) {
    case HVSZ_MENU_SETTINGS:
      menuController->setMenuContent(showSettingsMenu(), 2);
      menuController->showPage(0);
      break;
    case HVSZ_MENU_BEACONTYPE:
      menuController->setMenuContent(showBeaconTypeSetupMenu(), 3);
      menuController->showPage(0);
      break;
    case HVSZ_MENU_REMOTEHOST:
      break;
    case HVSZ_MENU_BT_HSF:
      Serial.println("Chosen Human SafeZone mode");
      menuController->setMenuContent(showSettingsMenu(), 2);
      menuController->showPage(0);
      break;
    case HVSZ_MENU_BT_ZHQ:
      Serial.println("Chosen Zombie HQ mode");
      menuController->setMenuContent(showSettingsMenu(), 2);
      menuController->showPage(0);
      break;
    case HVSZ_MENU_BT_FS:
      Serial.println("Chosen FoodSupply mode");
      menuController->setMenuContent(showSettingsMenu(), 2);
      menuController->showPage(0);
      break;
  }
}

void HVsZGame::onMenuItemExit(byte code) {
  switch (code) {
    case HVSZ_MENU_SETTINGS:
      break;
    case HVSZ_MENU_BEACONTYPE:
    case HVSZ_MENU_REMOTEHOST:
      // Back to base menu, setup page
      menuController->setMenuContent(showBaseMenu(), 2);
      menuController->showPage(1);
      break;
    case HVSZ_MENU_BT_HSF:
    case HVSZ_MENU_BT_ZHQ:
    case HVSZ_MENU_BT_FS:
      menuController->setMenuContent(showSettingsMenu(), 2);
      menuController->showPage(0);
      break;
  }
}

void HVsZGame::onMenuPageChanged(byte code) {
  Serial.print("Clicked on ");
  Serial.println(code);
}


void HVsZGame::onBtnPressed(Button& button, byte btnPin) {
  //TODO
}

void HVsZGame::onBtnReleased(Button& button, byte btnPin) {
  //TODO
}

void HVsZGame::onCardIn() {
}
void HVsZGame::onCardHold() {
}
void HVsZGame::onCardOut() {
}

/**
 * This is the game base menu
 */
MenuPage* HVsZGame::showBaseMenu() {
  return new MenuPage[2] {
    MenuPage(1, new String[2]{"Beacon Type:", beaconTypeFromEnum(this->beaconType)}),
    MenuPage(HVSZ_MENU_SETTINGS, new String[2]{"Settings:", "Press Enter"})
  };
}

/**
 * This is the game settings menu
 */
MenuPage* HVsZGame::showSettingsMenu() {
  return new MenuPage[2] {
    MenuPage(HVSZ_MENU_BEACONTYPE, new String[2]{">Beacon Type:",beaconTypeFromEnum(this->beaconType)}),
    MenuPage(HVSZ_MENU_REMOTEHOST, new String[2]{">Remote Host:", "123.123.123.123"})
  };
}

/**
 * This is the type configuration menu
 */
MenuPage* HVsZGame::showBeaconTypeSetupMenu() {
  return new MenuPage[3] {
    MenuPage(HVSZ_MENU_BT_HSF, new String[2]{"Beacon Type:", ">" + beaconTypeFromEnum(BeaconType::HumanSZ)}),
    MenuPage(HVSZ_MENU_BT_ZHQ, new String[2]{"Beacon Type:", ">" + beaconTypeFromEnum(BeaconType::ZombieHQ)}),
    MenuPage(HVSZ_MENU_BT_FS, new String[2]{"Beacon Type:", ">" + beaconTypeFromEnum(BeaconType::FoodSupply)}),
  };
}
