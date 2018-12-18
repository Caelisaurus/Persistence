#include "readMap.h"

int player_x = 0;
int player_y = 0;
space *currentMap[M_WIDTH][M_HEIGHT];

int loadMap(char* path){
        int x = 0;
        int y = 0;
        player_x = 0;
        player_y = 0;
        int c;
        File mapFile = SD.open(path);

        // This SD library is dumb and this wasn't working so now hopefully whoever is using this is using the right filenames

        // Reads in the map file line by line
        mapFile.seek(0);
        while(mapFile.available()) {
                c = mapFile.read();
                if(c == '\n') { // Skips to the next line in ze file (if there is one)
                        x = 0;
                        y++;
                        continue;
                }

                if(currentMap[x][y] == NULL)
		              currentMap[x][y] = malloc(sizeof(space));

                currentMap[x][y]->type = c;

                // Sets struct values based on character read in
                switch(c) {
                // Air
                case ' ':
                        currentMap[x][y]->res = AIR_RES;
                        currentMap[x][y]->pwr = AIR_PWR;
                        break;
                // Wall
                case '#':
                        currentMap[x][y]->res = WALL_RES;
                        currentMap[x][y]->pwr = WALL_PWR;
                        break;
                // Player
                case '@':
                        currentMap[x][y]->res = PLYR_PWR;
                        currentMap[x][y]->pwr = PLYR_RES;
                        player_x = x;
                        player_y = y;
                        break;
        		// Exit
        		case '!':
                        currentMap[x][y]->res = EXIT_RES;
                        currentMap[x][y]->pwr = EXIT_PWR;
                        break;
                default:
                        Serial.println("Warning: Unknown object in map");
                        break;
                }

                x++;
        }

        mapFile.close();
        return 0;
}

int loadDefaultMap(){
        //char* defaultMap = "################\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#              #\n#@             #\n################";
        char* defaultMap = "#  #  ##        \n## # #  #       \n# ## #  #       \n#  #  ##        \n                \n                \n ### ###        \n#    #  #       \n ##  #  #       \n   # #  #       \n###  ###        \n                \n                \n                \n                \n@               ";
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

                currentMap[x][y] = malloc(sizeof(space));

                currentMap[x][y]->type = c;

                // Sets struct values based on character read in
                switch(c) {
                // Air
                case ' ':
                        currentMap[x][y]->res = AIR_RES;
                        currentMap[x][y]->pwr = AIR_PWR;
                        break;
                // Wall
                case '#':
                        currentMap[x][y]->res = WALL_RES;
                        currentMap[x][y]->pwr = WALL_PWR;
                        break;
                // Player
                case '@':
                        currentMap[x][y]->res = PLYR_PWR;
                        currentMap[x][y]->pwr = PLYR_RES;
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

void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}

linkedlist* loadMapList(linkedlist* list, char* path) {
  File dir = SD.open(path);
  char* name;

  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    if (!entry.isDirectory()) {
      insertTail(list, entry.name());
    }
    entry.close();
  }
  dir.close();
  return list;
}
