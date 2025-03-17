#include "util.h"

int** compress_matrix(int** matrix, int rows, int cols, int& new_rows, int& new_cols) {
    
    bool* rows_to_keep = new bool[rows]();
    bool* cols_to_keep = new bool[cols]();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                rows_to_keep[i] = true;
                cols_to_keep[j] = true;
            }
        }
    }

    
    new_rows = 0, new_cols = 0;
    for (int i = 0; i < rows; i++) {
        if (rows_to_keep[i]) new_rows++;
    }
    for (int j = 0; j < cols; j++) {
        if (cols_to_keep[j]) new_cols++;
    }


    int** compressed_matrix = new int* [new_rows];
    for (int i = 0; i < new_rows; i++) {
        compressed_matrix[i] = new int[new_cols];
    }


    int new_row = 0;
    for (int i = 0; i < rows; i++) {
        if (rows_to_keep[i]) {
            int new_col = 0;
            for (int j = 0; j < cols; j++) {
                if (cols_to_keep[j]) {
                    compressed_matrix[new_row][new_col] = matrix[i][j];
                    new_col++;
                }
            }
            new_row++;
        }
    }

    delete[] rows_to_keep;
    delete[] cols_to_keep;
    return compressed_matrix;
}
