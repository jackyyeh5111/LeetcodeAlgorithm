class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        /*
            each mode, say pascal[row][col]=pascal[row-1][col-1]+pascal[row-1][col]
            T:O(numRows^2), S:O(numRows^2)
        */
        vector<vector<int>> ans;
        for (int row=0; row<numRows; ++row) {
            vector<int> cur(row+1,1);
            for (int col=1; col<row; ++col) {
                cur[col]=ans[row-1][col-1]+ans[row-1][col];
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
