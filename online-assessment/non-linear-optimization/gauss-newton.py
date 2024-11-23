import numpy as np

""" 
Assume model: y = ae^{bx}
"""
def gauss_newton(x_data, y_data, initial_params, max_iterations=100, tolerance=1e-6):
    """
    Gauss-Newton algorithm for non-linear least squares optimization.

    Parameters:
    x_data (array): The input data points.
    y_data (array): The observed output data points.
    initial_params (array): Initial guess for the parameters [a, b].
    max_iterations (int): Maximum number of iterations.
    tolerance (float): Tolerance for stopping criterion.

    Returns:
    params (array): Optimized parameters [a, b].
    """

    # Initialize parameters
    params = np.array(initial_params, dtype=float)

    # Iteratively update parameters
    for iteration in range(max_iterations):
        # Compute the residuals
        residuals = y_data - params[0] * np.exp(params[1] * x_data)

        # Compute the Jacobian matrix
        J = np.zeros((len(x_data), 2))
        J[:, 0] = -np.exp(params[1] * x_data)       # Partial derivative w.r.t a
        J[:, 1] = -params[0] * x_data * np.exp(params[1] * x_data)  # Partial derivative w.r.t b

        # Compute the update step using the normal equation
        delta_params = np.linalg.inv(J.T @ J) @ J.T @ residuals

        # Update the parameters
        params += delta_params
        print (f'iter: {iteration}, params: {params}')

        # Check for convergence
        if np.linalg.norm(delta_params) < tolerance:
            print(f'Converged in {iteration + 1} iterations')
            break
    else:
        print('Reached maximum iterations without convergence')

    return params

# Example data
x_data = np.array([0.1, 0.4, 0.6, 0.8, 1.0])
y_data = np.array([2.7, 3.0, 3.5, 4.0, 4.2])

# Initial guess for the parameters [a, b]
initial_params = [1.0, 0.1]

# Perform Gauss-Newton optimization
optimized_params = gauss_newton(x_data, y_data, initial_params)

print('Optimized parameters:', optimized_params)
