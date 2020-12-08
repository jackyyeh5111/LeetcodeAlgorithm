/***** Third Visit *****/
/*
    1 2 3 4 5 6 7 8 9 , k=3, n=9
    T:O(9!)/S:O(C^9_k)
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> comb;
        help(1,k,n,comb,ans);
        return ans;
    }

    void help(int cur, int k, int n, vector<int> &comb, vector<vector<int>> &ans)
    {
        if (k==0&&n==0) {ans.push_back(comb); return;}
        else if (k<=0||n<=0) return;
        for (int i=cur; i<10; ++i) {
            comb.push_back(i);
            help(i+1,k-1,n-i,comb,ans);
            comb.pop_back();
        }
    }
};

/***** Second Visit *****/
/*
    find all combinations sum to n with exactly k nums.
    T:O(C^9_k)/S:O(k)
    space complexity in worst case would be  the depth of recursive.

    Since we employed recursion in the backtracking, we would need some
    additional space for the function call stack, which could pile up to KK
    consecutive invocations, i.e. \mathcal{O}(K)O(K)
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> comb;
        help(1,k,n,comb);
        return ans;
    }

    void help(int i, int k, int target, vector<int> &comb)
    {
        if (i==10||0==k) return;
        help(i+1,k,target,comb);
        target-=i;
        comb.push_back(i);
        if (target==0&&1==k) ans.push_back(comb);
        if (target>=i+1) help(i+1,k-1,target,comb);
        comb.pop_back();
    }
};

/***** First Visit *****/
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
