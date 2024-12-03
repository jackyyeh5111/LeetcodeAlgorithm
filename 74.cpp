class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n_row = matrix.size();
        int n_col = matrix[0].size();
        
        // 1) init first col vector
        vector<int> first_col(n_row);
        for (int r = 0; r < n_row; r++)
            first_col[r] = matrix[r][0];

        // 2) check which row target should be in
        auto it = upper_bound(first_col.begin(), first_col.end(), target);
        if (it == first_col.begin()) return false;
        int target_row = it - first_col.begin() - 1;

        // 3) check if target is in that row
        it = lower_bound(matrix[target_row].begin(), matrix[target_row].end(), target);
        if (it == matrix[target_row].end()) return false;
        return *it == target;
    }
};