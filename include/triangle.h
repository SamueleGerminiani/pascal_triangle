/** @file triangle.h
 */

/** Function to build the first n rows of Pascal's triangle.
 *  Row i contains i+1 numbers.
 */
int **buildTriangle(int n);

/** Function to free the memory of the triangle
 */
void freeTriangle(int **triangle, int n);
