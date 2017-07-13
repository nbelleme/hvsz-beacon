#include "LedController.h"
#include "FastLED.h"
#include <math.h>
#include "Gauge.h"
#include "BeaconUtils.h"

using namespace beacon;

/**
 * The Led Controller controls all the leds of the Beacon
 */
LedController::LedController() {
  this->vGauge1 = new Gauge(V_GAUGE_NUM_LEDS);
  this->vGauge2 = new Gauge(V_GAUGE_NUM_LEDS);
  this->hGauge1 = new Gauge(H_GAUGE_NUM_LEDS);
  this->hGauge2 = new Gauge(H_GAUGE_NUM_LEDS);
  this->hGauge3 = new Gauge(H_GAUGE_NUM_LEDS);
  this->ledStrategy = HLEDsStrategy::Beacon;
  currentLed = 0;
  bri = 0;
  dir = true;
}

Gauge* LedController::getVGauge1() {
  return this->vGauge1;
}
Gauge* LedController::getVGauge2() {
  return this->vGauge2;
}
Gauge* LedController::getHGauge1() {
  return this->hGauge1;
}
Gauge* LedController::getHGauge2() {
  return this->hGauge2;
}
Gauge* LedController::getHGauge3() {
  return this->hGauge3;
}

Chrono LedController::getChrono(){
  return this->chrono;
}

byte LedController::getHorizontalLEDsStrategy() {
  return this->ledStrategy;
}
void LedController::setHorizontalLEDsStrategy(byte str) {
  this->ledStrategy = str;
}

void LedController::begin() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(this->leds, NUM_LEDS);
  FastLED.setBrightness(0);
  FastLED.clear(true);
}

void LedController::update() {
  updateGauge(0, vGauge1);
  updateGauge(14, vGauge2);
  switch (this->ledStrategy) {
    case HLEDsStrategy::Separate:
      // Separate <=> each line is a separate gauge
      updateGauge(28, hGauge1);
      updateGauge(36, hGauge2);
      updateGauge(44, hGauge3);

      break;
    case HLEDsStrategy::Combine:
      // Combine <=> hGauge1 is the model, the others are identical
      updateGauge(28, hGauge1);
      updateGauge(36, hGauge1);
      updateGauge(44, hGauge1);
      break;
    case HLEDsStrategy::Beacon:
      // Beacon <=> all gauges moves like a radar
      updateBeacon(28, hGauge1);
  }
  FastLED.setBrightness(bri);
  FastLED.show();
  nextBrightness();
}

void LedController::updateGauge(byte offset, Gauge* gauge) {
  byte ratio = floor(((double) 100) / gauge->getLedCount());
  byte level = (byte) (((double) gauge->getLevel()) / ratio);
  CRGB color = CRGB::Black;
  switch (gauge->getColorStrategy()) {
    case ColorStrategy::SingleColor:
      color = gauge->computeColor(gauge->getLevel());
      for (byte i = 0; i < level; i++) {
        leds[i + offset] = color;
      }
      break;
    case ColorStrategy::ColorGradient:
      for (byte i = 0; i < level; i++) {
        leds[i + offset] = gauge->computeColor(ratio * i);
      }
      break;
  }
  for (byte i = level; i < H_GAUGE_NUM_LEDS; i++) {
    leds[i + offset] = CRGB::Black;
  }
}

void LedController::nextBrightness() {
    if (bri >= BRIGHTNESS_MAX) {
      dir = false;
    } else if (bri <= BRIGHTNESS_MIN) {
      dir = true;
    }
    dir ? bri+= BRIGHTNESS_INC : bri-=BRIGHTNESS_INC;
}

void LedController::nextLed(){
      if (currentLed >= H_GAUGE_NUM_LEDS - 1) {
        dirLed = false;
      } else if (currentLed == 0) {
        dirLed = true;
      }
      dirLed ? currentLed++ : currentLed--;
}

void LedController::updateBeacon(byte offset, Gauge* gauge) {
  CRGB color = gauge->computeColor(gauge->getLevel());

  if (!this->chrono.hasPassed(TIMER_BEACON)) {
    return;
  }

  // Passed time

  if (currentLed > 1 && currentLed < H_GAUGE_NUM_LEDS - 2) {
    updateColors(offset + currentLed + 2 * (dirLed ? -1 : 1), 0, color);
  }

  if (currentLed < H_GAUGE_NUM_LEDS - 1 && currentLed > 0) {
    updateColors(offset + currentLed + 1 * (dirLed ? -1 : 1), 20, color);
  }
  updateColors(offset + currentLed, 50, color);
  nextLed();
  updateColors(offset + currentLed, 100, color);

  this->chrono.restart();
}

void LedController::updateColors(byte offset, byte brightnessRatio, CRGB color) {
  byte ratio = 100/brightnessRatio;
  color.red /= ratio;
  color.green /= ratio;
  color.blue /= ratio;

  leds[offset] = color;
  leds[offset + H_GAUGE_NUM_LEDS] = color;
  leds[offset + 2 * H_GAUGE_NUM_LEDS] = color;
}
