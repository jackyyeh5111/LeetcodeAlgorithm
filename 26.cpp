class Solution {
public:
    // T:O(n), S:O(1)
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<=1) return nums.size();
        int i=0;
        for (int j=1; j<nums.size(); ++j) {
            if (nums[j]!=nums[i]) {
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};
