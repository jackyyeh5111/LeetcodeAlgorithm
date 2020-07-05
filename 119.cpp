class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        /*
            use 1d dp
            T:O((rowIndex+1)^2), S:O(1)
        */
        vector<int> ans(rowIndex+1,1);
        for(int row=0; row<=rowIndex; ++row) {
            int prev=ans[0];
            for (int col=1; col<row; ++col) {
                int tmp=ans[col];
                ans[col]+=prev;
                prev=tmp;
            }
        }
        return ans;
    }
};
