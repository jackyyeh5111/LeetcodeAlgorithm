/*
    Use a hash table with key: first element; value: index of pieces
    T:O(n)/S:O(n)

    ## Q: What if duplicate nums in arr or pieces?
    Here I just write down my thought for this follow up questioin. If there's any wrong concept please let me know. Feel free to have discussion.
    1. I think we can still utilize a hashmap with key: first element, value: vector of index w.r.t. pieces. Then do backtracking on arr and pieces. T:O(2^n)
    2. DP solution? Say dp[i][j] denotes arr[0~i] matches pieces[0~j] concatenations or not.
        transition: dp[i][j]|=dp[i-pieces[j].length()][j-1]&&arr[i-pieces[j].length() ~ i] == pieces[j]
    	T:O(mn*k), k denotes max length of piece.
    	S:O(mn)
    	Improvement: KMP
    	1. vector comparison (be like string comparison with KMP) table: T:O(mn)
    	2. Adopt DP ALG above. T:O(mn)
    	T:O(mn)/S:O(mn)
*/
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces)
    {
        unordered_map<int,int> m;
        for (int i=0; i<pieces.size(); ++i)
            m[pieces[i][0]]=i;
        int n=arr.size(), i=0;
        while (i<n) {
            if (m.count(arr[i])==0) return false;
            int j=m[arr[i]];
            for (auto num:pieces[j]) {
                if (num!=arr[i]||i>=n) return false;
                else i++;
            }
        }
        return true;
    }
};
