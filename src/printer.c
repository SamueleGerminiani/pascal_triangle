#include <printer.h>
#include <stdio.h>

// Function to print a single row, centered with respect to the last row
static void printRow(int row[], int i, int n) {
    // Indentation: the shorter the row, the more spaces
    for (int s = 0; s < (n - 1 - i) * 2; s++) {
        printf(" ");
    }

    for (int j = 0; j <= i; j++) {
        printf("%4d", row[j]);
    }
    printf("\n");
}

// Function to print the first n rows of Pascal's triangle
void printTriangle(int **triangle, int n) {
    for (int i = 0; i < n; i++) {
        printRow(triangle[i], i, n);
    }
}
