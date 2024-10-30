# gauss_seidel.R
# Function for Gauss-Seidel Method in R

gauss_seidel <- function(A, b, tolerance = 1e-6, max_iterations = 100) {
  # Gauss-Seidel method to solve Ax = b
  #
  # Args:
  #   A: Coefficient matrix
  #   b: Constants vector
  #   tolerance: Convergence tolerance
  #   max_iterations: Maximum iterations to try for convergence
  #
  # Returns:
  #   Solution vector or NULL if convergence is not achieved
  
  n <- length(b)
  x <- numeric(n)  # Initialize solution vector with zeros
  
  for (k in 1:max_iterations) {
    x_old <- x  # Copy of previous solution for convergence check
    
    for (i in 1:n) {
      sum <- b[i]
      
      for (j in 1:n) {
        if (i != j) {
          sum <- sum - A[i, j] * x[j]
        }
      }
      
      x[i] <- sum / A[i, i]  # Update the ith variable
    }
    
    # Check for convergence
    if (sum(abs(x - x_old)) < tolerance) {
      return(x)  # Return solution if converged
    }
  }
  
  return(NULL)  # Return NULL if maximum iterations are reached without convergence
}
