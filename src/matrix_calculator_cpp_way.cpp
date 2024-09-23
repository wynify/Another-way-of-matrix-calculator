//N O T  I N   U S E 

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Matrix{
public:
    int row, col;
    vector<vector<int>> data;

    Matrix(int r, int c) : row(r), col(c), data(r, vector<int>(c)) {}

    void input(){
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                cin >> data[i][j];
            } 
        }     
    }

    void print() const{
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                cout << "[" << data[i][j] << "]";
            }
            cout << "\n";
        }
    }

    Matrix operator+(const Matrix& other) const{
        Matrix result(row, col);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const{
        Matrix result(row, col);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const{
        Matrix result(row, other.col);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < other.col; j++){
                result.data[i][j] = 0;
                for (int k = 0; k < col; k++){
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }

            }  
        }
        return result;  
    }

    Matrix operator/(const Matrix& other) const{
        Matrix result(row, col);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (other.data[i][j] != 0){
                    result.data[i][j] = data[i][j] / other.data[i][j];
                } else {
                    cerr << "Division by zero error at (" << i << ", " << j << ")\n";
                    result.data[i][j] = 0;
                }
            }
        }
    return result;
    }
};

Matrix parseAndCompute(const string& expression, const Matrix& m1, const Matrix& m2){
    istringstream iss(expression);
    string matrix1, op, matrix2; //Описывается ввод операнда между двумя матрицами
    iss >> matrix1 >> op >> matrix2;

    if (matrix1 == "matrix1" && matrix2 == "matrix2"){
        if(op == "+"){
            return m1 + m2;
        } else if(op == "-"){
            return m1 - m2;
        } else if(op == "*"){
            return m1 * m2;
        } else if (op == "/"){
            return m1 / m2;
        } else {
            cerr << "Invalid operator\n";
        }
    } else {cerr << "Invalid matrix names\n";}
    return Matrix(0, 0);
}

int main() {
    int row, col;
    cout << "Enter the number of rows and columns: ";
    cin >> row >> col;

    Matrix m1(row, col);
    Matrix m2(row, col);

    cout << "Enter numbers for matrix A:\n";
    m1.input();

    cout << "Enter numbers for matrix B:\n";
    m2.input();

    cin.ignore(); // Игнорируем оставшийся символ новой строки после ввода чисел

    string expression;
    cout << "Enter the expression (e.g., matrix1 + matrix2): ";
    getline(cin, expression);

    Matrix result = parseAndCompute(expression, m1, m2);

    cout << "Resultant matrix:\n";
    result.print();

    return 0;
}