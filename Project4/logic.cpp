#include "util.h"
int calculate_sum_extreme_columns(int** matrix, int rows, int cols) {

    int max_value = matrix[0][0];
    int min_value = matrix[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max_value) {
                max_value = matrix[i][j];
            }
            if (matrix[i][j] < min_value) {
                min_value = matrix[i][j];
            }
        }
    }

    bool* extreme_columns = new bool[cols]();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == max_value || matrix[i][j] == min_value) {
                extreme_columns[j] = true;
            }
        }
    }

    int sum = 0;
    for (int j = 0; j < cols; j++) {
        if (extreme_columns[j]) {
            for (int i = 0; i < rows; i++) {
                sum += matrix[i][j];
            }
        }
    }

    delete[] extreme_columns;
    return sum;
}

