#include "HVsZGame.h"
#include "gauge.h"
#define LED_PIN 10

Game* game;
Gauge* gauge1;
Chrono myChrono;

void setup() {
  game = new HVsZGame();
  Serial.begin(115200);
  Serial.println("Init");
  game->init();
  // Start Menu Controller
  game->getMenuController()->begin();
  // Start Led Controller
  game->getLedController()->begin();
  // Start NFC Controller
  //game->getNfcController()->begin();

  // Set dummy values for testing
  game->getLedController()->getVGauge1()->setLevel(100);
  game->getLedController()->getVGauge2()->setLevel(100);
  game->getLedController()->getHGauge1()->setLevel(40);
  game->getLedController()->getHGauge2()->setLevel(0);
  game->getLedController()->getHGauge3()->setLevel(0);
  Serial.println("Init done");
}

void loop() {
    // Call in loop to update LEDs
    game->getLedController()->update();
    game->getMenuController()->update();
    //game->getNfcController()->update();
    //if (game.getNfcController()->hasCard()) {
    //  uint8_t data[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};
    //  game.getNfcController()->writeBlock(2,2,data);
    //  game.getNfcController()->readBlock(2,2);
    //}
    delay(50);
}
