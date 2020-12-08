/***** Second Visit *****/
/*
    T:O(n)/S:O(1)
    -----
    [3,0,1]
    [0,1,3]
    -----
    [9,6,4,2,3,5,7,0,1]
    [0,1,2,3,4,5,6,7,9]
    -----
    2 pass swapping val by index
    T:O(n)/S:O(1)
    -----
    bit manipulation
    [3,0,1], n=3
     0 1 2
    Only 2 is the single number.
    Reduce to Single Number Finding Problem
    T:O(n)/S:O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n=nums.size(),ans=n;
        for (int i=0; i<n; ++i) {
            ans^=i; ans^=nums[i];
        }
        return ans;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n=nums.size();
        for (int i=0; i<n; ++i) {
            while (nums[i]<n&&nums[i]!=i)
                swap(nums[i],nums[nums[i]]);
        }
        for (int i=0; i<n; ++i) {
            if (i!=nums[i]) return i;
        }
        return n;
    }
};

/***** First Visit *****/
/*
    Sort and compare iteratively
    T:O(nlogn)/S:O(1) with in-place soring
    ----------------
    Use a set and find min/max, then iteratively check in min ~ max
    T:O(n)/S:O(n)
    ----------------
    find min and subtract all elements, the value turns out to be index.
    set nums[index] as negative if exists, then iteratively find which
    index is positively, bingo!
    Note that we should avoid 0-base due to sign.
    T:O(n)/S:O(1)

    [-2,-1,0,1,3] -> [1,2,3,4,6]

    [-3,-2,-1,0,2,3] -> [1,2,3,4,6,7] -> [-1,-2,-3,-4,6,-7]
    [9,6,4,2,3,5,7,0,1] -> [-10,-7,-5,-3,-4,-6,-8,-1,2]
    2145
    ----------------
    Bit Manipulation

    Because we know that nums contains n numbers and that it is missing exactly one number on the range [0..n-1][0..n−1], we know that n definitely replaces the missing number in nums. Therefore, if we initialize an integer to n and XOR it with every index and value, we will be left with the missing number.
*/

/************ bit manipulation ***********/
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int ans=nums.size();
        for (int i=0; i<nums.size(); ++i) {
            ans ^= i; ans ^= nums[i];
        }
        return ans;
    }
};

/************ for this question ************/
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n=nums.size();
        for (int i=0; i<n; ++i) nums[i]+=1;
        for (int i=0; i<n; ++i) {
            if (abs(nums[i])>n) continue;
            nums[abs(nums[i])-1]*=-1;
        }
        for (int i=0; i<n; ++i) {
            if (nums[i]>0) return i;
        }
        return n;
    }
};

/************ General case for -m ~ n and find missing num ************/
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int lb=INT_MAX;
        for (int num:nums) lb=min(lb,num);
        int n=nums.size();
        for (int i=0; i<n; ++i) {
            nums[i]=nums[i]-lb+1;
        }
        for (int i=0; i<n; ++i) {
            if (nums[i]>n) continue;
            nums[abs(nums[i])-1]*=-1;
        }
        for (int i=0; i<n; ++i) {
            if (nums[i]>0) return i+lb;
        }
        return n+lb;
    }
};
