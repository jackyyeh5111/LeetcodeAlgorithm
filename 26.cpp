/***** Third Visit *****/
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int p=-1,n=nums.size();
        for (int i=0; i<n; ++i) {
            if (p==-1||nums[i]!=nums[p])
                swap(nums[++p],nums[i]);
        }
        return p+1;
    }
};

/***** Second Visit *****/
/*
    SORTED ARRAY
    1. binary search?
    2. 2 ptr solution? (v)
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i=0, n=nums.size();
        for (int j=0; j<n; ++j) {
            if(j>0&&nums[j]==nums[j-1]) continue;
            nums[i++]=nums[j];
        }
        return i;
    }
};

/***** First Visit *****/
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
