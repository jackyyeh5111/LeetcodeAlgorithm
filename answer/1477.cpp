/*
    Sliding window to find each possible contiguous array which sums up to target.
    Apply DP to save current min array
    dp[i] is the min length of contiguous array sums up to target.
    Say dp[i]=2, it means [dp[i-1],dp[i]] sums up to target.
    Then we can check if 2 + dp[i-2] is min answer or not. This will guarentee to be non-overlapped.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target)
    {
        int n=arr.size(), l=0, ans=INT_MAX, cur=0, min_len=INT_MAX;
        vector<int> dp(n,INT_MAX);
        for (int i=0; i<n; ++i) {
            cur+=arr[i];
            while (cur>target&&l<=i) cur-=arr[l++];
            if (target==cur) {
                int len=i-l+1;
                if (i-len>=0&&dp[i-len]!=INT_MAX)
                    ans=min(ans,len+dp[i-len]);
                min_len=min(min_len,len);
            }
            dp[i]=min_len;
        }
        return ans==INT_MAX?-1:ans;
    }
};
