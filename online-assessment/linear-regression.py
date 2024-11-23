import numpy as np

class LinearRegressionGD:
    def __init__(self, learning_rate=0.01, n_iterations=1000):
        self.learning_rate = learning_rate
        self.n_iterations = n_iterations
        self.theta = None

    def fit(self, X, y):
        # Add a bias term (column of ones) to the input data
        X = np.c_[np.ones(X.shape[0]), X]
        m, n = X.shape

        # Initialize parameters (theta) with zeros
        self.theta = np.zeros(n)

        # Gradient descent
        for _ in range(self.n_iterations):
            # Compute the prediction
            y_pred = X.dot(self.theta)

            # Compute the gradient
            gradient = (1 / m) * X.T.dot(y_pred - y)

            # Update the parameters
            self.theta -= self.learning_rate * gradient

    def predict(self, X):
        # Add a bias term (column of ones) to the input data
        X = np.c_[np.ones(X.shape[0]), X]
        return X.dot(self.theta)

# Example usage
if __name__ == "__main__":
    # Generate some synthetic data
    np.random.seed(0)
    X = 2 * np.random.rand(100, 1)
    y = 4 + 3 * X + np.random.randn(100, 1)

    # Train linear regression model
    model = LinearRegressionGD(learning_rate=0.01, n_iterations=1000)
    model.fit(X, y)

    # Make predictions
    X_new = np.array([[0], [2]])
    y_pred = model.predict(X_new)
    print(f"Predictions: {y_pred}")
