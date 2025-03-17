#include "util.h"
int main() {
    int n;

    cout << "Enter dimension: ";
    cin >> n;
    while (n <= 0) {
        cout << "Invalid data." << endl;
        cin >> n;
    }
   

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

     cout<<calculate_diagonal_sum( matrix,  n);


    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}