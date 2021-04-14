/***** Seventh Visit *****/
/*
           2 3 -2  4
    pos  1 2 6 1
    neg  1 1 1 -12 -48

    use pos/neg to find largest/smallest product subarray ends up to ith.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        if (nums.size()==0) return -1;
        int pos=1,neg=1,ans=nums[0];
        for (int num:nums) {
            if (num<0) swap(pos,neg);
            pos=max(pos*num,num);
            neg=min(neg*num,num);
            ans=max(pos,ans);
        }
        return ans;
    }
};

/***** Sixth Visit *****/
/*
         2 3 -2 4
   pos 0 2 6  0 0
   neg 0 0 0 -12-48
*/
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int pos=0,neg=0,n=nums.size(),ans=0;
        if (n==1) return nums[0];
        else ans=nums[0];
        for (int num:nums) {
            if (num>=0) {
                pos=max(pos*num,num);
                neg=min(neg*num,num);
            }
            else {
                swap(pos,neg);
                pos=max(pos*num,num);
                neg=min(neg*num,num);
            }
            ans=max(ans,pos);
        }
        return ans;
    }
};

/***** Fifth Visit *****/
/*
    2  3  -2  4  -2
    2  6   0  4   96
    0  0  -12 -48 -8
*/
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        if (nums.size()==0) return 0;
        int cmax=nums[0], cmin=nums[0], ans=nums[0];
        for (int i=1; i<nums.size(); ++i) {
            int num=nums[i];
            if (num==0) {cmin=0; cmax=0;}
            else {
                if (num<0) swap(cmax,cmin);
                cmax=max(cmax*num,num);
                cmin=min(cmin*num,num);
            }
            ans=max(ans,cmax);
        }
        return ans;
    }
};

/***** Fourth Visit *****/
/*
    pos: max product with right endian nums[i]
    neg: min product with right endian nums[i]

    2 3 -2  4 -2
    2 6 0   4  -48
    0 0 -12 -48 4
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        if (nums.size()==1) return nums[0]; // init pos/neg as fiirst element.
        int pos=0,neg=0,ans=0;
        for (int num:nums) {
            if (num==0) {pos=0; neg=0;} // could be ignored
            if (num<0) swap(pos,neg);
            pos=max(pos*num,num);
            neg=min(neg*num,num);
            ans=max(ans,pos);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int pos=nums[0],neg=nums[0],ans=nums[0];
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i]<0) swap(pos,neg);
            pos=max(pos*nums[i],nums[i]);
            neg=min(neg*nums[i],nums[i]);
            ans=max(ans,pos);
        }
        return ans;
    }
};

/***** Third Visit *****/
// FAIL AGAIN

/***** Second Visit *****/
/*
   contiguous array ->. cannot sort first.
   1. 2 ptr (V)
   2. moving window
   treat non-positive number as delimeter. Use a moving acc.
   T:O(n)/S:O(1)
   WRONG RESULT, contiguous negative number should take into consideration as well.
   -----
   brute force
   enumerate all contiguous array and check sum
   T:O(n^2)/S:O(1)
   -----
   Most naiive dp solution comes up when all numbers are positive, then we can
   have an induction with dp[i]=max(dp[i-1]*nums[i],nums[i]) where dp[i]
   denotes max contiguous product of subarray. But now we have negative num,

   We can keep another min product contiguous array, while we meet incoming
   negativie number, just switch the max dp and min dp, then our previous
   induction works again.
   -----
   -7 2 3 1 -3 1 2 -1 1 2
   DP solution
   imax: max contiguous array so far
   imin: min contiguous array so far
   if num < 0, swap imax,imin
   else if num == 0, imax/imin would be always 0, then replace to the next num.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int imax=nums[0],imin=nums[0],ans=nums[0];
        int n=nums.size();
        for (int i=1; i<n;  ++i) {
            if (nums[i]<0) swap(imax,imin);
            imax=max(nums[i],imax*nums[i]);
            imin=min(nums[i],imin*nums[i]);
            ans=max(imax,ans);
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        /*
            enumerate all possible contiguous subarray
            (n-1)+(n-2)+...+1 => T:O(n^2)
            ---------------------
            -10 2 3 -2 4
                all the way
                standalone
                continuous to last one
            ---------------------
            dp thought is correct but here we rely on multiple information from previous
            max_dp[i-1] i.e. largest multiplication so far
            min_dp[i-1] i.e. smallest multiplication so far
            dp[i]=max(nums[i],dp[i-1]*nums[i])
                i.e. contiguous maximum or start from i
        */
        int size=nums.size();
        if (size==0) return 0;
        int imax=nums[0], imin=nums[0];
        int ans=nums[0];
        for (int i=1; i<size; ++i) {
            if (nums[i]<0) swap(imax,imin);
            imax=max(nums[i],imax*nums[i]);
            imin=min(nums[i],imin*nums[i]);
            ans=max(ans,imax);
        }
        return ans;
    }
};
