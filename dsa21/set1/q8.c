#include <stdio.h>
int i,j;
int main() {
    int rows, cols;

    // Input the dimensions of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Find and print the number of non-zero elements in each row
    printf("Number of non-zero elements in each row:\n");
    for (i = 0; i < rows; i++) {
        int nonZeroCount = 0;
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
        printf("Row %d: %d non-zero elements\n", i , nonZeroCount);
    }

    return 0;
}
