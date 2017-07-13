#include "FastLED.h"
#include "Chrono.h"

#define NUM_LEDS 52
#define V_GAUGE_NUM_LEDS 14
#define H_GAUGE_NUM_LEDS 8

#ifndef BRIGHTNESS_MIN
#define BRIGHTNESS_MIN  60
#endif
#ifndef BRIGHTNESS_MAX
#define BRIGHTNESS_MAX  200
#endif
#ifndef BRIGHTNESS_INC
#define BRIGHTNESS_INC 7
#endif


#ifndef TIMER_BEACON
#define TIMER_BEACON 75
#endif

#ifndef LED_PIN
#define LED_PIN 10
#endif

class Gauge;

/**
   The Led Controller controls all the leds of the Beacon
*/
class LedController {
  public:
    LedController();
    void begin();
    void update();
    void stop();
    /**
       See enum declaration for details
    */
    byte getHorizontalLEDsStrategy();
    void setHorizontalLEDsStrategy(byte str);
    Gauge* getVGauge1();
    Gauge* getVGauge2();
    Gauge* getHGauge1();
    Gauge* getHGauge2();
    Gauge* getHGauge3();
    Chrono getChrono();
  private:
    Gauge* vGauge1;
    Gauge* vGauge2;
    Gauge* hGauge1;
    Gauge* hGauge2;
    Gauge* hGauge3;
    Chrono chrono;
    byte ledStrategy;
    CRGB leds[NUM_LEDS];
    byte bri;
    boolean dir;
    boolean dirLed;
    byte currentLed;
    /**
       Used internally to update the current gauge color
    */
    void updateGauge(byte offset, Gauge* gauge);
    /**
       Used internally to determine the next gauge brightness
    */
    void nextBrightness();

    /**
      Used internally to update all the gauges in beacon strategy
    */
    void updateBeacon(byte offset, Gauge* gauge);

    /**
       Used internally to determine the next led to turn on
    */
    void nextLed();

    /**
      Used to update led colors in beacon mode
    */
    void updateColors(byte offset, byte brightnessRatio, CRGB color);
};
