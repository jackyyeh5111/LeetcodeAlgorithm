/* 
    1. return false if two matrices dimension not aligned
    2. replace std::vector with std::array
    3. Use 1D matrix to mimic 2D matrix (1D matrix has contiguous memory allocation, so faster)
    4. multi-thread
        - one thread in charge of a row
        - one thread in charge of element
 */
#include <iostream>
#include <vector>

using namespace std;

 bool multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result) {

    int rowsA = A.size();
    int rowsB = B.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    if (colsA != rowsB) return false;

    // init result size here
    result.resize(rowsA, vector<int>(colsB));

    /* 
      a:
        1 2 3
        4 5 6

      B:
        1 2
        4 5
        7 8
     */
     std::thread

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            std::atomic<int> sum = 0;
            for (int k = 0; k < colsA; ++k) {
                // lock
                sum += A[i][k] * B[k][j];
                // unlock
            }
            result[i][j] = sum;

            // row_result.push_back(sum);
        }
        // result[i] = row_result;
        // result.push_back(row_result);
    }

    return true;
}

int main() {
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    vector<vector<int>> result = multiplyMatrices(A, B);

    // Print the result
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[0].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}