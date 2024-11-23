#include <iostream>
#include <vector>

// Function to convolve a matrix with a 1D kernel along rows
std::vector<std::vector<double>> convolve1DHorizontal(
    const std::vector<std::vector<double>>& input, const std::vector<double>& kernel) {
    int rows = input.size();
    int cols = input[0].size();
    int kSize = kernel.size();
    int halfK = kSize / 2;
    
    std::vector<std::vector<double>> output(rows, std::vector<double>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double sum = 0.0;
            for (int k = -halfK; k <= halfK; ++k) {
                int colIdx = j + k;
                if (colIdx >= 0 && colIdx < cols) {
                    sum += input[i][colIdx] * kernel[halfK + k];
                }
            }
            output[i][j] = sum;
        }
    }
    return output;
}

// Function to convolve a matrix with a 1D kernel along columns
std::vector<std::vector<double>> convolve1DVertical(
    const std::vector<std::vector<double>>& input, const std::vector<double>& kernel) {
    int rows = input.size();
    int cols = input[0].size();
    int kSize = kernel.size();
    int halfK = kSize / 2;
    
    std::vector<std::vector<double>> output(rows, std::vector<double>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double sum = 0.0;
            for (int k = -halfK; k <= halfK; ++k) {
                int rowIdx = i + k;
                if (rowIdx >= 0 && rowIdx < rows) {
                    sum += input[rowIdx][j] * kernel[halfK + k];
                }
            }
            output[i][j] = sum;
        }
    }
    return output;
}

int main() {
    // Example input matrix (5x5)
    std::vector<std::vector<double>> input = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    // 1D Gaussian kernel for horizontal and vertical convolution
    std::vector<double> gaussianKernel = {0.25, 0.5, 0.25};

    // Convolve along rows
    std::vector<std::vector<double>> tempResult = convolve1DHorizontal(input, gaussianKernel);
    
    // Convolve along columns
    std::vector<std::vector<double>> finalResult = convolve1DVertical(tempResult, gaussianKernel);

    // Print the final result
    for (const auto& row : finalResult) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
