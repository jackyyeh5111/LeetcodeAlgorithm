/***** Second Visit *****/
/*
    permutation:
    T:O(n!)/S:O(n!)
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums)
    {
        int n=nums.size();
        help(nums,0,n);
        return ans;
    }

    void help(vector<int>& nums, int idx, int n)
    {
        if (idx>=n) {ans.push_back(nums); return;}
        for (int i=idx; i<n; ++i) {
            swap(nums[i],nums[idx]);
            help(nums,idx+1,n);
            swap(nums[i],nums[idx]);
        }
    }
};

/***** First Visit *****/
class Solution {
public:
    // T:O(N!), S:O(N)
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums)
    {
        if (nums.size()==0) return vector<vector<int>>(1,vector<int>{});
        vector<int> perm=nums;
        permute(nums, 0, perm);
        return ans;
    }

    void permute(vector<int>& nums, int start, vector<int>& perm)
    {
        if (start==nums.size()-1){
            ans.push_back(perm);
            return;
        }
        for (int i=start; i<nums.size(); ++i) {
            swap(perm[start], perm[i]);
            permute(nums, start+1, perm);
            swap(perm[start], perm[i]);
        }
    }
};
