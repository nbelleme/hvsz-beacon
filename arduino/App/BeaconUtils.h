#include <Arduino.h>

namespace beacon {
  /**
   * Color Strategy:
   * SingleColor: Will draw all LEDS of the same color
   * ColorGradient: Will draw LEDS with a gradient until current level"
   */
  namespace ColorStrategy {
    static const byte SingleColor = 0;
    static const byte ColorGradient = 1;
  }
  /**
   * Horizontal LEDs Strategy:
   * Separate: Will treat each line as a separate Gauge
   * Combine: Will consider the three lines as equal (as in parallel)
   * Beacon: The LEDs will be animated like a beacon (custom animation)
   */
  namespace HLEDsStrategy {
    static const byte Separate = 0;
    static const byte Combine = 1;
    static const byte Beacon = 2;
  }
}
