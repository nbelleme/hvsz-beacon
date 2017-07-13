#include "NfcController.h"
#include <PN532.h>
#include <SPI.h>

#define PN532_CS 53

#define  DEBUG 1
#define  NFC_DEMO_DEBUG 0

NfcController::NfcController() {
  this->nfc = new PN532(PN532_CS);
  this->cb = this;
  this->lastHasCard = false;
}

void NfcController::begin() {
#ifdef DEBUG
  Serial.println("Starting NFC Controller!");
#endif
  this->nfc->begin();
  uint32_t versiondata = this->nfc->getFirmwareVersion();
  if (! versiondata) {
#ifdef DEBUG
    Serial.print("Didn't find PN53x board");
#endif
    while (1); // halt
  }
#ifdef DEBUG
  // Got ok data, print it out!
  Serial.print("Found chip PN5");
  Serial.println((versiondata>>24) & 0xFF, HEX);
  Serial.print("Firmware ver. ");
  Serial.print((versiondata>>16) & 0xFF, DEC);
  Serial.print('.');
  Serial.println((versiondata>>8) & 0xFF, DEC);
  Serial.print("Supports ");
  Serial.println(versiondata & 0xFF, HEX);
#endif
  // Configure board to read RFID tags and cards
  this->nfc->SAMConfig();
}


void NfcController::update() {
  boolean hasCardNow = this->hasCard();
  if (!this->lastHasCard && hasCardNow) {
    // We have just detected a card
    this->lastHasCard = true;
    this->cb->onCardIn();
  } else if (this->lastHasCard && hasCardNow) {
    // Card was already in.
    this->cb->onCardHold();
  } else if (this->lastHasCard && !hasCardNow) {
    // Card was just removed
    this->lastHasCard = false;
    this->cb->onCardOut();
  }
}

boolean NfcController::hasCard() {
  return this->nfc->readPassiveTargetID(PN532_MIFARE_ISO14443A) != 0;
}

boolean NfcController::authenticateBlock(uint8_t blockn) {
  uint32_t id = nfc->readPassiveTargetID(PN532_MIFARE_ISO14443A);
  boolean authenticated = this->nfc->authenticateBlock(1, id, blockn, KEY_A, this->keys);
  // Authenticate block blockn
  if(!authenticated) {
    // If authentication failed
#ifdef DEBUG
    Serial.println("Error during block authentication");
#endif
  }
  return authenticated;
}

uint8_t*  NfcController::readBlock(uint8_t sector, uint8_t blockNumber) {
  uint8_t blockn = (sector * 4) + blockNumber;
  uint8_t* block = new uint8_t[16];
  if (!this->authenticateBlock(blockn)) {
    return block;
  }
  // If authentication successful read memory block blockn
  if(!this->nfc->readMemoryBlock(1,blockn,block)) {
    // If read failed
#ifdef DEBUG
    Serial.println("Error reading block");
    return block;
#endif
  }
  // If read successful
#ifdef DEBUG
  for(uint8_t i=0;i<16;i++) {
    // Print memory block
    Serial.print(block[i],HEX);
    // Data arrangement / beautify
    if(block[i] <= 0xF) {
      Serial.print("  ");
    } else {
      Serial.print(" ");
    }
  }
  Serial.print("| Block ");
  // Data arrangement / beautify
  if(blockn <= 9) {
    Serial.print(" ");
  }
  Serial.print(blockn,DEC);
  Serial.print(" | ");
  if(blockn == 0) {
    Serial.println("Manufacturer Block");
  } else {
    if(((blockn + 1) % 4) == 0) {
      Serial.println("Sector Trailer");
    } else {
      Serial.println("Data Block");
    }
  }
#endif
  return block;
}

void NfcController::writeBlock(uint8_t sector, uint8_t blockNumber, uint8_t data[16]) {
  if (blockNumber == 3) {
    // Protection to forbid change card access-bits
    return;
  }
  uint8_t blockn = (sector * 4) + blockNumber;
  boolean written = false;
  if (!this->authenticateBlock(blockn)) {
    return;
  }
  // Write data[] to block blockn
  written = nfc->writeMemoryBlock(1, blockn, data);
#ifdef DEBUG
  if(written) {
    Serial.println("Write Successful");
  } else {
    Serial.println("Write failed");
  }
#endif
}

void NfcController::onCardIn() {
#ifdef DEBUG
  Serial.println("Card plugged in");
#endif
}
void NfcController::onCardHold() {
#ifdef DEBUG
  Serial.println("Card still here");
#endif
}
void NfcController::onCardOut() {
#ifdef DEBUG
  Serial.println("Card removed");
#endif
}

void NfcController::setNfcCallbacks(NfcCallbacks& cb) {
  this->cb = &cb;
}
