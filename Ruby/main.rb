# main.rb
# Demonstration of Gauss-Seidel Method in Ruby

require_relative 'gauss_seidel'

# Define the coefficient matrix A and vector b for the system Ax = b
a = [
  [4, 1, 2],
  [3, 5, 1],
  [1, 1, 3]
]

b = [4, 7, 3]

# Set parameters
tolerance = 1e-6  # Convergence tolerance
max_iterations = 100  # Maximum number of iterations

# Solve the system using Gauss-Seidel
solution = gauss_seidel(a, b, tolerance, max_iterations)

# Display the result
if solution
  puts "Solution:"
  solution.each { |value| puts value }
else
  puts "Solution did not converge within the given tolerance and iteration limit."
end
