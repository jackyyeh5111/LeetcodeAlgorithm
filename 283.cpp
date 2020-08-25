/*
    0  1  0  3  12
    ^  ^
    1  0. 0. 3. 12
       ^     ^
    1. 3. 0. 0. 12
          ^      ^
    1. 3. 12 0. 0
    ----
    Use 2 ptr i, j. i is to keep non-zero index, and j is used to iterate over the
    array.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int i=0,j=0,n=nums.size();
        if (n<=1) return;
        while(j<n) {
            if (nums[j]!=0) swap(nums[i++],nums[j]);
            j++;
        }
    }
};
