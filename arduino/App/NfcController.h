#include <PN532.h>
#include "NfcCallbacks.h"

class NfcController : public NfcCallbacks {
public:
  NfcController();
  void begin();
  void update();
  uint8_t* readBlock(uint8_t sector, uint8_t blockNumber);
  void writeBlock(uint8_t sector, uint8_t blockNumber, uint8_t data[16]);
  boolean hasCard();
  void setNfcCallbacks(NfcCallbacks& cb);
  virtual void onCardIn();
  virtual void onCardHold();
  virtual void onCardOut();
private:
  uint8_t keys[6] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
  boolean lastHasCard;
  PN532* nfc;
  NfcCallbacks* cb;
  boolean authenticateBlock(uint8_t blockn);

};
