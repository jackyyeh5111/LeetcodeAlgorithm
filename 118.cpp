/***** Second Visit *****/
// T:O(n^2)/S:O(n^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        if (numRows>0) ans.push_back(vector<int>{1});
        for (int i=1; i<numRows; ++i) {
            ans.push_back(vector<int>{1});
            for(int j=0; j<i-1; ++j)
                ans[i].push_back(ans[i-1][j]+ans[i-1][j+1]);
            ans[i].push_back(1);
        }
        return ans;
    }
};

/***** First Visit *****/
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
