class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n)
    {
        /*
            enumerate T(n)=n*(n-1)*(n-2)...=O(n^k)
            note that "each combination should be a unique set of numbers"
            worst case: 9!/k!
        */
        vector<int> comb;
        help(k,n,comb);
        return ans;
    }

    void help(int k, int n, vector<int> &comb)
    {
        if (k==0&&n==0) { ans.push_back(comb); return; }
        else if (k<=0||n<=0) return;
        int start=comb.size()==0?1:comb.back()+1;
        for (int i=start; i<=9; ++i) {
            comb.push_back(i);
            help(k-1,n-i,comb);
            comb.pop_back();
        }
    }
};
