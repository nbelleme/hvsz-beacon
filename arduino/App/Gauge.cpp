#include "Gauge.h"
#include "FastLED.h"
#include "BeaconUtils.h"

using namespace beacon;

CRGB defaultComputeColorFunc(byte level) {
  if (level <= 20) {
    return CRGB::Red;
  }
  if (level <= 30) {
    return CRGB::DarkOrange;
  }
  if (level <= 50) {
    return CRGB::Orange;
  }
  if (level <= 80) {
    return CRGB::DarkGreen;
  }
  return CRGB::Blue;
}

Gauge::Gauge(byte ledCount) {
  this->ledCount = ledCount;
  this->colorStrategy = ColorStrategy::ColorGradient;
  this->level = 10;
  this->computeColorFunc = &defaultComputeColorFunc;
}

byte Gauge::getLevel() {
  return this->level;
}

void Gauge::setLevel(byte lvl) {
  this->level = lvl;
}

byte Gauge::getLedCount() {
  return this->ledCount;
}

void Gauge::setLedCount(byte ledCount) {
  this->ledCount = ledCount;
}

byte Gauge::getColorStrategy() {
  return this->colorStrategy;
}

void Gauge::setColorStrategy(byte str) {
  this->colorStrategy = str;
}

CRGB Gauge::computeColor(byte level) {
  return this->computeColorFunc(level);
}

void Gauge::overrideComputeColor(CRGB (*func)(byte)) {
  this->computeColorFunc = func;
}
