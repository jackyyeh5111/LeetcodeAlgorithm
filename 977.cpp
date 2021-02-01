/*
    2 ptr solution, start from large or min.
    Large one is more elegant
    T:O(n)/S:O(n)
*/

// Top Down T:O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=n-1, k=n-1;
        vector<int> ans(n,0);
        while (l<=r) {
            if (abs(nums[l])>nums[r]) ans[k--]=nums[l]*nums[l++];
            else ans[k--]=nums[r]*nums[r--];
        }
        return ans;
    }
};

// Bottom Up T:O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int n=nums.size(), i=0;
        while (i<n&&nums[i]<0) i++;
        int j=i-1;
        vector<int> ans;
        while (j>=0&&i<n) {
            if (abs(nums[j])>nums[i])
                ans.push_back(nums[i]*nums[i++]);
            else
                ans.push_back(nums[j]*nums[j--]);
        }
        while (j>=0) ans.push_back(nums[j]*nums[j--]);
        while (i<n) ans.push_back(nums[i]*nums[i++]);
        return ans;
    }
};
