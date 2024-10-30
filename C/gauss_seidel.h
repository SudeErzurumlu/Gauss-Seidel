// gauss_seidel.h
// Header file for Gauss-Seidel Method in C

#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

// Gauss-Seidel method to solve a system of linear equations Ax = b
// Parameters:
//   A - Coefficient matrix (2D array)
//   b - Constants vector
//   n - Dimension of matrix A and vector b
//   tolerance - Error tolerance for convergence
//   maxIterations - Maximum number of iterations
//   x - Solution vector (output)
int gauss_seidel(double **A, double *b, int n, double tolerance, int maxIterations, double *x);

#endif
