#include <stdio.h>
#include <stdlib.h>

struct space{
    int res;
    int pwr;
    char type;
  };

static struct space map[16][16];

// void init_space(struct space map[16][16], int x, int y);

int main(){
  int x = 0;
  int y = 0;
  int c = getchar();

  // Reads in the map file line by line
  while(c != EOF){
    while((c != '\n') && (c != EOF)){
      map[x][y] = (struct space){0, 0, c};
      // map[x][y].type = c;

      // Sets struct values based on character read in
      if(map[x][y].type == ' '){
	map[x][y].res = 0;
	map[x][y].pwr = 0;
      } else if(map[x][y].type == '#'){
	map[x][y].res = 250;
	map[x][y].pwr = 0;
      } else if(map[x][y].type == '@'){
	map[x][y].res = 0;
	map[x][y].pwr = 10;
      }

      x++;
      if(c == '\n'){
	c = getchar();
      }
    }
    ++y;
  }

  int i = 0;
  int j = 0;
  // Prints map (well... that's what we WANTED it to do)
  while(i < 15){
    while(j < 15){
      putchar(map[j][i].type);
      j++;
    }
    i++;
    j = 0;
    putchar('\n');
  }  
}

/*void init_space(struct space map[][], int x, int y){  
  if(map[x][y].type == ' '){
    map[x][y].res = 0;
    map[x][y].pwr = 0;
  } else if(map[x][y].type == '#'){
    map[x][y].res = 250;
    map[x][y].pwr = 0;
  } else if(map[x][y].type == '@'){
    map[x][y].res = 0;
    map[x][y].pwr = 10;
  } 
  }*/
