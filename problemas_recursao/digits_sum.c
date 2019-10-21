#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number_of_times = 0;

int char_to_int(char c) {
  return c - 48;
}

void g(char * array) {
  int total = 0;
  int size = strlen(array);
  for (int i = 0; i < size; ++i) {
    total += char_to_int(array[i]);
  }
  number_of_times++;
  sprintf(array, "%d", total);
}

int main(int argc, char *argv[])
{
  char array[1000000];
  scanf(" %s", array);

  while (strlen(array) > 1) g(array);
  
  printf("%s %d\n", array, number_of_times + 1);
  return 0;
}
