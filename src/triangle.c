#include <stdlib.h>
#include <triangle.h>

// Function to build the first n rows of Pascal's triangle
int **buildTriangle(int n) {
    // One pointer for each row (calloc initializes them to NULL)
    int **triangle = calloc(n, sizeof(int *));

    for (int i = 1; i < n; i++) {
        // Row i contains i+1 numbers
        triangle[i] = malloc((i + 1) * sizeof(int));

        // The first and the last number of each row are 1
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        // Every other number is the sum of the two numbers above it
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}

// Function to free the memory of the triangle
void freeTriangle(int **triangle, int n) {
    for (int i = 0; i < n; i++) {
        free(triangle[i]);
    }
    free(triangle);
}
