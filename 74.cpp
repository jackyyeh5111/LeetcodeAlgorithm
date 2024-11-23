// visit 2
/* 
    Implement binary search from scratch.
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n_row = matrix.size();
        int n_col = matrix[0].size();

        // check target is in the range of matrix
        if (target < matrix[0][0] || target > matrix[n_row-1][n_col-1])
            return false;
        
        vector<int> col1(n_row);
        for (int i = 0; i < n_row; i++)
            col1[i] = matrix[i][0];

        // check which row the target belongs to
        // int tgt_row = upper_bound(col1.begin(), col1.end(), target) - col1.begin();
        int tgt_row = binarySearch(col1, target, true);
        tgt_row -= 1;

        // check if the target is in that particular row
        // auto it = lower_bound(matrix[tgt_row].begin(), matrix[tgt_row].end(), target);
        int idx = binarySearch(matrix[tgt_row], target, false);
        if (idx == n_col) return false;
        return matrix[tgt_row][idx] == target;
    }
    int binarySearch(const vector<int> &vec, int target, bool is_upper_bound) {
        int left = 0;
        int right = vec.size(); // notice here, not vec.size() - 1 !!!

        /* 
            tgt = 5
            1 3 
                l
                r
              m
         */
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (vec[mid] == target)
                return is_upper_bound ? mid + 1 : mid;
            else if (vec[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};


class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n_row = matrix.size();
    int n_col = matrix[0].size();

    // check target is in the range of matrix
    if (target < matrix[0][0] || target > matrix[n_row - 1][n_col - 1])
      return false;

    vector<int> col1(n_row);
    for (int i = 0; i < n_row; i++) col1[i] = matrix[i][0];

    // check which row the target belongs to
    int tgt_row = upper_bound(col1.begin(), col1.end(), target) - col1.begin();
    tgt_row -= 1;

    // check if the target is in that particular row
    auto it =
        lower_bound(matrix[tgt_row].begin(), matrix[tgt_row].end(), target);
    if (it == matrix[tgt_row].end()) return false;
    return *it == target;
  }
}