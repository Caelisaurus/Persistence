/*
 * =====================================================================================
 *
 *       Filename:  persistance.ino
 *
 *    Description:  The initilization program for the Persistance Game
 *
 *        Version:  0.1 ALPHA
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */
#include "persistance.h"

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(M_WIDTH * M_HEIGHT, MATRIX_PIN, NEO_GRB + NEO_KHZ800);

space *currentMap[M_WIDTH][M_HEIGHT]; // Currently loaded map

void setup() {
  // Initialize LED Matrix
  pixels.begin();

  // Initialize SD card
  // TODO: See if we need this or maybe make it detect when we are not using USB
  Serial.begin(2000000);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  pinMode(SD_PIN, OUTPUT);
  pinMode(JOYSTICK_PIN_BTN, INPUT);
  digitalWrite(SD_PIN,HIGH);
  digitalWrite(JOYSTICK_PIN_BTN, HIGH);

  if (!SD.begin(SD_PIN)) {
    Serial.println("initialization failed!\nloading default map");
    loadDefaultMap(currentMap);
    printMap(pixels, currentMap);
  }
  else {
    Serial.println("initialization done.");
  
    char* test_file = "test_map";
  
    if(loadMap(currentMap, test_file) == 0) {
            printMap(pixels, currentMap);
    }
    else {
            exit(1);
    }
  }
}

void loop() {
  int joy_x = 0;
  int joy_y = 0;
  int joy_btn = 0;
  int x = 0;
  int y = 0;
  while(movePlayer(currentMap, x, y) == 0){
            x=0;
            y=0;
            joy_x = analogRead(JOYSTICK_PIN_X);
            joy_y = analogRead(JOYSTICK_PIN_Y);
            if(joy_x < 300)
              x = -1;
            if(joy_x > 800)
              x = 1;
            if(joy_y < 300)
              y = -1;
            if(joy_y > 800)
              y = 1;
            if(x != 0 || y != 0)
              printMap(pixels, currentMap);
            delay(100); // TODO: Dynamic movement speed

  }
}
