#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

typedef struct{
    int a;
    int b;
    int c;
    double d;
    double r1;
    double r2;
} QuadraticEquation;

typedef struct{
  int row;
  int col;
  QuadraticEquation** data;
} Matrix;


QuadraticEquation QuadraticEquationCreate() {
  QuadraticEquation eq;
  
  eq.a = rand() % 10 + 1;  //can't be zero
  eq.b = rand() % 21 - 10;
  eq.c = rand() % 21 - 10;
  
  eq.d = (eq.b*eq.b)-(4-eq.a*eq.c);
  if(eq.d >= 0){
    eq.d = sqrt(eq.d);
    eq.r1 = (-eq.b-eq.d)/(2*eq.a);
    eq.r2 = (-eq.b+eq.d)/(2*eq.a);
  } else  {
    eq.r1 = eq.r2 = NAN;
  }
  
  return eq;
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

void MatrixPrint(Matrix *m)
{
    for(int i = 0; i < m->row; i++){
        for(int j = 0; j < m->col; j++){
            QuadraticEquation eq = m->data[i][j];
            printf("[%dx^2+%dx+%d=0]\t{Root1:%.2lf|Root2:%.2lf}\n", eq.a, eq.b, eq.c, eq.r1, eq.r2);
        }printf("\n");
    }//printf("Root1: %d\tRoot2: %d", eq.r1, eq.r2);
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
    row = rand()%10;
    col = rand()%10;
    
    Matrix m;
    MatrixCreate(&m, row, col);
    MatrixPrint(&m);
    MatrixFree(&m);
  return 0;
}
