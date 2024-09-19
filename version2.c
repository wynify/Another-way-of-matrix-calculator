#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <complex.h>

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
  QuadraticEquation** data;
} Matrix;

QuadraticEquation QuadraticEquationCreate() {
  QuadraticEquation eq;
  
  eq.a = rand() % 10 + 1;                             //can't be zero
  eq.b = rand() % 21 - 10;
  eq.c = rand() % 21 - 10;
  
  eq.d = (eq.b*eq.b)-(4*eq.a*eq.c);
  if(eq.d > 0){
    eq.d = sqrt(eq.d);
    eq.r1 = (-eq.b+eq.d)/(2*eq.a);
    eq.r2 = (-eq.b-eq.d)/(2*eq.a);
  }
  return eq;  //???
}

void MatrixCreate(Matrix *m, int row, int col) {
    m->row = row;
    m->col = col;
    m->data = (QuadraticEquation **)malloc(row * sizeof(QuadraticEquation *));
    for (int i = 0; i < row; i++) {
        m->data[i] = (QuadraticEquation *)malloc(col * sizeof(QuadraticEquation));
        for (int j = 0; j < col; j++) {
            m->data[i][j] = QuadraticEquationCreate();
        }
    }
}

void MatrixPrint(Matrix *m) {
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < m->col; j++) {
            QuadraticEquation eq = m->data[i][j]; 
            printf("[%dx^2+(%d)x+(%d)=0] - {%.2f | %.2f}\n", eq.a, eq.b, eq.c, eq.r1, eq.r2);
        }
        printf("\n");
    }
}

void MatrixFree(Matrix *m) {
    for(int i = 0; i < m->row; i++)
        free(m->data[i]);
    free(m->data);
}

int main()
{
    srand(time(NULL));
    
    int row, col;
    row = 2;
    col = 2;
    
    Matrix m;
    MatrixCreate(&m, row, col);
    MatrixPrint(&m);
    MatrixFree(&m);
  return 0;
}
