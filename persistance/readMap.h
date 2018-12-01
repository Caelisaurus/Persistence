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
#include "p_constants.h"

 typedef struct space {
         int res;
         int pwr;
         int type; // Actually a char
 } space;

int loadMap(space *mapData[M_WIDTH][M_HEIGHT], char* fileName);
void printMap(space *mapData[M_WIDTH][M_HEIGHT]);

#endif
