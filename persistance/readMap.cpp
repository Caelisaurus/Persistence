#include "readMap.h"

int player_x = 0;
int player_y = 0;

// static struct space global_map[M_WIDTH][M_HEIGHT];

//int main() {
//        space *mymap[M_WIDTH][M_HEIGHT];
//        char* test_map = "../maps/test_map";
//
//        if(loadMap(mymap, test_map) == 0) {
//                printMap(mymap);
//        }
//        else {
//                exit(1);
//        }
//}

int loadMap(space *mapData[M_WIDTH][M_HEIGHT], char* path){
        int x = 0;
        int y = 0;
        player_x = 0;
        player_y = 0;
        int c;
        File mapFile = SD.open(path);
          
          // This SD library is dumb and this wasn't working so now hopefully whoever is using this is using the right filenames
//        if(mapFile = SD.open(path)) {
//                Serial.println("Error: Map file failed to load");
//                while(1);
//        }

        // Reads in the map file line by line
        while(mapFile.available()) {
                c = mapFile.read();
                if(c == '\n') { // Skips to the next line in ze file (if there is one)
                        x = 0;
                        y++;
                        continue;
                }
		
		            mapData[x][y] = malloc(sizeof(space));

                mapData[x][y]->type = c;

                // Sets struct values based on character read in
                switch(c) {
                // Air
                case ' ':
                        mapData[x][y]->res = AIR_RES;
                        mapData[x][y]->pwr = AIR_PWR;
                        break;
                // Wall
                case '#':
                        mapData[x][y]->res = WALL_RES;
                        mapData[x][y]->pwr = WALL_PWR;
                        break;
                // Player
                case '@':
                        mapData[x][y]->res = PLYR_PWR;
                        mapData[x][y]->pwr = PLYR_RES;
                        player_x = x;
                        player_y = y;
                        break;
		// Exit
		case '!':
                        mapData[x][y]->res = EXIT_RES;
                        mapData[x][y]->pwr = EXIT_PWR;
                        break;
                default:
                        break;
                }

                x++;
        }

        mapFile.close();
        return 0;
}

int loadDefaultMap(space *mapData[M_WIDTH][M_HEIGHT]){
        char* defaultMap = "################\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#@             #\n################";
        int x = 0;
        int y = 0;
        player_x = 0;
        player_y = 0;
        int c;

        // Reads in the map file line by line
        int len = strlen(defaultMap);
        for(int i = 0; i < len; i++){
                c = defaultMap[i];
                if(c == '\n') { // Skips to the next line in ze file (if there is one)
                        x = 0;
                        y++;
                        continue;
                }
    
                mapData[x][y] = malloc(sizeof(space));

                mapData[x][y]->type = c;

                // Sets struct values based on character read in
                switch(c) {
                // Air
                case ' ':
                        mapData[x][y]->res = AIR_RES;
                        mapData[x][y]->pwr = AIR_PWR;
                        break;
                // Wall
                case '#':
                        mapData[x][y]->res = WALL_RES;
                        mapData[x][y]->pwr = WALL_PWR;
                        break;
                // Player
                case '@':
                        mapData[x][y]->res = PLYR_PWR;
                        mapData[x][y]->pwr = PLYR_RES;
                        player_x = x;
                        player_y = y;
                        break;
                default:
                        break;
                }

                x++;
        }
        return 0;
}
