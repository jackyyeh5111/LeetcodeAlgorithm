/*
    It is guarenteed that only one duplicate num, and the range of nums is 1-n.
    Greedy to find the duplicate num while moving it to the right place.
    return the final pair.
    T:O(n) 1 pass / S:O(1)

    -----
    bit wise xor to find unique num in duplicate nums array, similar to problem 260.
     1 2 3 4
    [1,2,2,4]
    T:O(n) 3 pass / S:O(1)
*/

// T:O(n) 1 pass / S:O(1)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            while (nums[nums[i]-1]!=nums[i]) swap(nums[nums[i]-1],nums[i]);
            if (i+1!=nums[i]) ans={nums[i],i+1};
        }
        return ans;
    }
};

// T:O(n) 3 pass / S:O(1)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int t=0,n=nums.size();
        for (int i=0; i<n; ++i) {
            t^=(i+1);
            t^=nums[i];
        }
        int mask=t^(t&(t-1)),a=0,b=0;
        for (int i=0; i<n; ++i) {
            if ((i+1)&mask) a^=(i+1);
            else b^=(i+1);
            if (nums[i]&mask) a^=nums[i];
            else b^=nums[i];
        }
        for (int num:nums) {
            if (num==a) return {a,b};
        }
        return {b,a};
    }
};
