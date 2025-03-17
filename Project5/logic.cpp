#include "util.h"

void find_last_local_minimum(int** matrix, int rows, int cols, int& row, int& col, int& value) {
    row = -1;
    col = -1;
    value = 0; 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool is_local_minimum = true;

           
            if (i > 0 && matrix[i][j] >= matrix[i - 1][j]) is_local_minimum = false;     // Top neighbor
            if (i < rows - 1 && matrix[i][j] >= matrix[i + 1][j]) is_local_minimum = false; // Bottom neighbor
            if (j > 0 && matrix[i][j] >= matrix[i][j - 1]) is_local_minimum = false;     // Left neighbor
            if (j < cols - 1 && matrix[i][j] >= matrix[i][j + 1]) is_local_minimum = false; // Right neighbor

            if (is_local_minimum) {
                row = i + 1;  
                col = j + 1;  
                value = matrix[i][j]; 
            }
        }
    }
}
