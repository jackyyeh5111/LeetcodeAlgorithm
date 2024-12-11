""" 
    Closed form
"""
import numpy as np

# Input features (X) and target values (y)
X = np.array([[1, 1], [1, 2], [1, 3]])  # Add bias term (column of 1s)
y = np.array([1, 2, 3])

# Closed-form solution
theta = np.linalg.inv(X.T @ X) @ X.T @ y
print("Closed-Form Theta:", theta)

""" 
    Gradient descent
"""
import numpy as np

# Input features (X) and target values (y)
X = np.array([[1, 1], [1, 2], [1, 3]])  # Add bias term (column of 1s)
y = np.array([1, 2, 3])

# Parameters
theta = np.zeros(X.shape[1])  # Initialize theta (weights)
alpha = 0.01  # Learning rate
iterations = 1000  # Number of iterations

# Gradient descent
for _ in range(iterations):
    gradient = (X.T @ (X @ theta - y)) / len(y)
    theta -= alpha * gradient

print("Gradient Descent Theta:", theta)
