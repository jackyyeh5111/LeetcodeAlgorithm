class Solution {
public:
    // T:O(n^2), S:O(n)
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        /*
        a % b == 0
        b % c == 0
        -------------
        a % c == 0

        This could be solved with induction -> DP!!

        */
        if (nums.size()==0) return vector<int>{};
        sort(nums.begin(), nums.end());
        vector<int> prev(nums.size(), -1);
        vector<int> largest(nums.size(), 1);
        for (int i=0; i<nums.size(); ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[i]%nums[j]==0&&largest[i]<largest[j]+1){
                    largest[i]=largest[j]+1;
                    prev[i]=j;
                }
            }
        }
        int max_idx=0;
        for (int i=1; i<largest.size(); ++i) {
            if (largest[i]>largest[max_idx]) max_idx=i;
        }
        if (max_idx==-1) return vector<int>{nums[max_idx]};
        vector<int> ans;
        do {
            ans.push_back(nums[max_idx]);
            max_idx = prev[max_idx];
        } while(max_idx!=-1);

        return ans;
    }
};
