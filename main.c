#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <complex.h>

#include "CubicEquation.c"
#include "QuadraticEquation.c"
#include "xn.c"


int main()
{
    srand(time(NULL));
    int RAND_NUM = 2;//(rand() % 10) + 1; //uses only for row and col for now 2;//
    
    int row, col;
    row = RAND_NUM;
    col = RAND_NUM;
    
    int n;

    int OP;
    printf("Enter an OP-Code for generation:\n1 - Quadratic Equation's\n2 - Cubic Equation's\n3 - Both\n4 - Polinom x^n\n\n");
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
    case 4:
      printf("Enter an x^n for polinom: ");
      scanf("%d", &n);
      XN(n);
    }
  return 0;
}
