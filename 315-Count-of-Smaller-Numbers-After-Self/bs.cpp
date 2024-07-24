class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N);
        vector<int> arr;
        for (int i = N-1; i >= 0; i--) {
            auto it = lower_bound(arr.begin(), arr.end(), nums[i]);
            int pos = it - arr.begin();
            ans[i] = pos;
            arr.insert(it, nums[i]);
        }
        return ans;
    }
};

/* 
    Iterate array in reverse order, maintain the array along the way.

    5 2 6 1
    2 1 1 0
    
    array: 1 2 5 6
 */