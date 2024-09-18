#include <stdio.h>
#include <time.h>
#include <math.h>
#include "defenitions.h"

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