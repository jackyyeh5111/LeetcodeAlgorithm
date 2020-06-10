class Solution {
public:
    // T:O(n^2)
    void rotate(vector<vector<int>>& matrix)
    {
        reverse(matrix.begin(), matrix.end()); //O(n)
        for (int j=0; j<matrix.size(); ++j) { //O(n^2)
            for (int i=0; i<=j; ++i) {
                swap(matrix[j][i], matrix[i][j]);
            }
        }
    }
};
