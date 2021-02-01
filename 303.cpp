class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        int csum=0;
        for (int num:nums) {
            csum+=num;
            dp.push_back(csum);
        }
    }

    int sumRange(int i, int j) {
        return i>0?dp[j]-dp[i-1]:dp[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
