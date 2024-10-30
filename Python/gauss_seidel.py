# gauss_seidel.py
# Function for Gauss-Seidel Method in Python

import numpy as np

def gauss_seidel(A, b, tolerance=1e-6, max_iterations=100):
    """
    Solves the system of linear equations Ax = b using the Gauss-Seidel method.
    
    Parameters:
        A (ndarray): Coefficient matrix
        b (ndarray): Constants vector
        tolerance (float): Error tolerance for convergence
        max_iterations (int): Maximum number of iterations
    
    Returns:
        x (ndarray): Solution vector, or None if convergence is not achieved
    """
    n = len(b)
    x = np.zeros(n)  # Initial guess
    
    for k in range(max_iterations):
        x_old = x.copy()
        
        for i in range(n):
            sum_ = b[i]
            
            for j in range(n):
                if i != j:
                    sum_ -= A[i, j] * x[j]
            
            x[i] = sum_ / A[i, i]
        
        # Check for convergence
        error = np.linalg.norm(x - x_old, ord=np.inf)
        
        if error < tolerance:
            return x  # Solution converged
    
    return None  # Solution did not converge
