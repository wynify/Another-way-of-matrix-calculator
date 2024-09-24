#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void inputMatrix(vector<vector<double>>& matrix) {
    int rows, cols;
    cout << "Введите количество строк и столбцов (например, 2 3): ";
    cin >> rows >> cols;
    matrix.resize(rows, vector<double>(cols));
    
    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << setw(8) << elem << " ";
        }
        cout << endl;
    }
}

vector<vector<double>> addMatrices(const vector<vector<double>>& a, const vector<vector<double>>& b) {
    int rows = a.size(), cols = a[0].size();
    vector<vector<double>> result(rows, vector<double>(cols));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

vector<vector<double>> subtractMatrices(const vector<vector<double>>& a, const vector<vector<double>>& b) {
    int rows = a.size(), cols = a[0].size();
    vector<vector<double>> result(rows, vector<double>(cols));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}

vector<vector<double>> multiplyMatrices(const vector<vector<double>>& a, const vector<vector<double>>& b) {
    int rows = a.size(), cols = b[0].size(), common = a[0].size();
    vector<vector<double>> result(rows, vector<double>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < common; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

vector<vector<double>> divideMatrices(const vector<vector<double>>& a, const vector<vector<double>>& b) {
    int rows = a.size(), cols = a[0].size();
    vector<vector<double>> result(rows, vector<double>(cols));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (b[i][j] != 0) {
                result[i][j] = a[i][j] / b[i][j];
            } else {
                cout << "Ошибка: деление на ноль в позиции (" << i << ", " << j << ")\n";
                result[i][j] = 0; // или выбросить исключение
            }
        }
    }
    return result;
}

int MatrixCalculatorCall() {
    vector<vector<double>> matrix1, matrix2;
    
    cout << "Ввод первой матрицы:\n";
    inputMatrix(matrix1);
    
    char operation;
    cout << "Введите оператор (+, -, *, /): ";
    cin >> operation;
    
    cout << "Ввод второй матрицы:\n";
    inputMatrix(matrix2);
    
    vector<vector<double>> result;

    switch (operation) {
        case '+':
            if (matrix1.size() == matrix2.size() && matrix1[0].size() == matrix2[0].size()) {
                result = addMatrices(matrix1, matrix2);
            } else {
                cout << "Ошибка: размеры матриц не совпадают для сложения.\n";
                return 1;
            }
            break;
        case '-':
            if (matrix1.size() == matrix2.size() && matrix1[0].size() == matrix2[0].size()) {
                result = subtractMatrices(matrix1, matrix2);
            } else {
                cout << "Ошибка: размеры матриц не совпадают для вычитания.\n";
                return 1;
            }
            break;
        case '*':
            if (matrix1[0].size() == matrix2.size()) {
                result = multiplyMatrices(matrix1, matrix2);
            } else {
                cout << "Ошибка: количество столбцов первой матрицы не совпадает с количеством строк второй.\n";
                return 1;
            }
            break;
        case '/':
            if (matrix1.size() == matrix2.size() && matrix1[0].size() == matrix2[0].size()) {
                result = divideMatrices(matrix1, matrix2);
            } else {
                cout << "Ошибка: размеры матриц не совпадают для деления.\n";
                return 1;
            }
            break;
        default:
            cout << "Ошибка: неверный оператор.\n";
            return 1;
    }

    cout << "Matrix 1 \n";
    printMatrix(matrix1);
    cout << endl;

    cout << "Matrix 2 \n";
    printMatrix(matrix2);
    cout << endl;

    cout << "Результат:\n";
    printMatrix(result);
    
    return 0;
}
