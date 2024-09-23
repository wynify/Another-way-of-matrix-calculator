#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <complex.h>

#include "ui.c"



int main()
{
  srand(time(NULL));
  int RAND_NUM = 2;//(rand() % 10) + 1; //uses only for row and col for now 2;//
    
  int row, col;
  int OP;
  int n;
  row = RAND_NUM;
  col = RAND_NUM;

  Menu(row, col, OP, n);

  return 0;
}
