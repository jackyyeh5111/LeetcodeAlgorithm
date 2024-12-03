class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sweeping line
        vector<pair<int, int>> diffs;
        for (const auto& interval : intervals) {
            diffs.push_back({interval[0], 1});
            diffs.push_back({interval[1], -1});
        }

        // sort diffs
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first == p2.first)
                return p1.second > p2.second; // +1 comes before -1
            return p1.first < p2.first;
        };
        sort(diffs.begin(), diffs.end(), comp);

        // sweeping line
        vector<vector<int>> ans;
        int val = 0;
        for (const auto& diff : diffs) {
            val += diff.second;
            if (val == 1 && diff.second == 1)
                ans.push_back({diff.first, -1});
            if (val == 0 && diff.second == -1)
                ans.back()[1] = diff.first;
        }
        return ans;
    }
};
/* 
        _______
    ____
    +1  -1
        +1   -1
 */