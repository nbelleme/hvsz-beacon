# Arduino Module
This folder contains the main source code for Arduino.

So far, here is the work that has been achieved:

 * Led Control is fully operational and configurable
 * Menu Control is finished.
 * NFC Control is functional, but no business-logic implemented yet.

Here are the next steps:
 * Implement menu control specifics: what happens when settings are changed, + Global IP configuration
 * Implement ESP-8266 and MQTT Messaging once server is set. Connect to remote server, wait to receive message.
 * Implement Game start and global game logic in HumanBeaconGameController.
 * Implement other game logics for ZombieBeacon and FoodSupplyBeacon

Here is what has been forgotten for now:
 * SD-Card persistence (for settings)
 * Speaker communication


TODO: add schematics, board specifics, configuration, power supply, external libraries etc...


## Environment
You need to install:  
 * the latest Arduino IDE
 * FastLed Library (tested with 3.1.3)
 * LiquidCrystal_I2C (tested with 1.1.0)
 * [Button Library](https://github.com/JChristensen/Button) (tested with 1.0)
 * [ITead NFC PN532 Lib](ftp://imall.iteadstudio.com/Modules/IM130625002_ITEAD_PN532_NFC/Library_Arduino_PN532_SPI_V2.zip)
