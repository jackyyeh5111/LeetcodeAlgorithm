class Solution3 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      auto comp = [](const vector<int>& i1, const vector<int>& i2){
        return i1[0] < i2[0];
      };
      sort(intervals.begin(), intervals.end(), comp);

      vector<vector<int>> ans; 
      for (int i = 0; i < intervals.size(); i++) {
        if (i != 0 && intervals[i][0] <= ans.back()[1]) {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else
          ans.push_back(intervals[i]);
      }
      return ans;
    }
};


/* wrong solution 
  fail case:
    intervals: [[1,4],[2,3]]
       output: [[1, 3]]
*/
class Solution2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      auto comp = [](const vector<int>& i1, const vector<int>& i2){
        return i1[0] < i2[0];
      };
      sort(intervals.begin(), intervals.end(), comp);

      vector<vector<int>> ans; 
      for (int i = 0; i < intervals.size(); i++) { 
        if (i != 0 && intervals[i][0] <= intervals[i-1][1]) // wrong here
          ans.back()[1] = intervals[i][1]; // wrong here
        else
          ans.push_back(intervals[i]);
      }
      return ans;
    }
};


/* wrong solution 
  fail case:
    intervals: [[1,3],[2,6],[8,10],[15,18]]
       output: [[1,6],[8,18]]
*/
class Solution1 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      auto comp = [](const vector<int>& i1, const vector<int>& i2){
        return i1[0] < i2[0];
      };
      sort(intervals.begin(), intervals.end(), comp);

      vector<vector<int>> ans; // [[1, 6]]
      vector<int> new_interval{-1, -1}; // [8, -1]
      for (int i = 0; i < intervals.size() - 1; i++) { // i = 1
        if (new_interval[0] == -1)
          new_interval[0] = intervals[i][0]; 
        else {
          if (intervals[i][1] < intervals[i+1][0]) {
            new_interval[1] = intervals[i][1];
            ans.push_back(new_interval);
            new_interval = {-1, -1};
          }
        }
      }

      if (new_interval[0] == -1)
        new_interval[0] = intervals.back()[0];
      new_interval[1] = intervals.back()[1];
      
      ans.push_back(new_interval);
      return ans;
    }
};

/* 
    
 */