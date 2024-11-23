#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

struct Point3D {
    double x, y, z;
};

// Function to calculate the Mean Squared Error (MSE) for a plane
double calculateError(const std::vector<Point3D>& points, double a, double b, double c, double d) {
    double error = 0.0;
    for (const auto& point : points) {
        double distance = a * point.x + b * point.y + c * point.z + d;
        error += distance * distance;
    }
    return error / points.size();
}

// Gradient descent to fit a plane: ax + by + cz + d = 0
void fitPlaneGradientDescent(const std::vector<Point3D>& points, double& a, double& b, double& c, double& d,
                             double learning_rate = 0.01, int max_iters = 10000, double tolerance = 1e-6) {
    int n = points.size();
    if (n < 3) {
        throw std::invalid_argument("At least 3 points are required to fit a plane.");
    }

    // Initialize plane parameters
    a = 1.0; b = 1.0; c = -1.0; d = 0.0;

    // Perform gradient descent
    for (int iter = 0; iter < max_iters; ++iter) {
        double da = 0.0, db = 0.0, dc = 0.0, dd = 0.0;

        // Compute gradients
        for (const auto& point : points) {
            double residual = a * point.x + b * point.y + c * point.z + d;
            /* 
                Plane = ax + by + cz + b = 0
                Loss = Sigma(y_gt - y_pred) ^ 2
                     = Sigma(residual) ^ 2
                gradient_a = 2 * residual * x
                gradient_b = 2 * residual * y
                gradient_c = 2 * residual * z
                gradient_b = 2 * residual * 1
             */
            da += residual * point.x;
            db += residual * point.y;
            dc += residual * point.z;
            dd += residual;
        }

        // Average the gradients
        da /= n;
        db /= n;
        dc /= n;
        dd /= n;

        // Update parameters
        a -= learning_rate * da;
        b -= learning_rate * db;
        c -= learning_rate * dc;
        d -= learning_rate * dd;

        // Check for convergence
        double gradient_magnitude = std::sqrt(da * da + db * db + dc * dc + dd * dd);
        std::cout << "gradient_magnitude: " << gradient_magnitude << '\n';
        if (gradient_magnitude < tolerance) {
            std::cout << "Converged after " << iter + 1 << " iterations.\n";
            break;
        }
    }
}

int main() {
    // Example points
    std::vector<Point3D> points = {
        {1.0, 2.0, 3.0},
        {2.0, 3.0, 5.0},
        {3.0, 4.0, 6.0},
        {4.0, 5.0, 7.0},
        {1.0, 1.0, 2.0}
    };

    try {
        double a, b, c, d;
        fitPlaneGradientDescent(points, a, b, c, d);

        std::cout << "Fitted Plane Equation: "
                  << a << "x + " << b << "y + " << c << "z + " << d << " = 0\n";

        double error = calculateError(points, a, b, c, d);
        std::cout << "Mean Squared Error: " << error << "\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
