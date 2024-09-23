#include <stdio.h>
#include <math.h>
#include <complex.h>

#define PI 3.14

typedef struct {
    double a;
    double b;
    double c;
    double d;
    
    double p;
    double q;
    
    double Discriminant;
    double u;
    double v;
    
    double rr;
    double real_root1;
    double real_root2;
    double real_root3;
} CubicEquation;

typedef struct{
  int row;
  int col;
  CubicEquation** CEdata;
} CubicEquationMatrix;


CubicEquation CubicEquationCreate(){
    CubicEquation ce;
    
/*=============DEBUG=============
    ce.a = 1;               
    ce.b = -12;
    ce.c = 48;
    ce.d = -64;
=============DEBUG=============*/
    ce.a = (rand() % 100) + 1; // a should not be zero
    ce.b = (rand() % 200) - 100; // Range from -100 to 99
    ce.c = (rand() % 300) - 150; // Range from -150 to 149
    ce.d = (rand() % 400) - 200; // Range from -200 to 199
    
    return ce;
}

void CubicEquationMatrixCreate(CubicEquationMatrix *cem, int row, int col) {
    cem->row = row;
    cem->col = col;
    cem->CEdata = (CubicEquation **)malloc(row * sizeof(CubicEquation *));
    for (int i = 0; i < row; i++) {
        cem->CEdata[i] = (CubicEquation *)malloc(col * sizeof(CubicEquation));
        for (int j = 0; j < col; j++) {
            cem->CEdata[i][j] = CubicEquationCreate();
        }
    }
}

CubicEquation CubicEquationSolver(CubicEquation ce) {
/*  CubicEquation ce;
    double a, b, c, d;
    ce.a = a;
    ce.b = b;
    ce.c = c;
    ce.d = d;
*/
    ce.p = (3 * ce.a * ce.c - ce.b * ce.b) / (3 * ce.a * ce.a);
    ce.q = (2 * ce.b * ce.b * ce.b - 9 * ce.a * ce.b * ce.c + 27 * ce.a * ce.a * ce.d) / (27 * ce.a * ce.a * ce.a);
    
    ce.Discriminant = pow(ce.q / 2, 2) + pow(ce.p / 3, 3);
    
    return ce;
}

void CubicEquationMatrixPrint(CubicEquationMatrix *cem) {
    for (int i = 0; i < cem->row; i++) {
        for (int j = 0; j < cem->col; j++) {
        CubicEquation ce = cem->CEdata[i][j]; 
              for (int i = 0; i < cem->row; i++) {
        for (int j = 0; j < cem->col; j++) {
            CubicEquation ce = cem->CEdata[i][j]; 
            ce.p = (3 * ce.a * ce.c - ce.b * ce.b) / (3 * ce.a * ce.a);
            ce.q = (2 * ce.b * ce.b * ce.b - 9 * ce.a * ce.b * ce.c + 27 * ce.a * ce.a * ce.d) / (27 * ce.a * ce.a * ce.a);
            ce.Discriminant = pow(ce.q / 2, 2) + pow(ce.p / 3, 3);

            if (ce.Discriminant > 0) {
                ce.u = cbrt(-ce.q / 2 + sqrt(ce.Discriminant));
                ce.v = cbrt(-ce.q / 2 - sqrt(ce.Discriminant));
                ce.rr = ce.u + ce.v - ce.b / (3 * ce.a);
                printf("[%.0lfx^3+(%.0lf)x^2+(%.0lf)x+(%.0lf)=0] - Real root: {%.2lf}\n", ce.a, ce.b, ce.c, ce.d, ce.rr);
            } else if (ce.Discriminant == 0) {
                ce.u = cbrt(-ce.q / 2);
                ce.real_root1 = 2 * ce.u - ce.b / (3 * ce.a);
                ce.real_root2 = -ce.u - ce.b / (3 * ce.a);
                printf("[%.0lfx^3+(%.0lf)x^2+(%.0lf)x+(%.0lf)=0] - Real roots: {%.2lf | %.2lf}\n", ce.a, ce.b, ce.c, ce.d, ce.real_root1, ce.real_root2);
            } else {
                double r = sqrt(-pow(ce.p / 3, 3));
                double phi = acos(-ce.q / (2 * r));
                ce.real_root1 = 2 * cbrt(r) * cos(phi / 3) - ce.b / (3 * ce.a);
                ce.real_root2 = 2 * cbrt(r) * cos((phi + 2 * PI) / 3) - ce.b / (3 * ce.a);
                ce.real_root3 = 2 * cbrt(r) * cos((phi + 4 * PI) / 3) - ce.b / (3 * ce.a);
                printf("[%.0lfx^3+(%.0lf)x^2+(%.0lf)x+(%.0lf)=0] - Real roots: {%.2lf | %.2lf | %.2lf}\n", ce.a, ce.b, ce.c, ce.d, ce.real_root1, ce.real_root2, ce.real_root3);
              }
            }printf("\n");
          }
        printf("\n");
      }
    }
}

void CEMatrixFree(CubicEquationMatrix *cem) {
    for(int i = 0; i < cem->row; i++)
        free(cem->CEdata[i]);
    free(cem->CEdata);
}