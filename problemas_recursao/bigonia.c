#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int x;
  int y;
} position;

position up(position pos) {
  pos.x--;
  return pos;
}

position down(position pos) {
  pos.x++;
  return pos;
}

position left(position pos) {
  pos.y--;
  return pos;
}

position right(position pos) {
  pos.y++;
  return pos;
}


void print_array(char ** array, int size) {
  int i, j;
  for (i = 0; i < size; ++i) {
    for (j = 0; j < size; ++j) {
      printf("%c", array[i][j]);
    }
    printf("\n");
  }
}

char get_c(char ** array, position pos) {
  return array[pos.x][pos.y];
}

void infect_pos(char ** array, position pos) {
  array[pos.x][pos.y] = 'x';
}

bool is_water(char ** array, position pos) {
  if (get_c(array, pos) == '.') return true;
  return false;
}

bool is_top_row(position pos, int size) {
  if (pos.x == 0) return true;
  return false;
}

bool is_right_row(position pos, int size) {
  if (pos.y == size - 1) return true;
  return false;
}

bool is_bottom_row(position pos, int size) {
  if (pos.x == size - 1) return true;
  return false;
}

void infect_away(char ** array, position pos, int size) {
  infect_pos(array, pos);
  if (!is_top_row(pos, size)) {
    if (is_water(array, up(pos))) infect_away(array, up(pos), size);  
  }
  if (!is_bottom_row(pos, size)) {
    if (is_water(array, down(pos))) infect_away(array, down(pos), size);    
  }
  if (is_water(array, left(pos))) infect_away(array, left(pos), size);
  if (!is_right_row(pos, size)) {
    if (is_water(array, right(pos))) infect_away(array, right(pos), size);    
  }
  else return;
} 

int main(int argc, char *argv[])
{
  int N, lat, heit;
  position ground_zero;
  scanf("%d", &N);

  char ** array;
  array = (char**) malloc (N * sizeof(char*));
  for (int i = 0; i < N; ++i) array[i] = (char*) malloc (N * sizeof(char));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++ j) {
     scanf(" %c", &array[i][j]);
    }
  }
  
  scanf("%d %d", &lat, &heit);
  ground_zero.x = lat;
  ground_zero.y = heit;

  infect_away(array, ground_zero, N);

  print_array(array, N);
  
  return 0;
}
