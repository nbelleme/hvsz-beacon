#include "Game.h"
#include <math.h>
#include <Arduino.h>
#define HVSZ_MENU_SETTINGS 2
#define HVSZ_MENU_BEACONTYPE 3
#define HVSZ_MENU_REMOTEHOST 4
#define HVSZ_MENU_BT_HSF 5
#define HVSZ_MENU_BT_ZHQ 6
#define HVSZ_MENU_BT_FS 7

class MenuCallbacks;
class NfcCallbacks;
/**
 * The Game represents any kind of game
 */
class HVsZGame : public Game, public MenuCallbacks, public NfcCallbacks {
public:
  HVsZGame();
  virtual void init();
  virtual void onBtnPressed(Button& btn, byte pin);
  virtual void onBtnReleased(Button& btn, byte pin);
  virtual void onMenuItemSelected(byte code);
  virtual void onMenuItemExit(byte code);
  virtual void onMenuPageChanged(byte code);
  virtual void onCardIn();
  virtual void onCardHold();
  virtual void onCardOut();
private:
  byte beaconType;
  String remoteHost;
  int remainingTime;
  MenuPage* showBaseMenu();
  MenuPage* showSettingsMenu();
  MenuPage* showBeaconTypeSetupMenu();
};
