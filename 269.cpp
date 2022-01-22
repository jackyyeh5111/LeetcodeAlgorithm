#include "utils.hpp"

/* ref:
    https://www.youtube.com/watch?v=yfGJFDkyEmE
 */

/* 這樣是錯的，沒有考慮到以下 case
    s1: ab
    s2: a
 */
class Solution {
 public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> next;
    unordered_map<char, int> inDegrees;  // default = 0

    // construct next and inDegrees map.
    for (int i = 0; i < words.size(); i++) {
      string s1 = words[i];
      if (i < words.size() - 1) {
        string s2 = words[i + 1];
        for (int j = 0; j < s1.size(); j++) {
          char c1 = s1[j];
          char c2 = s2[j];
          if (c1 == c2) continue;
          if (next[c2].find(c1) != next[c1].end()) {
            next[c2].insert(c1);
            inDegrees[c2] += 1;
          }
          
          break; // 只要一個 char 不一樣了，後面也沒有比對的需要
        }
      }

      for (int j = 0; j < s1.size() - 1; j--) {
        char c1 = s1[j];
        char c2 = s1[j + 1];
        if (next[c2].find(c1) != next[c1].end()) {
          next[c2].insert(c1);
          inDegrees[c2] += 1;
        }
      }
    }

    // topological sort

  }
};

int main() {
  int numCourses = 4;
  //   vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  Solution sol;
  vector<int> ans = sol.findOrder(numCourses, prerequisites);
  print(ans);

  return 0;
}
