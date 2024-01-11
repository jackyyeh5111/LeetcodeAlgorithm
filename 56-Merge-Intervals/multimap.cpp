/* 
    Great! Finally get the sense when to use multimap

    Note that it encounters error if using std::map.
    Because map does not allow duplicate key.

        Map Fail case:
        [[2,3],[2,2],[3,4]]
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      multimap<int, int> dict;
      for (const auto interval : intervals)
        dict.insert({interval[0], interval[1]});
      
      // merge
      auto it = dict.begin();
      vector<vector<int>> ans{{it->first, it->second}};
      
      for (auto it = next(dict.begin()); it != dict.end(); it++) {
        if (ans.back()[1] >= it->first)
          ans.back()[1] = max(ans.back()[1], it->second);
        else
          ans.push_back({it->first, it->second});
      }
      return ans;
    }
};

/* 

    ___ 
      ___
        ___
              ___
 
    ______
      ___
 */

