class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*
        sort O(nlogn)
        use a set, k: string O(2^n)
        T:O(2^n), S:O(2^n) in worst
        ------------------
        calc histogram
        for distinct value:
          for entry in ans:
            for duplicate #:
                ans.push_back(entry+ # of duplicate)
        T: O(2^n), faster than method 1 due to theoritical lower bound.
        S: O(2^n+n)
        */
        // second approach
        vector<vector<int>> ans(1,vector<int>{});
        unordered_map<int,int> hist;
        for (int num:nums) hist[num]++;
        for (auto it=hist.begin(); it!=hist.end(); ++it) {
            int cur_size = ans.size();
            for (int i=0; i<cur_size; ++i) {
                for (int j=1; j<=it->second; ++j) {
                    vector<int> tmp=ans[i];
                    vector<int> add=vector<int>(j, it->first);
                    tmp.insert(tmp.end(),add.begin(),add.end());
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};
