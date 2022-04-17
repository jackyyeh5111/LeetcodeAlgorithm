#include "utils.hpp"

/* Approach 1: DFS
可以轉化為找環的問題

(7, 3)
(7, 8)
(8, 7)

1->2->3->4
      ^
5->6->7->8
      ^__|
*/

class Solution2 {
 public:
  unordered_map<int, vector<int>> premap;
  vector<int> visit;
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    visit.resize(numCourses);
    for (auto pre : prerequisites) {
      premap[pre[0]].push_back(pre[1]);
    }

    for (int i = 0; i < numCourses; i++) {
      if (!dfs(i)) return false;
    }

    return true;
  }

  bool dfs(int label) {
    // 可以把判斷移動到前面，更淺顯易懂
    if (visit[label] == 1) return false;
    if (visit[label] == 2) return true;

    visit[label] = 1;
    for (int next_label : premap[label]) {
      if (!dfs(next_label)) return false;
    }

    visit[label] = 2;

    return true;
  }
};

/*
    calculate in degrees
    0: not visited
    1: visited in last traversal
    2: visited in current traversal

  1->2->3->4
        ^
        |
  5->6->7->8
        ^ _|
*/
class Solution {
 public:
  unordered_map<int, vector<int>> premap;
  vector<int> visit;
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    visit.resize(numCourses);
    for (auto pre : prerequisites) {
      premap[pre[0]].push_back(pre[1]);
    }

    for (int i = 0; i < numCourses; i++) {
      if (!dfs(i)) return false;
    }

    return true;
  }

  bool dfs(int label) {
    visit[label] = 1;
    for (int next_label : premap[label]) {
      if (visit[next_label] == 1) return false;
      if (visit[next_label] == 2) continue;
      if (!dfs(next_label)) return false;
    }

    visit[label] = 2;

    return true;
  }
};