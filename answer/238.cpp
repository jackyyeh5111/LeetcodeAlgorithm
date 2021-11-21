/***** Fifth Visit *****/
/*
      [1, 2, 3,4]
    l: 1  1  2 6
    r: 24 12 4 1
    use 2 variable l/r to maintain left/right conseccutive product.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int l=1,r=1,n=nums.size();
        vector<int> ans(n,1);
        for (int i=0; i<n; ++i) {
            ans[i]*=l; ans[n-i-1]*=r;
            l*=nums[i]; r*=nums[n-i-1];
        }
        return ans;
    }
};

/***** Fourth Visit *****/
/*
    prefix product?
    [1,2,3,4]
    -----
    O(n) time complexity and without using division
    O(1) constant space complexity
    -----
    [1,2,3,4]
    2 ptr?
    [1, 2, 3, 4]
     1  1  2  6
     24 12 4  1
  -> combine
    init: left=1, right=1

    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int l=1,r=1, n=nums.size();
        vector<int> ans(n,1);
        for (int i=0; i<n; ++i) {
            ans[i]*=l;
            ans[n-i-1]*=r;
            l*=nums[i]; r*=nums[n-i-1];
        }
        return ans;
    }
};

/***** Third Visit *****/
/*
    division 2 pass T:O(n)
    -----
    brute force T:O(n^2)
    -----
    2 ptr solution
    [1,2,3,4]
     ^     ^
     T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> dp(n,1);
        int left=1,right=1;
        for (int i=0; i<n; ++i) {
            dp[i]*=left; dp[n-i-1]*=right;
            left*=nums[i]; right*=nums[n-i-1];
        }
        return dp;
    }
};

/***** Second Visit *****/
/*
    1  2   3  4
    1  1   2  6 [forward: ->]
    24 12  4  1 [backward: <-]
    T:O(n)/S:O(n)

*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size(), f=1, b=1;
        vector<int> ans(n,1);
        for (int i=1; i<n; ++i) {
            f*=nums[i-1]; b*=nums[n-i];
            ans[i]*=f; ans[n-i-1]*=b;
        }
        return ans;
    }
};

/***** First Visit *****/
/*
    with division:
    product over all nums then divide each.
    T:O(n)/S:O(1)
    ------------------
    without division:
    brute force: T:O(n^2)/S:O(1)
    ------------------
    1 pass: left product
    1 pass: right product
    input 1  2  3  4
    left  1  1  2  6
    right 24 12 4  1
    T:O(n)/S:O(n)
    ------------------
    Follow up:
    replace left/right part as one accumulated variable
    T:O(n)/S:O(1)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> left,right,ans;
        left.push_back(1); right.push_back(1);
        for (int i=1; i<n; ++i) {
            left.push_back(left.back()*nums[i-1]);
            right.push_back(right.back()*nums[n-i]);
        }
        for (int i=0; i<n; ++i) {
            ans.push_back(left[i]*right[n-i-1]);
        }
        return ans;
    }
};
