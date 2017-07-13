class HVsZSettings {
  public:
    HVsZSettings();
    void setGameTime(unsigned int gameTime);
    unsigned int getGameTime();
    void setFoodSupplyQuantity(unsigned int qty);
    unsigned int getFoodSupplyQuantity();
    void setSafeZoneInitialFood(unsigned int qty);
    unsigned int getSafeZoneInitialFood();
    void setSafeZoneFoodEatenPerMinute(unsigned int qty);
    unsigned int getSafeZoneFoodEatenPerMinute();
    void setMaxFoodCarry(unsigned int qty);
    unsigned int getMaxFoodCarry();
  private:
  // Game time in seconds
  unsigned int gameTime;
  // Food Supply capacity in kg
  unsigned int foodSupplyQuantity;
  // Quantity of food initially present in a safe zone in kg
  unsigned int safeZoneInitialFood;
  // Food eaten per minute in kg / minute
  unsigned int safeZoneFoodEatenPerMinute;
  // Maximum quantity of food one can carry in kg
  unsigned int maxFoodCarry;
};
