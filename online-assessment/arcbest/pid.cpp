#include <iostream>
#include <chrono>
#include <thread>

class PIDController {
private:
    double kp; // Proportional gain
    double ki; // Integral gain
    double kd; // Derivative gain

    double prevError;      // Error from the previous step
    double integral;       // Accumulated integral
    double prevTime;       // Previous time in seconds

public:
    // Constructor
    PIDController(double kp, double ki, double kd)
        : kp(kp), ki(ki), kd(kd), prevError(0), integral(0), prevTime(0) {}

    // Compute PID output
    double compute(double setpoint, double current, double dt) {
        // Calculate error
        double error = setpoint - current;

        // Calculate integral
        integral += error * dt;

        // Calculate derivative
        double derivative = (error - prevError) / dt;

        // PID output
        double output = (kp * error) + (ki * integral) + (kd * derivative);

        // Update state
        prevError = error;

        return output;
    }
};

int main() {
    // PID coefficients
    double kp = 1.0;
    double ki = 0.5;
    double kd = 0.1;

    PIDController pid(kp, ki, kd);

    // Simulation variables
    double setpoint = 100.0; // Desired value
    double processValue = 0.0; // Current value of the process
    double dt = 0.1; // Time step (in seconds)

    std::cout << "Time\tSetpoint\tProcess Value\tControl Output\n";

    // Simulation loop
    for (int i = 0; i < 100; ++i) {
        double controlOutput = pid.compute(setpoint, processValue, dt);

        // Simulate process dynamics (example: system response)
        processValue += controlOutput * dt;

        // Print the results
        std::cout << i * dt << "\t" << setpoint << "\t\t" << processValue << "\t\t" << controlOutput << "\n";

        // Wait for the next cycle
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(dt * 1000)));
    }

    return 0;
}
