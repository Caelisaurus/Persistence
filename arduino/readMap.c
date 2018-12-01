#include "readMap.h"

// static struct space global_map[M_WIDTH][M_HEIGHT];

int main() {
        space *map[M_WIDTH][M_HEIGHT];
        char* test_map = "../maps/test_map";

        if(loadMap(map, test_map) == 0) {
                printMap(map);
        }
        else {
                exit(1);
        }
}

int loadMap(space *map[M_WIDTH][M_HEIGHT], char* path){
        int x = 0;
        int y = 0;
        int c;
        FILE *mapFile;

        if((mapFile = fopen(path, "r")) == NULL) {
                fprintf(stderr, "Error: Map file failed to load: %s", path);
                return 1;
        }

        // Reads in the map file line by line
        while((c = fgetc(mapFile)) != EOF) {
                if(c == '\n') { // Skips to the next line in ze file (if there is one)
                        x = 0;
                        y++;
                        continue;
                }
		
		map[x][y] = malloc(sizeof(space));

                map[x][y]->type = c;

                // Sets struct values based on character read in
                switch(c) {
                // Air
                case ' ':
                        map[x][y]->res = AIR_RES;
                        map[x][y]->pwr = AIR_PWR;
                        break;
                // Wall
                case '#':
                        map[x][y]->res = WALL_RES;
                        map[x][y]->pwr = WALL_PWR;
                        break;
                // Player
                case '@':
                        map[x][y]->res = PLYR_PWR;
                        map[x][y]->pwr = PLYR_RES;
                        break;
                }

                x++;
        }

        fclose(mapFile);
        return 0;
}

void printMap(space *map[M_WIDTH][M_HEIGHT]){
        int i = 0;
        int j = 0;
        // Prints map (well... that's what we WANTED it to do)
        while(i < 16) {
                while(j < 16) {
                        putchar(map[j][i]->type);
                        j++;
                }
                putchar('\n');
                i++;
                j = 0;
        }
}
