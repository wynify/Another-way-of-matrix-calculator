#include <stdio.h>
#include <math.h>

typedef struct{
  int row;
  int col;
  int** data;
} Matrix;

Matrix createMatrix(int row, int col){
    Matrix m;
    m.row = row;
    m.col = col;
    m.data = (int**)malloc(row * sizeof(int*));

    for (int i = 0; i < row; i++){
        m.data[i] = (int*)malloc(row * sizeof(int));
    }
    return m;    
}

Matrix inputMatrix(Matrix m){
    for (int i = 0; i < m.row; i++){
        for (int j = 0; j < m.col; j++){
            scanf("%d", &m.data[i][j]);
        }
    }
    return m;
}

Matrix addMatrix(Matrix m1, Matrix m2){
    Matrix result = createMatrix(m1.row, m1.col);
    for (size_t i = 0; i < m1.row; i++){
        for (int j = 0; j < m1.col; j++){
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

Matrix subMatrix(Matrix m1, Matrix m2){
    Matrix result = createMatrix(m1.row, m1.col);
    for (size_t i = 0; i < m1.row; i++){
        for (int j = 0; j < m1.col; j++){
            result.data[i][j] = m1.data[i][j] - m2.data[i][j];
        }
    }
    return result;
}

void printMatrix(Matrix m){
    for (int i = 0; i < m.row; i++){
        for (int j = 0; j < m.col; j++){
            printf(" [%d] ", m.data[i][j]);
        }
        printf("\n");
    }
}

void FreeMatrix(Matrix m){
    for (int i = 0; i < m.row; i++)
    {
        free(m.data[i]);
    }
    free(m.data);
}

void EXPECT_MATRIX() {
    int row, col, operation;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &col);

    Matrix m1 = createMatrix(row, col);
    Matrix m2 = createMatrix(row, col);

    printf("Enter numbers for matrix A:\n");
    inputMatrix(m1);

    printf("Enter numbers for matrix B:\n");
    inputMatrix(m2);

    printf("Choose an operation:\n1 - Add\n2 - Subtract\n");
    scanf("%d", &operation);

    Matrix result;
    if (operation == 1) {
        result = addMatrix(m1, m2);
    } else if (operation == 2) {
        result = subMatrix(m1, m2);
    } else {
        printf("Invalid operation\n");
        FreeMatrix(m1);
        FreeMatrix(m2);
        return;
    }

    printf("Resultant matrix:\n");
    printMatrix(result);

    FreeMatrix(m1);
    FreeMatrix(m2);
    FreeMatrix(result);
}