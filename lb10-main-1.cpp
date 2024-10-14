#include<iostream>

using namespace std;

// Варіанти завдань середнього рівня (виконують всі)

// 13.Створіть шаблонну функцію, яка обчислює суму всіх елементів матриці
// будь-якого типу.

template <class T>
T sumMatrix(T** matrix, int rows, int cols) {
    T sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}


int main() {

    int r = 3;
    int c = 3;

    int** intMatrix = new int*[r];
    for (int i = 0; i < r; ++i) {
        intMatrix[i] = new int[c];
    }

    for (int i = 0, ii = 1; i < r; i++){
        for (int j= 0; j < c; j++){
            intMatrix[i][j] = ii; ii++;
        }
    }
    
    
    cout << "sum of matrix is " << sumMatrix(intMatrix, r, c) << endl;

    ///////

    double** doubleMatrix = new double*[r];
    for (int i = 0; i < r; ++i) {
        doubleMatrix[i] = new double[c];
    }

    float ii = 1.1;
    for (int i = 0; i < r; i++){
        for (int j= 0; j < c; j++){
            doubleMatrix[i][j] = ii; ii += 1.1;
        }
    }
    cout << "sum of matrix is " << sumMatrix(doubleMatrix, r, c) << endl;

    for (int i = 0; i < r; ++i) {
        delete[] intMatrix[i];
        delete[] doubleMatrix[i];
    }
    delete[] intMatrix;
    delete[] doubleMatrix;


    return 0;
}
