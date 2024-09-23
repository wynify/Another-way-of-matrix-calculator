#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <complex.h>

#include "ui.c"
#include "matrix_calculator_upd.c"


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


/*
#include "CubicEquation.c"
#include "QuadraticEquation.c"
#include "xn.c"

    int n;

    int OP;
    printf("Enter an OP-Code for generation:\n1 - Quadratic Equation's\n2 - Cubic Equation's\n3 - Both\n4 - Polinom x^n\n5 - [NEW] Enter to MatrixCalculator(UPD 23.09.24)\t *Only ADD matrix for now. I work an update ;)\n\n");
    
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
      break;
    case 5:
      EXPECT_MATRIX(row, col);
      break;
    }
*/

  return 0;
}
