#include <Arduino.h>

namespace hvsz {
  String beaconTypeFromEnum(byte t);
  namespace BeaconType {
    static const byte ZombieHQ = 0;
    static const byte HumanSZ = 1;
    static const byte FoodSupply = 2;
  }
}
