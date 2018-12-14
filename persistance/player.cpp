#include "readMap.h"

// Moves player and handles all logic related to moving the player
int movePlayer(space *mapData[M_WIDTH][M_HEIGHT], int mv_x, int mv_y){

    // Make the player teleport to the other side of the map at the map boundries
    if(player_x + mv_x >= M_WIDTH){
      // Teleport from the upper X boundry
      mv_x = -M_WIDTH + 1;
    }
    if(player_x + mv_x < 0){
      // Teleport from the lower X boundry
      mv_x = M_WIDTH - 1;
    }
    if(player_y + mv_y >= M_HEIGHT){
      // Teleport from the upper Y boundry
      mv_y = -M_HEIGHT + 1;
    }
    if(player_y + mv_y < 0){
      // Teleport from the lower Y boundry
      mv_y = M_HEIGHT - 1;
    }
    
    space *temp = malloc(sizeof(space));
    
    switch(mapData[player_x + mv_x][player_y + mv_y]->type) {
    // Air
    case ' ':
            // Swap the player with the air
            temp = mapData[player_x + mv_x][player_y + mv_y];
            mapData[player_x + mv_x][player_y + mv_y] = mapData[player_x][player_y];
            mapData[player_x][player_y] = temp;
            player_x = player_x + mv_x;
            player_y = player_y + mv_y;
            break;
    // Wall
    case '#':
            // Wall Logic
            if(mapData[player_x + mv_x][player_y + mv_y]->res > 0){
              // If the wall still has resistance, then subtract resistance based on player power
              mapData[player_x + mv_x][player_y + mv_y]->res = mapData[player_x + mv_x][player_y + mv_y]->res - PLYR_PWR;
            }
            else {
              // Else set the wall to air (or otherwise: destroy the wall)
              mapData[player_x + mv_x][player_y + mv_y]->type = ' ';
              mapData[player_x + mv_x][player_y + mv_y]->res = AIR_RES;
              mapData[player_x + mv_x][player_y + mv_y]->pwr = AIR_PWR;
            }
            break;
    default:
            break;
    }
    return 0;
}
