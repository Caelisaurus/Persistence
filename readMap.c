#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    printf("Current char: %c\n", c);
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
    }

     if(c == '\n'){ // Skips to the next line in ze file (if there is one)
	c = getchar();
      }
     
    x = 0;
    y++;
  }

  int i = 0;
  int j = 0;
  // Prints map (well... that's what we WANTED it to do)
  while(i++ < 16){
    while(j++ < 16){
      putchar(map[j][i].type);
    }
    j = 0;
    putchar('\n');
    } 
}

// We originally initialized the struct values in a separate function; we thought it may be where issues were coming from.
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
