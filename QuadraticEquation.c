#include <stdio.h>


typedef struct{
    int a;
    int b;
    int c;
    float r1;
    float r2;
    double d;
    double realPart;
    double imagPart;
} QuadraticEquation;

typedef struct{
  int row;
  int col;
  QuadraticEquation** QEdata;
} QuadraticEquationMatrix;

QuadraticEquation QuadraticEquationCreate() {
  QuadraticEquation eq;
  
  eq.a = rand() % 10 + 1;                             //can't be zero
  eq.b = rand() % 21 - 10;
  eq.c = rand() % 21 - 10;
  
  eq.d = (eq.b*eq.b)-(4*eq.a*eq.c);
  if(eq.d >= 0){
    eq.d = sqrt(eq.d);
    eq.r1 = (-eq.b-eq.d)/(2*eq.a);
    eq.r2 = (-eq.b+eq.d)/(2*eq.a);
  } else  {
    eq.r1 = eq.r2 = NAN;
  }
  return eq;
}

void QuadraticEquatioMatrixCreate(QuadraticEquationMatrix *qem, int row, int col) {
    qem->row = row;
    qem->col = col;
    qem->QEdata = (QuadraticEquation **)malloc(row * sizeof(QuadraticEquation *));
    for (int i = 0; i < row; i++) {
        qem->QEdata[i] = (QuadraticEquation *)malloc(col * sizeof(QuadraticEquation));
        for (int j = 0; j < col; j++) {
            qem->QEdata[i][j] = QuadraticEquationCreate();
        }
    }
}

void QuadraticEquatioMatrixPrint(QuadraticEquationMatrix *qem) {
    for (int i = 0; i < qem->row; i++) {
        for (int j = 0; j < qem->col; j++) {
            QuadraticEquation eq = qem->QEdata[i][j]; 
            printf("[%dx^2+(%d)x+(%d)=0] - {%.2f | %.2f}\n", eq.a, eq.b, eq.c, eq.r1, eq.r2);
        }
        printf("\n");
    }
}
void QEMatrixFree(QuadraticEquationMatrix *eqm) {
    for(int i = 0; i < eqm->row; i++)
        free(eqm->QEdata[i]);
    free(eqm->QEdata);
}
