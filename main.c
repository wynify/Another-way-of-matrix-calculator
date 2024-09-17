#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//I use Macro for now cuz I don't need a scan function rn, but I will add scan function later for matrix any demension
#define N 3
#define M 3

typedef struct {
    double a;
    double b;
    double c;
} QuadraticEquation;

QuadraticEquation generate_quadratic_equation()
{
    QuadraticEquation eq;
    eq.a = rand() % 10 + 1;                             //can't be zero
    eq.b = rand() % 21 - 10;
    eq.c = rand() % 21 - 10;
    return eq;
}

void EQSolver(QuadraticEquation eq, double* root1, double* root2, int* num_roots)
{
    double a = eq.a;
    double b = eq.b;
    double c = eq.c;
    double discriminant = b * b - 4 * a * c;
    
    if(discriminant > 0)                                //If discriminant > 0 then eqaution have are two roots
    {
        *num_roots = 2;                                 //Pointer than change contity of equation to 2
        *root1 = (-b + sqrt(discriminant)) / (2*a);     //Root 1 
        *root2 = (-b - sqrt(discriminant)) / (2*a);     //Root 2 
    } else if (discriminant == 0) {                     //If discriminant = 0 than root are one
        *num_roots = 1;                                 //Pointer than change contity of equation to 1
        *root1 = *root2 = -b / (2*a);                   //The only root
    } else {
        *num_roots = 0;                                 //No roots
    }
}

int main()
{
    srand(time(0));
    
    QuadraticEquation matrix[N][M];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            matrix[i][j] = generate_quadratic_equation();
        }
    } 
    
    //Matrix equation solver here []
    double root1, root2;
    int num_roots;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            QuadraticEquation eq = matrix[i][j];
            EQSolver(eq, &root1, &root2, &num_roots);
            printf("Equation [%d, %d]: %.0lfx^2+%.0lfx+%.0lf=0\n", i, j, eq.a, eq.b, eq.c);
            
            if(num_roots == 2){
                printf("Roots: %.2lf and %.2lf\n\n", root1, root2);
            } else if (num_roots == 1){
                printf("Root only one: %.2lf\n\n", root1);
            } else {
                printf("No valid roots\n");
            }
        }
    }
    
    return 0;
}
