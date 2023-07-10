/*
    [1, 3], [6, 9]
    [2, 5]

    ==> [1, 5], [6, 9]
 */
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> ans;
    bool inserted = false;
    for (auto interval : intervals) {
      if (interval[1] < newInterval[0])
        ans.push_back(interval);
      else {
        if (!inserted) {
          ans.push_back(newInterval);
          inserted = true;
        }
        if (interval[0] > newInterval[1])
          ans.push_back(interval);
        else {
          ans.back()[0] = min(ans.back()[0], interval[0]);
          ans.back()[1] = max(ans.back()[1], interval[1]);
        }
      }
    }
    if (!inserted) ans.push_back(newInterval); // handle case: [1, 5], newInterval: [6, 9]

    return ans;
  }
};
