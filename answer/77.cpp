/***** Fourth Visit *****/
/*
    C^n_k + C^n_k-1 = C^n+1_k
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> cur;
        help(n,k,0,cur,ans);
        return ans;
    }

    void help(int n, int k, int idx,
              vector<int> &cur, vector<vector<int>> &ans)
    {
        if (cur.size()==k) {
            ans.push_back(cur);
            return;
        }
        for (int i=idx; i<n; ++i) {
            cur.push_back(i+1);
            help(n,k,i+1,cur,ans);
            cur.pop_back();
        }
    }
};

/***** Third Visit *****/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        perm(n,k,1,comb,ans);
        return ans;
    }

    void perm(int n, int k, int idx, vector<int> &comb, vector<vector<int>> &ans)
    {
        if (comb.size()==k) {ans.push_back(comb); return;}
        for (int i=idx; i<=n; ++i) {
            comb.push_back(i);
            perm(n,k,i+1,comb,ans);
            comb.pop_back();
        }
    }
};

/***** Second Visit *****/
/*
    C^n_k
    permutation on those index larger than previous.
    T:O(n!)/S:O(C^n_k)
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> comb;
        help(n,k,comb,0);
        return ans;
    }

    void help(int n, int k, vector<int> &comb, int idx)
    {
        if (comb.size()==k) {ans.push_back(comb); return;}
        for (int i=idx; i<n; ++i) {
            comb.push_back(i+1);
            help(n,k,comb,i+1);
            comb.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> nums;
        for (int i=1; i<=n; ++i) nums.push_back(i);
        help(nums,k,0);
        return ans;
    }

    void help(vector<int> &nums, int k, int idx)
    {
        if (idx==k) {
            vector<int> tmp(nums.begin(),nums.begin()+idx);
            ans.push_back(tmp);
            return;
        }
        for (int i=idx; i<nums.size(); ++i) {
            if(idx>0&&nums[idx-1]>nums[i]) continue;
            swap(nums[i],nums[idx]);
            help(nums,k,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
};

/***** First Visit *****/
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
