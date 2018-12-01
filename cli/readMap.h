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

#ifndef readMap
#define readMap
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "../p_constants.h"

 typedef struct space {
         int res;
         int pwr;
         int type; // Actually a char
 } space;

int loadMap(space *map[M_WIDTH][M_HEIGHT], char* fileName);
void printMap(space *map[M_WIDTH][M_HEIGHT]);

#endif
