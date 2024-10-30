// main.cpp
// Main file to demonstrate Gauss-Seidel Method in C++

#include <iostream>
#include <vector>
#include "include/gauss_seidel.h"

int main() {
    // Define the coefficient matrix A and vector b for the system Ax = b
    std::vector<std::vector<double>> A = {
        {4, 1, 2},
        {3, 5, 1},
        {1, 1, 3}
    };
    
    std::vector<double> b = {4, 7, 3};
    
    // Set parameters
    double tolerance = 1e-6;   // Convergence tolerance
    int maxIterations = 100;   // Maximum number of iterations
    
    // Solve the system using Gauss-Seidel
    std::vector<double> solution = gaussSeidel(A, b, tolerance, maxIterations);
    
    // Display the result
    if (!solution.empty()) {
        std::cout << "Solution:" << std::endl;
        for (double value : solution) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Solution did not converge within the given tolerance and iteration limit." << std::endl;
    }
    
    return 0;
}
