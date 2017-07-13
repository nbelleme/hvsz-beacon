#include "MenuPage.h"


MenuPage::MenuPage() {
}
MenuPage::MenuPage(byte code, String lines[]) {
  this->code = code;
  this->line1 = lines[0];
  this->line2 = lines[1];
}

byte MenuPage::getCode() {
  return this->code;
}

String MenuPage::getLine1() {
  return this->line1;
}

String MenuPage::getLine2() {
  return this->line2;
}
