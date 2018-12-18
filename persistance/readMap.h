/*
 * =====================================================================================
 *
 *       Filename:  readMap.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  11/18/2018 14:32:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#ifndef readMap_h
#define readMap_h
#include <SPI.h>
#include <SD.h>
#include <Arduino.h>
#include "p_constants.h"
#include "linkedlist.h"

extern int player_x;
extern int player_y;

typedef struct space {
        int res;
        int pwr;
        int type; // Actually a char
} space;

extern space *currentMap[M_WIDTH][M_HEIGHT]; // Currently loaded map

int loadMap(char* fileName);
int loadDefaultMap();
void printMap();
void printDirectory(File dir, int numTabs);
linkedlist* loadMapList(linkedlist* list, char* path);

#endif
