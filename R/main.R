# main.R
# Main file to demonstrate Gauss-Seidel Method in R

source("gauss_seidel.R")

# Define the coefficient matrix A and vector b for the system Ax = b
A <- matrix(c(4, 1, 2,
              3, 5, 1,
              1, 1, 3), nrow = 3, byrow = TRUE)

b <- c(4, 7, 3)

# Set parameters
tolerance <- 1e-6  # Convergence tolerance
max_iterations <- 100  # Maximum number of iterations

# Solve the system using Gauss-Seidel
solution <- gauss_seidel(A, b, tolerance, max_iterations)

# Display the result
if (!is.null(solution)) {
  cat("Solution:\n")
  print(solution)
} else {
  cat("Solution did not converge within the given tolerance and iteration limit.\n")
}
