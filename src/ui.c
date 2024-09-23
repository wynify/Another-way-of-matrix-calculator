//I guess to make this more powerfull and colorfull and better looking with libs like: FTXUI  5.0.0
//But now it's gonna be look like this btw.
//I guess it's too looks good;

#include <stdio.h>

#include "CubicEquation.c"
#include "QuadraticEquation.c"
#include "xn.c"
#include "matrix_calculator_upd.c"

#define COMMANDS 5

typedef struct ui{
    int code;
    const char* description;
} Command;


void PrintMenu(Command commands[], int size){
    printf("Enter an OP Code for choose option: ");
    for (int i = 0; i < size; i++){
        printf("%d - %s\n", commands[i].code, commands[i].description);
    }
    printf("\n");
}

void Menu(int row, int col, int OP, int n){
    Command commands[COMMANDS] = {
        {1, "Random quantity of Quadratic Equation's"},
        {2, "Random quantity ofCubic Equation's"},
        {3, "Both: Random quantity of Quadratic+Cubic"},
        {4, "Polinom x^n"},
        {5, "[NEW] Enter to MatrixCalculator (UPD 23.09.24) *Only ADD matrix for now. I work an update ;)"}
    };   
    //int row, col;
    PrintMenu(commands, COMMANDS);
    printf("Your choise: ");
    scanf("%d", &OP);
    QuadraticEquationMatrix qem;
    CubicEquationMatrix cem;

    //Обработка выражений
    switch (OP){
        case 1:
            printf("You selected Quadratic Equation's\nThis function generate random quantity of Quadratic Equation's\n");
            QuadraticEquatioMatrixCreate(&qem, row, col);
            QuadraticEquatioMatrixPrint(&qem);
            QEMatrixFree(&qem);
        break;
        case 2:
            printf("You selected Cubic Equation's\nThis function generate random quantity of Cubic Equation's\n");
            CubicEquationMatrixCreate(&cem, row, col);
            CubicEquationMatrixPrint(&cem);
            CEMatrixFree(&cem);
            break;
        case 3:
            printf("You selected Both\n\nThis function generate random quantity of Quadratic and Cubic Equation's\n");
            QuadraticEquatioMatrixCreate(&qem, row, col);
            QuadraticEquatioMatrixPrint(&qem);
            QEMatrixFree(&qem);

            CubicEquationMatrixCreate(&cem, row, col);
            CubicEquationMatrixPrint(&cem);
            CEMatrixFree(&cem); 
            break;
        case 4:
            printf("You selected Polinom x^n\n");
            printf("Enter an x^n for polinom: ");
            scanf("%d", &n);
            XN(n);
            break;
        case 5:
            printf("You selected MatrixCalculator\n");
            EXPECT_MATRIX();
            break;
        default:
            printf("Invalid OP-Code\n");
            break;
    }
}