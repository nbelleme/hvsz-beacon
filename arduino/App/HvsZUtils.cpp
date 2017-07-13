#include "HVsZUtils.h"

namespace hvsz {
  String beaconTypeFromEnum(byte t) {
    switch (t) {
      case BeaconType::ZombieHQ:
        return "Zombie HQs";
      case BeaconType::HumanSZ:
        return "Human SafeZone";
      case BeaconType::FoodSupply:
        return "Food Bunker";
    }
  }
}
