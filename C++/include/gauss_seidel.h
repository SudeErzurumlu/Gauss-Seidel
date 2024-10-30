// gauss_seidel.h
// Header file for Gauss-Seidel Method in C++

#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

#include <vector>

// Gauss-Seidel method to solve a system of linear equations
// Parameters:
//   A - Coefficient matrix
//   b - Constants vector
//   tolerance - Error tolerance for convergence
//   maxIterations - Maximum number of iterations
// Returns:
//   Solution vector, or empty vector if convergence isn't reached
std::vector<double> gaussSeidel(const std::vector<std::vector<double>>& A, const std::vector<double>& b, double tolerance, int maxIterations);

#endif // GAUSS_SEIDEL_H
