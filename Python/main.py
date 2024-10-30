# main.py
# Main file to demonstrate Gauss-Seidel Method in Python

import numpy as np
from gauss_seidel import gauss_seidel

# Define the coefficient matrix A and vector b for the system Ax = b
A = np.array([
    [4, 1, 2],
    [3, 5, 1],
    [1, 1, 3]
], dtype=float)

b = np.array([4, 7, 3], dtype=float)

# Set parameters
tolerance = 1e-6  # Convergence tolerance
max_iterations = 100  # Maximum number of iterations

# Solve the system using Gauss-Seidel
solution = gauss_seidel(A, b, tolerance, max_iterations)

# Display the result
if solution is not None:
    print("Solution:")
    print(solution)
else:
    print("Solution did not converge within the given tolerance and iteration limit.")
