/* 
    Newton method:
        x_{n+1} = x_{n} - f(x_{n}) / f'(x_{n})
 */
#include <iostream>
#include <cmath>
#include <iomanip>

// Function for which we want to find the root
double f(double x) {
    return x * x - 5;
}

// Derivative of the function
double f_prime(double x) {
    return 2 * x;
}

int main() {
    // Initial guess
    double x0 = 1.0;
    // Tolerance
    double tol = 1e-6;
    // Maximum number of iterations
    int max_iter = 1000;

    double x = x0;
    for (int i = 0; i < max_iter; ++i) {
        double fx = f(x);
        double fpx = f_prime(x);

        // Update the estimate using Newton-Raphson formula
        // double x1 = x - fx / fpx;
        float lr = 0.01;
        double x1 = x - lr * fx;

        std::cout << "error: " << std::fabs(x1 - x) << std::endl;
        // Check for convergence
        if (std::fabs(x1 - x) < tol) {
            std::cout << "Root found: " << std::setprecision(10) << x1 << std::endl;
            return 0;
        }

        // Update the current estimate
        x = x1;
    }

    std::cout << "Failed to converge to a solution within " << max_iter << " iterations." << std::endl;
    return 1;
}
