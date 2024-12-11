class PIDController:
    def __init__(self, kp, ki, kd, setpoint=0.0):
        """
        Initialize the PID controller with specified gains and setpoint.
        :param kp: Proportional gain
        :param ki: Integral gain
        :param kd: Derivative gain
        :param setpoint: Desired target value
        """
        self.kp = kp
        self.ki = ki
        self.kd = kd
        self.setpoint = setpoint

        self.prev_error = 0
        self.integral = 0

    def update(self, current_value, dt):
        """
        Update the PID controller and calculate the control output.
        :param current_value: The current process value
        :param dt: Time step (in seconds)
        :return: Control output
        """
        # Calculate error
        error = self.setpoint - current_value

        # Proportional term
        p = self.kp * error

        # Integral term
        self.integral += error * dt
        i = self.ki * self.integral

        # Derivative term
        derivative = (error - self.prev_error) / dt if dt > 0 else 0
        d = self.kd * derivative

        # Compute total output
        output = p + i + d

        # Update previous error
        self.prev_error = error

        return output


# Example usage
if __name__ == "__main__":
    # Define PID gains
    kp = 1.0
    ki = 0.5
    kd = 0.1

    # Create a PID controller
    pid = PIDController(kp, ki, kd, setpoint=10.0)

    # Simulate a process
    current_value = 0.0
    dt = 0.1  # Time step in seconds
    for t in range(100):  # Simulate for 10 seconds (100 steps)
        output = pid.update(current_value, dt)
        current_value += output * dt  # Simulate process response
        print(f"Time: {t * dt:.1f}s, Output: {output:.2f}, Current Value: {current_value:.2f}")
