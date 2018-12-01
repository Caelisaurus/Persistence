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
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.print("Initializing SD card...");

  pinMode(SD_PIN, OUTPUT);
  digitalWrite(SD_PIN,HIGH);
  
  if (!SD.begin(SD_PIN)) {
    Serial.println("initialization failed!");
    while(1);
  }
  Serial.println("initialization done.");

  space* mymap[M_WIDTH][M_HEIGHT];
  char* test_map = "map";

  if(loadMap(mymap, test_map) == 0) {
          printMap(pixels, mymap);
  }
  else {
          exit(1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
