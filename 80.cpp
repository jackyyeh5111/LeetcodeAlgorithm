/***** Second Visit *****/
/*
    Array
    1. sort help< bucket sort?
    2. binary search
    3. 2 ptr
    4. running ptr
    5. 2-D array:DP/greedy/divide & conquer
    -----
    use l to check return length, i as a running ptr.
    1 1 1 2 2 3
      ^
          ^
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int l=0,n=nums.size();
        if (n==0) return 0;
        for (int i=1; i<n; ++i) {
            if (nums[i]!=nums[l]) swap(nums[i],nums[++l]);
            else {
                swap(nums[i++],nums[++l]);
                while (i<n&&nums[i]==nums[l]) ++i;
                --i;
            }
        }
        return l+1;
    }
};

/***** First Visit *****/
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i=0;
        for (const int &num:nums) {
            if (i<2||num>nums[i-2])
                nums[i++]=num;
        }
        return i;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        // remove duplicate AT MOST TWICE
        // use 2 pointer, say i j
        // i indicates the value we checked which is not duplicated over twice.
        // j travel the vector all the way.
        // use another variables to record current value and its frequency.
        if (nums.size()==0) return 0;
        int i=1; int val=nums[0]; int counter=1;
        for (int j=1; j<nums.size(); ++j) {
            if (nums[j]==val) {
                if (counter<2) {nums[i++]=nums[j]; counter++;}
            }
            else { counter=1; val=nums[i++]=nums[j]; }
        }
        return i;
    }
};
