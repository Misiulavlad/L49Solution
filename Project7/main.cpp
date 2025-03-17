#include "util.h"
#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter matrix dimensions (N and M): ";
    cin >> rows >> cols;

    while (rows <= 0 || cols <= 0) {
        cout << "Invalid input. Please try again: ";
        cin >> rows >> cols;
    }

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int new_rows, new_cols;
    int** compressed_matrix = compress_matrix(matrix, rows, cols, new_rows, new_cols);

    cout << "Compressed matrix:" << endl;
    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            cout << compressed_matrix[i][j] << " ";
        }
        cout << endl;
    }

    
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < new_rows; i++) {
        delete[] compressed_matrix[i];
    }
    delete[] compressed_matrix;

    return 0;
}
