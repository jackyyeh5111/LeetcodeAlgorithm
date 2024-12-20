#include <iostream>
#include <vector>

using namespace std;

// Function to compute the mean squared error
double computeCost(const vector<double>& X, const vector<double>& y, double bias, double slope) {
    int size = X.size();
    double cost = 0.0;
    
    for (int i = 0; i < size; ++i) {
        double prediction = bias + slope * X[i];
        cost += (prediction - y[i]) * (prediction - y[i]);
    }
    
    return cost / (2 * size);
}

// Function to perform gradient descent
void gradientDescent(const vector<double>& X, const vector<double>& y, double& bias, double& slope, double lr, int max_iter,
                     double tolerance = 1e-4) {
    int size = X.size();
    
    for (int iter = 0; iter < max_iter; ++iter) {
        double grad_bias = 0.0;
        double grad_slope = 0.0;
        double total_loss = 0.0;
        
        // 1) compute gradients
        /* 
            L: mx + - y + b = 0
            Loss = Sigma(y_gt - y_pred) ^ 2
                 = Sigma(residual) ^ 2

            da / dm = 2 * residual * x
            da / db = 2 * residual
         */
        for (int j = 0; j < size; ++j) {
            double prediction = bias + slope * X[j];
            double residual = prediction - y[j];
            total_loss += residual * residual;

            grad_bias += residual;
            grad_slope += (residual) * X[j];
        }
        
        // 2) update weights
        slope -= lr * grad_slope / size;
        bias -= lr * grad_bias / size;

        // 3) check for conergence
        std::cout << "iter: " << iter << " => total_loss: " << total_loss << '\n';
        if (total_loss < tolerance)
            break;
    }
}

int main() {
    // Example dataset: X is the input feature, y is the target value
    vector<double> X = {1, 2, 3, 4, 5}; // Input feature
    vector<double> y = {1, 2, 3, 4, 6}; // Target value

    double bias = 0.0; // Initial value for bias (intercept)
    double slope = 0.0; // Initial value for slope (slope)
    double lr = 0.01; // Learning rate
    int max_iter = 1000; // Number of max_iter for gradient descent

    // Perform linear regression using gradient descent
    gradientDescent(X, y, bias, slope, lr, max_iter);

    // Output the learned parameters
    cout << "Learned bias (intercept): " << bias << endl;
    cout << "Learned slope (slope): " << slope << endl;

    // Predict a new value using the learned model
    double prediction = bias + slope * 6.0; // Predict for X = 6
    cout << "Prediction for X = 6: " << prediction << endl;

    return 0;
}
