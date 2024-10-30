// gauss_seidel.cpp
// Implementation of Gauss-Seidel Method in C++

#include "gauss_seidel.h"
#include <cmath>    // For std::abs
#include <vector>

// Gauss-Seidel method to solve Ax = b
std::vector<double> gaussSeidel(const std::vector<std::vector<double>>& A, const std::vector<double>& b, double tolerance, int maxIterations) {
    int n = A.size();
    std::vector<double> x(n, 0.0);  // Initialize the solution vector with zeros
    
    for (int k = 0; k < maxIterations; ++k) {
        std::vector<double> x_old = x;  // Store the previous solution
        
        for (int i = 0; i < n; ++i) {
            double sum = b[i];
            
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum -= A[i][j] * x[j];
                }
            }
            
            x[i] = sum / A[i][i];  // Update the ith variable
        }
        
        // Check for convergence
        double error = 0.0;
        for (int i = 0; i < n; ++i) {
            error += std::abs(x[i] - x_old[i]);
        }
        
        if (error < tolerance) {
            return x;  // Converged solution
        }
    }
    
    return {};  // Return empty vector if max iterations are reached without convergence
}
