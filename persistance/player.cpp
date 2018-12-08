#include "readMap.h"

// Moves player and handles all logic related to moving the player
int movePlayer(space *mapData[M_WIDTH][M_HEIGHT], int mv_x, int mv_y){
//    if(player_x + mv_x < 0 || player_x + mv_x > M_WIDTH || player_y + mv_y < 0 || player_y + mv_y > 0){
//        Serial.println("WARNING: Attempted to move player outside boundry");
//        return 1;
//    }

//    space *player = mapData[player_x][player_y];
//    space *moveTo = mapData[player_x + mv_x][player_y + mv_y];
    space *temp = malloc(sizeof(space));
    
    switch(mapData[player_x + mv_x][player_y + mv_y]->type) {
    // Air
    case ' ':
            temp = mapData[player_x + mv_x][player_y + mv_y];
            mapData[player_x + mv_x][player_y + mv_y] = mapData[player_x][player_y];
            mapData[player_x][player_y] = temp;
            player_x = player_x + mv_x;
            player_y = player_y + mv_y;
            break;
    // Wall
    case '#':
            // Do wall things (seprate function)
            break;
    default:
            break;
    }
    return 0;
}
