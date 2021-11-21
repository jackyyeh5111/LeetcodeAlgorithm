/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        unordered_map<int, int> table;
        table[0] = -1;
        int sum = 0; int max_length = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]==1) sum+=1;
            if (nums[i]==0) sum-=1;
            if (table.find(sum) !=table.end()){
                max_length = max(max_length, i-table[sum]);
            }
            else
                table[sum] = i;
        }
        return max_length;

    }
};
