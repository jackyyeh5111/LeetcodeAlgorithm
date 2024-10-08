#include <iostream>
#include <vector>

using namespace std;
using Matrix = std::vector<std::vector<double>>;
Matrix averagePooling(const Matrix& input, int kernelSize, int stride) {
  int inputRows = input.size();
  int inputCols = input[0].size();

  // Step 1: Create the prefix sum array
  Matrix prefixSum(inputRows + 1, std::vector<double>(inputCols + 1, 0.0));

  // Calculate the prefix sums
  for (int i = 1; i <= inputRows; ++i) {
    for (int j = 1; j <= inputCols; ++j) {
      prefixSum[i][j] = input[i - 1][j - 1] + prefixSum[i - 1][j] +
                        prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
    }
  }

  // Step 2: Perform average pooling
  int outputRows = (inputRows - kernelSize) / stride + 1;
  int outputCols = (inputCols - kernelSize) / stride + 1;
  Matrix output(outputRows, std::vector<double>(outputCols, 0.0));

  for (int i = 0; i < outputRows; ++i) {
    for (int j = 0; j < outputCols; ++j) {
      int rowStart = i * stride;
      int colStart = j * stride;
      int rowEnd = rowStart + kernelSize - 1;
      int colEnd = colStart + kernelSize - 1;

      // kernelSize = 2
      // rowStart = 1
      // colStart = 1
      // rowEnd = 2
      // colEnd = 2

      // Calculate the sum of the pooling window using the prefix sum
      double sum =
          prefixSum[rowEnd + 1][colEnd + 1] - prefixSum[rowStart][colEnd + 1] -
          prefixSum[rowEnd + 1][colStart] + prefixSum[rowStart][colStart];

      // Calculate the average and store it in the output
      output[i][j] = sum / (kernelSize * kernelSize);
    }
  }

  return output;
}

Matrix averagePoolingJacky(const Matrix& input, int kernelSize, int stride) {
  int n_row = input.size();
  int n_col = input[0].size();
  // corner prefix sum
  Matrix prefix(n_row + 1, vector<double>(n_col + 1, 0.0));
  for (int r = 1; r <= n_row; r++) {
    for (int c = 1; c <= n_col; c++) {
      prefix[r][c] = prefix[r - 1][c] + prefix[r][c - 1] -
                     prefix[r - 1][c - 1] + input[r - 1][c - 1];
    }
  }

  std::cout << "Output after prefix:" << std::endl;
  for (const auto& row : prefix) {
    for (double val : row) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }

  /*
      X X X X
      X 1 2 X
      X 3 4 X
      X X X X
   */

  // do avg pooling
  int row_result = (n_row - kernelSize) / stride + 1;
  int col_result = (n_col - kernelSize) / stride + 1;
  int num_ele = kernelSize * kernelSize;
  Matrix result(row_result, vector<double>(col_result));
  for (int r = 0; r < row_result; r++) {
    for (int c = 0; c < col_result; c++) {
      int row_start = r * stride;
      int row_end = row_start + kernelSize - 1;
      int col_start = c * stride;
      int col_end = col_start + kernelSize - 1;
      result[r][c] =
          prefix[row_end + 1][col_end + 1] - prefix[row_start][col_end + 1] -
          prefix[row_end + 1][col_start] + prefix[row_start][col_start];
      
      result[r][c] /= num_ele;
    }
  }
  return result;
}
int main() {
  // Example input matrix
  Matrix input = {{1.0, 2.0, 3.0, 4.0},
                  {5.0, 6.0, 7.0, 8.0},
                  {9.0, 10.0, 11.0, 12.0},
                  {13.0, 14.0, 15.0, 16.0}};

  // Pooling parameters
  int kernelSize = 2;
  int stride = 2;

  // Perform average pooling
  Matrix output = averagePoolingJacky(input, kernelSize, stride);

  // Display the output
  std::cout << "Output after average pooling:" << std::endl;
  for (const auto& row : output) {
    for (double val : row) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
