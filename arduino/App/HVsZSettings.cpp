#include "HVsZSettings.h"

HVsZSettings::HVsZSettings() {
}

void HVsZSettings::setGameTime(unsigned int gameTime) {
  this->gameTime = gameTime;
}

unsigned int HVsZSettings::getGameTime() {
  return this->gameTime;
}
void HVsZSettings::setFoodSupplyQuantity(unsigned int qty) {
  this->foodSupplyQuantity = qty;
}
unsigned int HVsZSettings::getFoodSupplyQuantity() {
  return this->foodSupplyQuantity;
}
void HVsZSettings::setSafeZoneInitialFood(unsigned int qty) {
  this->safeZoneInitialFood = qty;
}
unsigned int HVsZSettings::getSafeZoneInitialFood() {
  return this->safeZoneInitialFood;
}
void HVsZSettings::setSafeZoneFoodEatenPerMinute(unsigned int qty) {
  this->safeZoneFoodEatenPerMinute = qty;
}
unsigned int HVsZSettings::getSafeZoneFoodEatenPerMinute() {
  return this->safeZoneFoodEatenPerMinute;
}
void HVsZSettings::setMaxFoodCarry(unsigned int qty) {
  this->maxFoodCarry = qty;
}
unsigned int HVsZSettings::getMaxFoodCarry() {
  return this->maxFoodCarry;
}
