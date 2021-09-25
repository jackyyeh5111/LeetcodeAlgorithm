/***** Fourth Visit *****/
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n=nums.size(),cmax=0;
        for (int i=0; i<n; ++i) {
            if (cmax>=i) cmax=max(cmax,i+nums[i]);
            if (cmax>=n-1) return true;
            else if (cmax<i) return false;
        }
        return -1;//not gonna reach here
    }
};

/***** Third Visit *****/
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n=nums.size(), cur=0;
        for (int i=0; i<n; ++i) {
            if (cur>=i) cur=max(cur,nums[i]+i);
            else break;
            if (cur>=n-1) return true;
        }
        return false;
    }
};

/***** Second Visit *****/
/*
    brute force:
    check each steps with at most n nums.
    T:O(n^2)/S:O(1)
    -----
    Array:
    1. 2 ptr
    2. binary search
    3. could. sort help? no.
    4. moving window
    5. DP/greedy/divide&conquer
    -----
    Use a ptr to record max position we can reach so far, and another running ptr to traverse.
    if running ptr is larger than max pos, return false ;
    else if max position larger than array size, return true;
    T:1 pass O(n)/S:O(1)
*/
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int i=0,n=nums.size();
        for (int k=0; k<n; ++k) {
            if(k>i) return false;
            i=max(i,k+nums[k]);
            if(i>=n-1) return true;
        }
        return i>=n-1; // not going to reach here.
    }
};

/***** First Visit *****/
/******************** Greedy **************************/
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int idx=0; int dst=nums.size()-1;
        int max_step=0;
        while (idx<dst&&max_step<dst) {
            int local_max=0;
            for(int i=idx; i<=max_step; ++i) local_max=max(i+nums[i],local_max);
            if(local_max==max_step&&local_max<dst) return false;
            idx=max_step+1;
            max_step=local_max;
        }
        return true;

    }
};

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int i=0;
        for (int reach=0; i<nums.size()&&i<=reach; ++i)
            reach=max(reach, i+nums[i]);
        return i==nums.size();

    }
};
