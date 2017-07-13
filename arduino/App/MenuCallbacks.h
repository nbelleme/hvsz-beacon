#include <Arduino.h>

class Button;

class MenuCallbacks {
public:
  MenuCallbacks();
  virtual void onBtnPressed(Button& btn, byte pin) = 0;
  virtual void onBtnReleased(Button& btn, byte pin) = 0;
  virtual void onMenuItemSelected(byte code) = 0;
  virtual void onMenuItemExit(byte code) = 0;
  virtual void onMenuPageChanged (byte code) = 0;
};
