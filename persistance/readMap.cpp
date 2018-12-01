#include "readMap.h"

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
        int c;
        File mapFile;
        
        if(mapFile = SD.open(path)) {
                Serial.println("Error: Map file failed to load");
                while(1);
        }

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
                        break;
                }

                x++;
        }

        mapFile.close();
        return 0;
}
