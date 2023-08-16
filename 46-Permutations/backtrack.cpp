class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> used;
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(nums, ans, used, cur);
        return ans;
    }
    void backtrack(const vector<int>& nums, vector<vector<int>>& ans,  unordered_set<int> &used, vector<int> &cur) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for (int num : nums) {
            if (used.count(num))
                continue;
            used.insert(num);
            cur.push_back(num);
            backtrack(nums, ans, used, cur);
            cur.pop_back();
            used.erase(num);
        }
    }
};
