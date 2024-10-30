// Main.java
// Main file to demonstrate Gauss-Seidel Method in Java

public class Main {
    public static void main(String[] args) {
        // Define the coefficient matrix A and constants vector b
        double[][] A = {
            {4, 1, 2},
            {3, 5, 1},
            {1, 1, 3}
        };
        
        double[] b = {4, 7, 3};

        // Set parameters
        double tolerance = 1e-6;  // Convergence tolerance
        int maxIterations = 100;  // Maximum number of iterations

        // Solve the system using Gauss-Seidel
        double[] solution = GaussSeidel.gaussSeidel(A, b, tolerance, maxIterations);

        // Display the result
        if (solution != null) {
            System.out.println("Solution:");
            for (int i = 0; i < solution.length; i++) {
                System.out.printf("x[%d] = %f%n", i, solution[i]);
            }
        } else {
            System.out.println("Solution did not converge within the given tolerance and iteration limit.");
        }
    }
}
