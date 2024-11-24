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
    // init
    a = 1.0;
    b = 1.0;
    c = 1.0;
    d = 1.0;
    
    for (int iter = 0; iter < max_iters; iter++) {
      // 1) compute gradients
      /* 
        Plane = ax + by + cz + b = 0
        Loss  = Sigma(y_gt - y_pred) ^ 2
              = Sigma(residual) ^ 2

        da / DL = 2 * residual * x
        db / DL = 2 * residual * y
        dc / DL = 2 * residual * z
        dd / DL = 2 * residual * 1
       */
      double da = 0.0, db = 0.0, dc = 0.0, dd = 0.0;
      double total_loss = 0.0;
      for (const auto& pt : points) {
        double residual = a * pt.x + b * pt.y + c * pt.z + d;
        total_loss += residual * residual;

        da += residual * pt.x;
        db += residual * pt.y;
        dc += residual * pt.z;
        dd += residual;
      }

      // [Optional] Average the gradients
      int n = points.size();
      da /= n;
      db /= n;
      dc /= n;
      dd /= n;


      // 2) update weights
      a -= learning_rate * da;
      b -= learning_rate * db;
      c -= learning_rate * dc;
      d -= learning_rate * dd;

      // 3) check for conergence
      std::cout << "iter: " << iter << " => total_loss: " << total_loss << '\n';
      if (total_loss < tolerance)
        break;
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
