#include "utils.hpp"

using namespace std;
/*
ref:
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise
 */

/*  min heap
  這一題因為 matrix 是有 sorted 過，所以用 mean heap 比較適合
  time: O(k * log(m))
  space: O(m)
*/
class Solution4 {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    auto comp = [](pair<int, int> p1, pair<int, int> p2) {
      return p1.first > p2.first;
    };
    std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
        pq(comp);

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> col_idxs(rows, 1);
    for (int i = 0; i < rows; i++) pq.push({matrix[i][0], i});

    for (int i = 0; i < k - 1; i++) {
      int pop_row = pq.top().second;
      pq.pop();
      if (col_idxs[pop_row] < cols)
        pq.push({matrix[pop_row][col_idxs[pop_row]], pop_row});

      col_idxs[pop_row]++;
    }

    return pq.top().first;
  }
};

/* MaxHeap
  維持著 heap size
  time: O(m * n * log(k))
  space: O(k)
*/
class Solution3 {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    std::priority_queue<int> pq;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        pq.push(matrix[i][j]);

        if (pq.size() > k) pq.pop();
      }
    }

    return pq.top();
  }
};

/* MaxHeap
- This approach leads this problem become the same with 215. Kth Largest Element
in an Array,
- which doesn't take the advantage that the matrix is already sorted by rows and
by columns.

這樣錯！ 不能讓 heap size 一直增加啊！ 這樣複雜度會很高
 */
class Solution2 {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    std::priority_queue<int, vector<int>> pq;
    int n_rows = matrix.size();
    int n_cols = matrix[0].size();
    for (int i = 0; i < n_rows; i++) {
      for (int j = 0; j < n_cols; j++) {
        pq.push(matrix[i][j]);
      }
    }

    for (int i = 0; i < n_rows * n_cols - k; i++) {
      pq.pop();
    }

    return pq.top();
  }
};

/* binary search
  直接用 value 來做 binary，因為沒有辦法保證 idx 小的 value 也比較小
*/
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int matrixSize = matrix.size();
    int head = matrix[0][0];
    int tail =
        matrix[matrixSize - 1][matrixSize - 1];  // because of n x "n" matrix
                                                 // (dont care matrixColSize)
    int j;  // use this index to get column index for the upper bound of
            // ascending matrix[]
    while (head < tail) {
      int mid = head + (tail - head) / 2;
      int ctr = 0;
      for (int i = 0; i < matrixSize; i++) {
        // Find the column upper bound
        for (j = 0; j < matrixSize; j++) {
          if (matrix[i][j] > mid) {
            break;
          }
        }

        ctr += j;
        if (j == 0 || ctr >= k) {
          break;
        }
      }

      if (ctr < k) {
        head = mid + 1;
      } else {
        tail = mid;
      }
    }

    return tail;
  }
};

int main(int argc, char** argv) {
  vector<std::vector<int>> nums{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  int k = 8;
  Solution4 sol;
  int ans = sol.kthSmallest(nums, k);

  std::cout << "ans:" << ans << '\n';
  return 0;
}