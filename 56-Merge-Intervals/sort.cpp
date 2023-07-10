class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      auto comp = [](const vector<int> &in1, const vector<int> &in2) {
        return in1[0] < in2[0];
      };

      sort(intervals.begin(), intervals.end(), comp);

      vector<vector<int>> ans;
      for (auto interval : intervals) {
        if (ans.size() == 0 || ans.back()[1] < interval[0])
          ans.push_back(interval);
        else {
          ans.back()[1] = max(ans.back()[1], interval[1]);
        }
      }
      return ans;
    }
};