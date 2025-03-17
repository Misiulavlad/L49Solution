#include "util.h"
int find_minimum_of_local_maxima(int** matrix, int rows, int cols) {
    int min_local_max = -1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool is_local_maximum = true;


            if (i > 0 && matrix[i][j] <= matrix[i - 1][j]) is_local_maximum = false;
            if (i < rows - 1 && matrix[i][j] <= matrix[i + 1][j]) is_local_maximum = false;
            if (j > 0 && matrix[i][j] <= matrix[i][j - 1]) is_local_maximum = false;
            if (j < cols - 1 && matrix[i][j] <= matrix[i][j + 1]) is_local_maximum = false;

            if (is_local_maximum) {
                if (min_local_max == -1 || matrix[i][j] < min_local_max) {
                    min_local_max = matrix[i][j];
                }
            }
        }
    }

    return min_local_max;
}