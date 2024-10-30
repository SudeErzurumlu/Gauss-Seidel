// gauss_seidel.c
// Implementation of Gauss-Seidel Method in C

#include "gauss_seidel.h"
#include <math.h>   // For fabs function
#include <stdlib.h> // For malloc

int gauss_seidel(double **A, double *b, int n, double tolerance, int maxIterations, double *x) {
    double *x_old = (double *)malloc(n * sizeof(double));
    if (x_old == NULL) return -1; // Memory allocation failure

    // Initialize x with zeros
    for (int i = 0; i < n; i++) x[i] = 0.0;

    for (int k = 0; k < maxIterations; k++) {
        // Store the previous solution
        for (int i = 0; i < n; i++) x_old[i] = x[i];

        // Perform Gauss-Seidel iteration
        for (int i = 0; i < n; i++) {
            double sum = b[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= A[i][j] * x[j];
                }
            }
            x[i] = sum / A[i][i];
        }

        // Check for convergence
        double error = 0.0;
        for (int i = 0; i < n; i++) {
            error += fabs(x[i] - x_old[i]);
        }
        if (error < tolerance) {
            free(x_old);
            return 0;  // Solution converged
        }
    }
    
    free(x_old);
    return 1;  // Solution did not converge within the maximum iterations
}
