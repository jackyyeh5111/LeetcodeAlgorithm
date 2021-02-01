/***** Third Visit *****/
/*
    dp[i][j] denotes max coins we gain from idx i to j.

    a i - - x - - - j b
    for idx i to j, we take all idx inside into consideration.
    For example, the coins we can get thru x is x*a*b+dp[i][x-1]+dp[x+1][j]

    We can ieteratively complete the above ALG by bottom up DP in terms of len.
    Here, len equals to j-i. While we are doing dp[i][j], it is guqreenteed that all the subregions inside i~j is done before.
    T:O(n^3)/S:O(n^2)
*/

/***** Second Visit *****/
/*
    1 5 5 5 5 5 1
        ^ .   ^
    T:O(n^3)/S:O(n^2 )
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for (int len=0; len<n; ++len) {
            for (int i=1; i+len<=n; ++i) {
                for (int j=i; j<=i+len; ++j) {
                    int coins=nums[j]*nums[i-1]*nums[i+len+1];
                    dp[i][i+len]=max(dp[i][i+len],
                                     coins+dp[i][j-1]+dp[j+1][i+len]);
                }
            }
        }
        return dp[1][n];
    }
};

/***** First Visit *****/
/*
    [3,1,5,8]
    burst from the smallest one.
    1->3->5->8
    index: O(1)
    delete:O(1)
    left/right:O(1)
    double linked list T:O(n) + sortT:O(nlogn) / S:O(n)
    -----
    But how do we handle the nums with same value?
    [3,1,3,8]
     0 1 2 3
     3 1 2 3
     1->2->0->3 9+72+24+8
     1->0->2->3 9+9+24+8
     1,1 3,1 1,8 ,3,1
    -----
    DP solution
    dp[i][j] denotes max coins we can get from i to j
    Refers: https://leetcode.com/problems/burst-balloons/discuss/76230/C%2B%2B-dp-detailed-explanation
    T:O(n^3)/S:O(n^2)
*/
class Solution {
public:
    int maxCoins(vector<int>& nums)
    {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for (int len=1; len<=n; ++len) {
            for (int l=1; l+len-1<=n; ++l) {
                int r=l+len-1;
                for (int k=l; k<=r; ++k) {
                    int coin=nums[k]*nums[l-1]*nums[r+1];
                    dp[l][r]=max(dp[l][r],coin + dp[l][k-1] + dp[k+1][r]);
                }
            }
        }
        return dp[1][n];
    }
};
