% example_usage.m
% Example usage of the Gauss-Seidel method

% Define the coefficient matrix A and vector b
A = [4, 1, 2;
     3, 5, 1;
     1, 1, 3];
b = [4; 7; 3];

% Set parameters
tolerance = 1e-6;   % Convergence tolerance
maxIterations = 100; % Maximum number of iterations

% Call the Gauss-Seidel function
[x, converged] = gauss_seidel(A, b, tolerance, maxIterations);

% Display the result
if converged
    disp('Solution:');
    disp(x);
else
    disp('Solution did not converge within the given tolerance and iteration limit.');
end
