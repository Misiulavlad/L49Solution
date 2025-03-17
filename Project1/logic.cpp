#include "util.h"
double find_avg_sum_of_nonzero_items(int** matrix, int n, int m) {
	double sum = 0;
	double count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] != 0) {
				sum += matrix[i][j];
				count++;
			}
		}
	}
	double result = sum / count;
	return result;
}