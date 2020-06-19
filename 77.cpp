/*
Copy constructor really take times!!
make tmp called by reference, time: 700ms->64ms
*/
class Solution {
public:

    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k)
    {
        /*
            we have vector with size n, find all k combinations
            which means C^n_k combinations.
            Use back tracking with params indice & k to permutate first k of n
        */
        vector<int> tmp;
        if(n<k||k==0) return vector<vector<int>>{};
        perm(n,tmp,0,k);
        return ans;
    }

    void perm(int n, vector<int> &tmp, int cur, int k)
    {
        if (tmp.size()==k) {ans.push_back(tmp); return;}
        for (int i=cur; i<n; ++i) {
            tmp.push_back(i+1); // 0-based indexinig
            perm(n,tmp,i+1,k);
            tmp.pop_back();
        }
    }

};
