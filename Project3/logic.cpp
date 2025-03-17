int count_rows_with_more_positives(int** matrix, int m, int n) {
    int count = 0;

    for (int i = 0; i < n; i++) { 
        int positive = 0, negative = 0;

        for (int j = 0; j < m; j++) { 
            if (matrix[i][j] > 0) {
                positive++;
            }
            else if (matrix[i][j] < 0) {
                negative++;
            }
        }

        if (positive > negative) { 
            count++;
        }
    }
    return count;
}
