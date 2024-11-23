#include <iostream>
#include <vector>

// Function to perform 1D convolution
std::vector<double> conv1D(const std::vector<double>& input, const std::vector<double>& kernel) {
    int inputSize = input.size();
    int kernelSize = kernel.size();
    int outputSize = inputSize - kernelSize + 1; // Output size after valid convolution

    if (kernelSize > inputSize) {
        std::cerr << "Kernel size should be smaller than or equal to input size" << std::endl;
        return {};
    }

    std::vector<double> output(outputSize);

    for (int i = 0; i < outputSize; ++i) {
        double sum = 0.0;
        for (int j = 0; j < kernelSize; ++j) {
            sum += input[i + j] * kernel[j]; // Dot product of input segment and kernel
        }
        output[i] = sum;
    }

    return output;
}

int main() {
    // Example input and kernel
    std::vector<double> input = {1, 2, 3, 4, 5};
    std::vector<double> kernel = {1, 0, -1};

    std::vector<double> result = conv1D(input, kernel);

    // Print the result
    std::cout << "Convolution Result: ";
    for (double val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
