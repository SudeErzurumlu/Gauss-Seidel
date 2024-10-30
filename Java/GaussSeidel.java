// GaussSeidel.java
// Class for Gauss-Seidel Method in Java

public class GaussSeidel {

    public static double[] gaussSeidel(double[][] A, double[] b, double tolerance, int maxIterations) {
        int n = b.length;
        double[] x = new double[n]; // Solution vector initialized with zeros

        for (int k = 0; k < maxIterations; k++) {
            double[] xOld = x.clone(); // Copy of previous solution for convergence check

            for (int i = 0; i < n; i++) {
                double sum = b[i];
                
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        sum -= A[i][j] * x[j];
                    }
                }
                
                x[i] = sum / A[i][i];
            }

            // Check for convergence
            double error = 0.0;
            for (int i = 0; i < n; i++) {
                error += Math.abs(x[i] - xOld[i]);
            }

            if (error < tolerance) {
                return x; // Solution converged
            }
        }
        
        return null; // Solution did not converge within the given tolerance and iteration limit
    }
}
