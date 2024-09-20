#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <complex.h>

#include "CubicEquation.c"
#include "QuadraticEquation.c"


int main()
{
    srand(time(NULL));
    int RAND_NUM = 2;//(rand() % 10) + 1; //uses only for row and col for now
    
    int row, col;
    row = RAND_NUM;
    col = RAND_NUM;
    
    int OP;
    printf("Enter an OP-Code for generation:\n1 - Quadratic Equation's\n2 - Cubic Equation's\n3 - Both\n\n");
    scanf("%d", &OP);

    QuadraticEquationMatrix qem;
    CubicEquationMatrix cem;
    switch (OP)
    {
    case 1:
      QuadraticEquatioMatrixCreate(&qem, row, col);
      QuadraticEquatioMatrixPrint(&qem);
      QEMatrixFree(&qem);
      break;
    case 2:
      CubicEquationMatrixCreate(&cem, row, col);
      CubicEquationMatrixPrint(&cem);
      CEMatrixFree(&cem);
      break;
    case 3:
      QuadraticEquatioMatrixCreate(&qem, row, col);
      QuadraticEquatioMatrixPrint(&qem);
      QEMatrixFree(&qem);

      CubicEquationMatrixCreate(&cem, row, col);
      CubicEquationMatrixPrint(&cem);
      CEMatrixFree(&cem);
      break;
    }
  return 0;
}
