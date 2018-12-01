#ifndef pixelEngine_h
#define pixelEngine_h

#include <SPI.h>
#include <SD.h>
#include "p_constants.h"
#include "readMap.h"
#include <Adafruit_NeoPixel.h>

typedef struct ledcolor {
        int r;
        int g;
        int b;
} ledcolor;

// Gets the value of a color calclulated from an intensity percentage value.
ledcolor getColorValue(int r, int g, int b, float intsy);

// Gets the color from a map tile x, y. Gets the color with an intensity between 0-100.
// Color is set in p_constants
ledcolor getColor(space *mapData[M_WIDTH][M_HEIGHT], int x, int y, int intsy);

// Calculate the location of a pixel for setPixelColor using x and y values. x and y start at index 0 and go to M_WIDTH-1 and M_HEIGHT-1.
int calcPixel(int x, int y);

void printMap(Adafruit_NeoPixel pixels, space *mapData[M_WIDTH][M_HEIGHT]);

#endif
