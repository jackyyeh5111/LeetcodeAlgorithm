/*
    How to find the children value of current node in terms of array?
    i-th node's child -> 2*i+1, 2*i+2 (0-based)
	[WE DONT NEED THIS]
    -----
    bottom-up
    process values in the increasing number, as a dp question.
    For example, if i=a*b -> dp[i]=dp[a]*dp[b]*2 if a!=b
    dp[i] denotes the number of binary trees we can make with root node's value i.

    [2,4,5,20]
    4,2,2 20,4,5 20,5,4

    init value is 1 as it is the tree with exactly one node which is itself.
    T:O(n^2+nlogn)/S:O(n)

    Notice: overflow and mod
*/
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr)
    {
        sort(arr.begin(),arr.end());
        unordered_map<int,long> dp;
        int ans=0,mod=1e9+7;
        for (int num:arr) {
            if (dp.count(num)!=0) continue;
            dp[num]=1;
            for (auto pair:dp) {
                if (num%pair.first==0&&dp.count(num/pair.first)!=0)
                    dp[num]=(dp[num])%mod+(pair.second*dp[num/pair.first])%mod;
            }
            ans=ans%mod+dp[num]%mod;
        }
        return ans%mod;
    }
};
