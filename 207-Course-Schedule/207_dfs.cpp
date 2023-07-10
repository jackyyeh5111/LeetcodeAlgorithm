#include "utils.hpp"

/* 
  Wrong answer!

  Failed case:
    numCourses = 4
    prerequisites = [[2,0],[1,0],[3,1],[3,2],[1,3]]

       --->   2
    |         |
    0 -> 1 -> 3
        ^ __ | 

    Visit node while in_degrees <= 0. This leads to multiple visits to "note 2".

 */
class Solution3 {
public:
    vector<int> in_degrees;
    vector<vector<int>> next;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      in_degrees.resize(numCourses);
      next.resize(numCourses);
      for (auto pre : prerequisites) {
        ++in_degrees[pre[0]];
        next[pre[1]].push_back(pre[0]);
      }

      for (int i=0; i < numCourses; ++i) {
        if (in_degrees[i] == 0)
          dfs(i);
      }
      for (int in_degree : in_degrees) {
        if (in_degree > 0)
          return false;
      }
      return true;
    }
    void dfs(int course) {
      --in_degrees[course];
      if (in_degrees[course] > 0) // > 0: course conflict
        return;
      for (int next_course : next[course])
        dfs(next_course);
    }
};

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

