//NOT IN USE

#include <iostream>
#include <vector>

class Matrix {
public:
    int row, col;
    std::vector<std::vector<int>> data;

    Matrix(int r, int c) : row(r), col(c), data(r, std::vector<int>(c)) {}

    void input() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                std::cin >> data[i][j];
            }
        }
    }

    void print() const {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                std::cout << " [" << data[i][j] << "] ";
            }
            std::cout << "\n";
        }
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Пример для умножения матриц
    Matrix operator*(const Matrix& other) const {
        Matrix result(row, other.col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < other.col; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < col; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Пример для деления матриц (элементное деление)
    Matrix operator/(const Matrix& other) const {
        Matrix result(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (other.data[i][j] != 0) {
                    result.data[i][j] = data[i][j] / other.data[i][j];
                } else {
                    std::cerr << "Division by zero error at (" << i << ", " << j << ")\n";
                    result.data[i][j] = 0; // или другое значение по умолчанию
                }
            }
        }
        return result;
    }
};

void EXPECT_MATRIX() {
    int row, col;
    std::cout << "Enter the number of rows and columns: ";
    std::cin >> row >> col;

    Matrix m1(row, col);
    Matrix m2(row, col);

    std::cout << "Enter numbers for matrix A:\n";
    m1.input();

    std::cout << "Enter numbers for matrix B:\n";
    m2.input();

    Matrix sum = m1 + m2;
    Matrix diff = m1 - m2;
    Matrix prod = m1 * m2;
    Matrix div = m1 / m2;

    std::cout << "Sum of matrices:\n";
    sum.print();

    std::cout << "Difference of matrices:\n";
    diff.print();

    std::cout << "Product of matrices:\n";
    prod.print();

    std::cout << "Division of matrices:\n";
    div.print();
}
