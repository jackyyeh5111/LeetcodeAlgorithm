class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<pair<int, int>> diffs;
       for (auto interval : intervals) {
         diffs.push_back({interval[0], 1});
         diffs.push_back({interval[1], -1});
       }

       auto comp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
          if (p1.first == p2.first)
            return p1.second > p2.second; // +1 first, -1 followed.
          return p1.first < p2.first;
       };

      sort(diffs.begin(), diffs.end(), comp);

      vector<vector<int>> ans;
      int num = 0;
      vector<int> interval{-1, -1};
      for (auto diff : diffs) {
        num += diff.second;
        if (num == 1 && diff.second == 1)
          interval[0] = diff.first;
        if (num == 0 && diff.second == -1) {
          interval[1] = diff.first;
          ans.push_back(interval);
        }
      }

      return ans;
    }
};

/* 
         _____
        +1
    _____
   +1   -1    
  

 */


