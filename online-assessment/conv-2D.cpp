#include <iostream>
#include <vector>
using namespace std;

std::vector<std::vector<int>> convolve2D(const std::vector<std::vector<int>>& input, const std::vector<std::vector<int>>& kernel) {
    int input_row = input.size();
    int input_col = input[0].size();
    int k_row = kernel.size();
    int k_col = kernel[0].size();

    // output matrix size
    int out_row = input_row - k_row + 1;
    int out_col = input_col - k_col + 1;
    vector<vector<int>> output(out_row, vector<int>(out_col));

    // apply conv
    for (int r = 0; r < out_row; r++) {
        for (int c = 0; c < out_col; c++) {
            for (int kr = 0; kr < k_row; kr++) {
                for (int kc = 0; kc < k_col; kc++) {
                    output[r][c] += input[r + kr][c + kc] * kernel[kr][kc];
                }
            }
        }
    }
    return output;
}

int main() {
    // Example input matrix
    std::vector<std::vector<int>> input = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    // Example kernel
    std::vector<std::vector<int>> kernel = {
        {1, 0},
        {0, -1}
    };

    // Perform 2D convolution
    std::vector<std::vector<int>> result = convolve2D(input, kernel);

    // Print the result
    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
