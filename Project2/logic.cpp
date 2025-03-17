#include "util.h"
int calculate_diagonal_sum(int** matrix, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += matrix[i][i];
		sum += matrix[i][n - i - 1];
	}

	return sum;
}