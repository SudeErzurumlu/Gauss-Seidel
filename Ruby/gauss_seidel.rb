# gauss_seidel.rb
# Function for Gauss-Seidel Method in Ruby

def gauss_seidel(a, b, tolerance = 1e-6, max_iterations = 100)
  # Gauss-Seidel method to solve Ax = b
  #
  # Args:
  #   a: Coefficient matrix (2D array)
  #   b: Constants vector (1D array)
  #   tolerance: Convergence tolerance
  #   max_iterations: Maximum iterations to try for convergence
  #
  # Returns:
  #   Solution vector or nil if convergence is not achieved

  n = b.size
  x = Array.new(n, 0.0) # Initialize solution vector with zeros
  
  max_iterations.times do
    x_old = x.clone # Copy of previous solution for convergence check
    
    n.times do |i|
      sum = b[i]
      
      n.times do |j|
        sum -= a[i][j] * x[j] if i != j
      end
      
      x[i] = sum / a[i][i] # Update the ith variable
    end
    
    # Check for convergence
    error = x.zip(x_old).map { |xi, x_old_i| (xi - x_old_i).abs }.sum
    return x if error < tolerance
  end
  
  nil # Return nil if maximum iterations are reached without convergence
end
