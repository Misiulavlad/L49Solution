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

    int row, col, value;
    find_last_local_minimum(matrix, rows, cols, row, col, value);

    if (row == -1 && col == -1) {
        cout << "No local minimum found." << endl;
    }
    else {
        cout << "The last local minimum is located at [" << row << ";" << col << "] with the value " << value << "." << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
