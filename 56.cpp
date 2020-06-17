class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // brute force O(n^2)
        // sorting then greedy
        // T:O(nlogn)+O(n)
        if (intervals.size()==0) return vector<vector<int>>{};
        sort(intervals.begin(), intervals.end(), [](auto& a, auto&b){
            return a[0]<b[0];
        });
        vector<vector<int>> ans{intervals[0]};
        for (int i=1; i<intervals.size(); ++i) {
            if (intervals[i][0]<=ans[ans.size()-1][1])
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};
