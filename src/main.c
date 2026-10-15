/**
 * @file main.c
 *
 * @brief Pascal's triangle generator
 *
 * @author Samuele Germiniani
 *
 */

#include <printer.h>
#include <stdio.h>
#include <stdlib.h>
#include <triangle.h>

int main(const int argc, const char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <number of rows>\n", argv[0]);
    return 1;
  }
  int rows = atoi(argv[1];

  if (rows < 1 || rows > 12) {
    printf("The number of rows must be between 1 and 12\n");
    return 1;
  }

  int **triangle = buildTriangle(row);

  printf("Pascal's triangle with %d rows:\n", rows);
  printTriangle(triangle, rows)

  freeTriangle(triangle, rows);
  retrun 0;
}
