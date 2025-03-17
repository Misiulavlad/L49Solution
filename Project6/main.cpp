#include "util.h"
int main() {
	int rows, cols;

	cout << "Enter number of rows: ";
	cin >> rows;
	while (rows <= 0) {
		cout << "Invalid data." << endl;
		cin >> rows;
	}
	cout << "Enter number of columns: ";
	cin >> cols;
	while (cols <= 0) {
		cout << "Invalid data." << endl;
		cin >> cols;
	}

	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}

	cout << "Enter matrix elements:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << find_minimum_of_local_maxima(matrix, rows, cols);



	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}