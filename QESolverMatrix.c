#include <stdio.h>
#include <time.h>
#include <math.h>
#include "defenitions.h"


int QESolverMatix()
{
    srand(time(0));
    
    QuadraticEquation matrix[N][M];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            matrix[i][j] = generate_quadratic_equation();
        }
    } 
    
    // Решение уравнений в матрице
    double root1, root2;
    int num_roots;
    double roots[2][2][2]; // Массив для хранения корней уравнений

    printf("Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            QuadraticEquation eq = matrix[i][j];
            EQSolver(eq, &root1, &root2, &num_roots);
            roots[i][j][0] = root1;
            roots[i][j][1] = root2;
            printf("[%d][%d] Equation: %.0lfx^2+%.0lfx+%.0lf=0\n", i, j, eq.a, eq.b, eq.c);

        }
    }

    // Вывод решений в формате таблицы
    printf("\nEquesion solver:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("[%d] ", i * 2 + j);
            if (roots[i][j][0] == roots[i][j][1]) {
                printf("Roots: %.2lf", roots[i][j][0]);
            } else {
                printf("Roots: %.2lf and %.2lf", roots[i][j][0], roots[i][j][1]);
            }
            if (j == 0) {
                printf(" | ");
            }
        }printf("\n");
    }printf("\n");
}