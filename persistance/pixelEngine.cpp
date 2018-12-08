#include "pixelEngine.h"

// Gets the value of a color calclulated from an intensity percentage value.
ledcolor getColorValue(int r, int g, int b, float intsy){
        r = round((float)r*intsy);
        g = round((float)g*intsy);
        b = round((float)b*intsy);
        return {r, g, b};
        //return pixels.Color(r, g, b);
}

// Gets the color from a map tile x, y. Gets the color with an intensity between 0-100.
// Color is set in p_constants
ledcolor getColor(space *mapData[M_WIDTH][M_HEIGHT], int x, int y, int intsy) {
        float intsyCalc = intsy/100;
        switch(mapData[x][y]->type) {
                // Air
                case ' ':
                        return getColorValue(AIR_R, AIR_G, AIR_B, intsyCalc);
                // Wall
                case '#':
                        return getColorValue(WALL_R, WALL_G, WALL_B, intsyCalc);
                // Player
                case '@':
                        return getColorValue(PLYR_R, PLYR_G, PLYR_B, intsyCalc);
         }
}

// Calculate the location of a pixel for setPixelColor using x and y values. x and y start at index 0 and go to M_WIDTH-1 and M_HEIGHT-1.
int calcPixel(int x, int y) {
        if(x >= M_WIDTH || y >= M_HEIGHT) {
                Serial.print("Error: calcPixel() tried to find a pixel outside the map size");
                exit(1);
        }
        return (y*M_HEIGHT)+x;
}

void printMap(Adafruit_NeoPixel pixels, space *mapData[M_WIDTH][M_HEIGHT]){
        for(int x = 0; x < M_WIDTH; x++){
                for(int y = 0; y < M_HEIGHT; y++){
                        ledcolor color = getColor(mapData, x, y, 100);
                        pixels.setPixelColor(calcPixel(x, y), pixels.Color(color.r, color.g, color.b));
                        char printOut = mapData[x][y]->type;
                        Serial.print(printOut);
                }
                Serial.print("\n");
        }
        pixels.show();
}
