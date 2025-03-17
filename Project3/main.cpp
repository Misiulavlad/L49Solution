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

	cout <<"Number of rows with a large number of positive elements: "<< count_rows_with_more_positives(matrix, cols, rows);


	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}