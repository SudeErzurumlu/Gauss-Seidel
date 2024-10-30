% gauss_seidel.m
% Gauss-Seidel Method for solving Ax = b

function [x, converged] = gauss_seidel(A, b, tolerance, maxIterations)
    % Initialize variables
    n = length(b);
    x = zeros(n, 1);    % Initial guess (vector of zeros)
    converged = false;  % Convergence flag

    for k = 1:maxIterations
        x_old = x;  % Store the previous iteration's solution
        
        % Perform Gauss-Seidel iteration
        for i = 1:n
            sum = b(i);
            
            for j = 1:n
                if j ~= i
                    sum = sum - A(i, j) * x(j);
                end
            end
            
            x(i) = sum / A(i, i);
        end

        % Check for convergence
        error = norm(x - x_old, inf); % Infinity norm of error
        if error < tolerance
            converged = true;
            return;  % Exit function if solution has converged
        end
    end
end
