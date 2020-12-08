/***** Second Visit *****/
/*
    In-place rotation
    swap \ diagonose then swap each col.
    T:O(n^2)/S:O(1)
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for (int i=0; i<n; ++i) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

/***** First Visit *****/
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
