// main.c
// Main file to demonstrate Gauss-Seidel Method in C

#include <stdio.h>
#include <stdlib.h>
#include "gauss_seidel.h"

int main() {
    // Define matrix size
    int n = 3;

    // Define the coefficient matrix A
    double **A = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) A[i] = (double *)malloc(n * sizeof(double));

    A[0][0] = 4; A[0][1] = 1; A[0][2] = 2;
    A[1][0] = 3; A[1][1] = 5; A[1][2] = 1;
    A[2][0] = 1; A[2][1] = 1; A[2][2] = 3;

    // Define the constants vector b
    double b[] = {4, 7, 3};

    // Solution vector
    double x[n];

    // Set parameters
    double tolerance = 1e-6;
    int maxIterations = 100;

    // Solve the system using Gauss-Seidel
    int result = gauss_seidel(A, b, n, tolerance, maxIterations, x);

    // Display the result
    if (result == 0) {
        printf("Solution:\n");
        for (int i = 0; i < n; i++) {
            printf("x[%d] = %f\n", i, x[i]);
        }
    } else {
        printf("Solution did not converge within the given tolerance and iteration limit.\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) free(A[i]);
    free(A);

    return 0;
}
