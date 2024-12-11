#include <iostream>
#include <vector>

class KalmanFilter {
public:
    KalmanFilter(double initialEstimate, double initialErrorCovariance, double processNoise, double measurementNoise)
        : estimate_(initialEstimate), errorCovariance_(initialErrorCovariance), processNoise_(processNoise), measurementNoise_(measurementNoise) {}

    // Prediction step: Predict the state (this is for a constant velocity model, but can be adapted)
    void predict() {
        // Assuming the system has a constant velocity (state model), no change to the estimate
        estimate_ = estimate_;  // In more complex systems, this could be a model update
        errorCovariance_ += processNoise_;  // Process noise is added to the covariance
    }

    // Update step: Incorporate the new measurement into the state estimate
    void update(double measurement) {
        // Kalman gain
        double kalmanGain = errorCovariance_ / (errorCovariance_ + measurementNoise_);
        
        // Update estimate with measurement
        estimate_ = estimate_ + kalmanGain * (measurement - estimate_);
        
        // Update error covariance
        errorCovariance_ = (1 - kalmanGain) * errorCovariance_;
        std::cout << "kalmanGain_: " << kalmanGain << '\n';
        std::cout << "errorCovariance_: " << errorCovariance_ << '\n';
    }

    // Get the current state estimate
    double getEstimate() const {
        return estimate_;
    }
    double geterrorCovariance() const {
        return errorCovariance_;
    }

private:
    double estimate_;  // Estimated state
    double errorCovariance_;  // Error covariance
    double processNoise_;  // Process noise covariance
    double measurementNoise_;  // Measurement noise covariance
};

int main() {
    // Initial state estimate, error covariance, process noise, measurement noise
    KalmanFilter kf(0.0, 1.0, 1.0, 2.0);

    // Simulated noisy measurements (e.g., sensor readings)
    std::vector<double> measurements = {5.0, 6.0, 7.0, 9.0, 10.0};
    // std::vector<double> measurements = {5.0,5.0,5.0,5.0,5.0,5.0,5.0};

    std::cout << "Initial state estimate: " << kf.getEstimate() << std::endl;

    // Perform Kalman filter estimation
    for (size_t i = 0; i < measurements.size(); ++i) {
        kf.predict();  // Prediction step
        kf.update(measurements[i]);  // Update step with new measurement

        std::cout << "Measurement: " << measurements[i]
                  << ", Updated estimate: " << kf.getEstimate() 
                  << ", Updated errorCovariance_: " << kf.geterrorCovariance()
                  << std::endl;
    }

    return 0;
}
