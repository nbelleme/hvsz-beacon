#include <Arduino.h>

class MenuPage {
public:
  MenuPage();
  MenuPage(byte code, String lines[]);
  byte getCode();
  String getLine1();
  String getLine2();
private:
  byte code;
  String line1;
  String line2;
};
