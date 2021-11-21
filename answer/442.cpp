class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        /*
            T:O(n), S:O(n) with hashmap
            ------
            sorting and compare, T:O(nlogn), S:O(1)
            ------
            Try to reduce to S:O(1).
            4521 [4,3,2,7,8,2,3,1]
            ^ ^
            5521 [4,3,2,7,8,2,3,1,1]
              ^
            ------
            3300 [1,2,3,3]
            bit is not useful!!
            ------
            KEY!! 1 ≤ a[i] ≤ n (n = size of array)
            since we have only O(1) space, we cannot do counting sort (T:O(n)).
            Use sign bit to track if we met this element before.
        */
        vector<int> ans;
        for (int i=0; i<nums.size(); ++i) {
            int index=abs(nums[i])-1;
            if (nums[index]<0) ans.push_back(index+1);
            nums[index]=-nums[index];
        }
        return ans;
    }
};
