/***** Fourth Visit *****/
/*
    for each i , find the min one, k, larget than nums[i] from right to left,
    then keep find if any mum larget than k
    T:O(n^2)
    -----
    find the current min for each i from left to right.
    For each num from right to left, treat it as "3" and binary search on the seen nums to check if "2" exists
    T:O(nlogn)/S:O(n)
    -----
    mono stack [decresing]
    the top of stack is always the largest we've seen so far.
    T:O(n)/S:O(n)
*/
// T:O(n)
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        stack<int> s;
        int n=nums.size(),second=INT_MIN;
        for (int i=n-1; i>=0; --i) {
            if (nums[i]<second) return true;
            while (!s.empty()&&s.top()<nums[i]) {
                second=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

// T:O(nlogn)
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n=nums.size(),cur=INT_MAX;
        vector<int> cmins;
        for (int num:nums) {
            cur=min(cur,num);
            cmins.push_back(cur);
        }
        set<int> ms;
        for (int i=n-1; i>=1; --i) {
            if (ms.size()>0) {
                auto it=ms.lower_bound(nums[i]);
                if (it!=ms.begin()) it=prev(it);
                if (*it>cmins[i-1]&&nums[i]>*it) return true;
            }
            ms.insert(nums[i]);
        }
        return false;
    }
};

/***** Third Visit *****/
/*
    1. Maintain a current min array to check "1"32 from left to right.
    2. Maintain an online sorting from right to left and conduct a binary search to find 1"3""2".
    T:O(nlogn+n)/S:O(n)
    -----
    Conduct a monostack from right to left with decreasing order.
    The top of stack indicates 1"3"2, use another variable to record the num we poped eachc time, it indicates the best 13"2".
    T:O(n)/S:O(n)
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n=nums.size(),second=INT_MIN;
        stack<int> s;
        for (int i=n-1; i>=0; --i) {
            if (nums[i]<second) return true;
            else {
                while(!s.empty()&&nums[i]>s.top()) {
                    second=s.top();
                    s.pop();
                }
                s.push(nums[i]);
            }
        }
        return false;
    }
};

/***** Second Visit *****/
/*
    brute force:
    for i in range(n):
      cmax=nums[i+1]
      for j in range(i+2,n,1):
        check if cmax>nums[j] && cmax>nums[i]
    T:O(n^2)/S:O(1)
    -----
    MONO stack:
    decreasing order from right to left
    T:O(n)/S:O(n)
    -----
    binary search on right part, left cmin could be handled in one pass.
    T:O(nlogn)/S:O(n)
    [3,1,[2],4]
     cmins.   binary search
*/

// stack
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n=nums.size();
        stack<int> s;
        int idx2=INT_MIN;
        for (int i=n-1; i>=0; --i) {
            if (nums[i]<idx2) return true;
            while(!s.empty()&&s.top()<nums[i]) {
                idx2=s.top(); s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

// binary search
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> cmins;
        int cmin=INT_MAX;
        for (int num:nums) {
            cmin=min(cmin,num);
            cmins.push_back(cmin);
        }
        set<int> ms;
        for (int i=n-1; i>=1; --i) {
            if (ms.size()!=0) {
                auto it=ms.lower_bound(nums[i]);
                if (it!=ms.begin()) it=prev(it);
                if (cmins[i-1]<*it&&*it<nums[i]) return true;
            }
            ms.insert(nums[i]);
        }
        return false;
    }
};

/***** First Visit *****/
/*
    top-down stack approach.
    We use stack to record current 3, 2 val. If we meet a larger incoming num, the num on the top of stack becomes 2. Thus we will have all valid 3,2 pair.
    We can check thee incoming num if its the smallest one, i.e. 1.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n=nums.size();
        int mid=INT_MIN;
        stack<int> s;
        for (int i=n-1; i>=0; --i) {
            if (mid>nums[i]) return true;
            while (!s.empty()&&nums[i]>s.top()) {
                mid=s.top(); s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

/*
    brute force:
    For each position k, find all pairs in the range of 0 - k-1 and see if 132 pattern
        in (nums[i],nums[j],nums[k]) where i<j<k
        T:O(n^3)/S:O(1)
    -----
    ARG sort and use a set to record if we've met or not.
    The domain of num will reduce to 1 ~ n
    T:O(nlogn)/S:O(n)
    [3,5,0,3,4]
    [2,5,1,3,4]
    -----
    Use a stack to record ascending order and a local min.
    See if the incoming num is in the range of [local min, s.top()]
    T:O(n)/S:O(n)
    FAIL case: [3,5,0,3,4]
    -----
    AC, record every ascending region and binary search on these regions
    T(n) = log1 + ... + log(n/2) = O(nlogn)
    S: O(n)
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n=nums.size();
        if (n<=2) return false;
        set<vector<int>> regions;
        vector<int> region{nums[0],nums[0]};
        auto cmp = [](int val, auto r){
            return r[0]<val;
        };
        auto cmp2 = [](auto r, int val){
            return r[1]<val;
        };
        for (int i=1; i<n; ++i) {
            if (nums[i]>=region[1]) region[1]=nums[i];
            else {
                if (region[0]<region[1]) regions.insert(region);
                region[0]=region[1]=nums[i];
            }
            auto it=upper_bound(regions.begin(),regions.end(),nums[i],cmp);
            if(it!=regions.end()) it=next(it,1);
            it=lower_bound(regions.begin(),it,nums[i],cmp2);
            if (it!=regions.end()&&nums[i]<(*it)[1]&&nums[i]>(*it)[0])
                return true;
        }
        return false;
    }
};
