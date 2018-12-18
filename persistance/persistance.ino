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

node* currentMapNode;

linkedlist *mapList;

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
    loadDefaultMap();
    printMap(pixels);
  }
  else {
    Serial.println("initialization done.");
    Serial.println("Loading maps...");

    mapList = newLinkedlist();

    mapList = loadMapList(mapList, MAP_DIR);

    Serial.println("Maps loaded:");
    File root = SD.open(MAP_DIR);
    printDirectory(root, 0);

    currentMapNode = mapList->head;
  }
}

void loop() {
  int joy_x = 0;
  int joy_y = 0;
  int joy_btn = 0;
  int x = 0;
  int y = 0;
  Serial.print("Loading map ");
  currentMapNode = currentMapNode->next;
  Serial.println(currentMapNode->path);
  if(loadMap(strcat(MAP_DIR, currentMapNode->path)) == 0) {
          Serial.println("Loaded...");
          delay(1000);
          Serial.println("Started...");
          printMap(pixels);
  }
  while(1){
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
            if(movePlayer(x, y) == 1){
                break;
            }
            if(x != 0 || y != 0)
              printMap(pixels);
            delay(100); // TODO: Dynamic movement speed

  }
}
