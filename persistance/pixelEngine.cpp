#include "pixelEngine.h"

int interpolate(int startValue, int endValue, int stepNumber, int lastStepNumber){
    return (endValue - startValue) * stepNumber / lastStepNumber + startValue;
}

// Gets the value of a color calclulated from an intensity percentage value.
ledcolor getColorValue(int r, int g, int b, double intsy){
        r = round((double)r*intsy);
        g = round((double)g*intsy);
        b = round((double)b*intsy);
        return {r, g, b};
        //return pixels.Color(r, g, b);
}

// Gets the color from a map tile x, y. Gets the color with an intensity between 0-100.
// Color is set in p_constants
ledcolor getColor(space *mapData[M_WIDTH][M_HEIGHT], int x, int y, int intsy) {
        double intsyCalc = (double)intsy/100;
        switch(mapData[x][y]->type) {
                // Air
                case ' ':
                        return getColorValue(AIR_R, AIR_G, AIR_B, intsyCalc);
                // Wall
                case '#':
                        // Interpolate between wall colors based on wall's resistance
                        return getColorValue(
                          interpolate(WALL_R_DMG, WALL_R, mapData[x][y]->res, WALL_RES),
                          interpolate(WALL_G_DMG, WALL_G, mapData[x][y]->res, WALL_RES),
                          interpolate(WALL_B_DMG, WALL_B, mapData[x][y]->res, WALL_RES), 
                          intsyCalc);
                // Player
                case '@':
                        return getColorValue(PLYR_R, PLYR_G, PLYR_B, intsyCalc);
                case '!':
                        return getColorValue(EXIT_R, EXIT_G, EXIT_B, intsyCalc);
         }
}

// Calculate the location of a pixel for setPixelColor using x and y values. x and y start at index 0 and go to M_WIDTH-1 and M_HEIGHT-1.
int calcPixel(int x, int y) {
  /*
        if(x >= M_WIDTH || y >= M_HEIGHT) {
                Serial.print("Error: calcPixel() tried to find a pixel outside the map size");
                exit(1);
        }
        if(y%2 > 0){
          y = abs(y - 15);
        }
        return (y*M_HEIGHT)+x;
        */
   int pos;
   if(x >= M_WIDTH || y >= M_HEIGHT) {
          Serial.print("Error: calcPixel() tried to find a pixel outside the map size");
          while(1);
   }
   if(x%2 > 0) { // is X odd
      pos = x * M_WIDTH + (M_WIDTH -1 - y) ;
   } else { // x is even
      pos = x * M_WIDTH + y;
   }
   return pos;
}

void printMap(Adafruit_NeoPixel pixels, space *mapData[M_WIDTH][M_HEIGHT]){
        for(int y = 0; y < M_HEIGHT; y++){
                for(int x = 0; x < M_WIDTH; x++){
                        ledcolor color = getColor(mapData, x, y, 10);
                        pixels.setPixelColor(calcPixel(x, y), pixels.Color(color.r, color.g, color.b));
                        char printOut = mapData[x][y]->type;
                        Serial.print(printOut);
                }
                Serial.print("\n");
        }
        pixels.begin();
        pixels.show();
}
