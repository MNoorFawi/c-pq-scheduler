#include <stdio.h>
#include <stdlib.h>

void print_array(int * array, size_t len) {
  puts("\n\tPrinting list in C");
  printf("\n\tLength of list is: %i\n", len);
  puts("\tList elements are: ");
  int i;
  for (i = 0; i < len; i++)
    printf("\t%i", array[i]);
  printf("\n");
}

void main(int argc, char * argv[]) {
  FILE * input = fopen(argv[1], "r");
  int number, val;
  int iter = 0;
  int b = 10; // initial capacity
  int * number_array = (int * ) malloc(b * sizeof(int));

  while (fscanf(input, "%i", & number) == 1) {

    if (iter >= b) {
      b = iter + 1; // new capacity to reallocate
      number_array = (int * ) realloc(number_array, sizeof(int) * b);
    }
    number_array[iter] = number;
    iter++;
  }
  fclose(input);

  print_array(number_array, b);
}