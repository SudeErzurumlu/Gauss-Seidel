# gauss_seidel.rb
# Gauss-Seidel Method in Ruby

def gauss_seidel(a, b, tolerance = 1e-6, max_iterations = 100)
  # Initialize the solution vector with zeros
  n = b.length
  x = Array.new(n, 0.0)

  # Gauss-Seidel iteration
  max_iterations.times do
    x_old = x.clone
    
    n.times do |i|
      sum = b[i]
      
      n.times do |j|
        sum -= a[i][j] * x[j] if i != j
      end
      
      x[i] = sum / a[i][i]
    end
    
    # Check for convergence
    error = x.each_with_index.map { |xi, i| (xi - x_old[i]).abs }.sum
    return x if error < tolerance
  end
  
  nil  # Return nil if the solution does not converge
end
