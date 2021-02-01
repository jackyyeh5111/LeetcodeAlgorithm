/*
    do backtracking
    T:O(n^4)/S:O(1)
    TLE
    -----

*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
    {
        unordered_map<int,int> ab;
        for (int a:A) {
            for (int b:B) {
                ab[a+b]++;
            }
        }
        int ans=0;
        for (int c:C) {
            for (int d:D) {
                if (ab.count(-1*(c+d)))
                    ans+=ab[-1*(c+d)];
            }
        }
        return ans;
    }
};
