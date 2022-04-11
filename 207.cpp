#include "utils.hpp"

/* ref:
    https://github.com/wisdompeak/LeetCode/blob/master/BFS/207.Course-Schedule/Readme.md
 */

/* Approach 2: (improved): BFS
  不用 count, 可以在最後時確認所有 in_degree 是否均為 0 比較直觀
*/
class Solution3 {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    in_degree.resize(numCourses, 0);
    next.resize(numCourses);

    for (vector<int> p : prerequisites) {
      next[p[0]].push_back(p[1]);
      in_degree[p[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (in_degree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
      int idx = q.front();
      q.pop();
      for (int next_idx : next[idx]) {
        in_degree[next_idx]--;
        if (in_degree[next_idx] == 0) q.push(next_idx);
      }
    }

    for (int num : in_degree)
      if (num) return false;
    return true;
  }

 private:
  vector<int> in_degree;
  vector<vector<int>> next;
};

/* Approach 2: BFS
    BFS的算法思想是拓扑排序：从外围往核心进发。我们每次在图中找入度为0的点，然后移除。
    如果最后没有入度为0的点，但是图中仍有点存在，那么这些剩下来的点一定是交错成环的。
 */
class Solution2 {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    in_degree.resize(numCourses, 0);
    next.resize(numCourses);

    for (vector<int> p : prerequisites) {
      next[p[0]].push_back(p[1]);
      in_degree[p[1]]++;
    }

    int count = 0;
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (in_degree[i] == 0) {
        q.push(i);
        count++;
      }
    }

    while (!q.empty()) {
      int idx = q.front();
      q.pop();
      for (int next_idx : next[idx]) {
        in_degree[next_idx]--;
        if (in_degree[next_idx] == 0) {
          q.push(next_idx);
          count++;
        }
      }
    }

    return count == numCourses;
  }

 private:
  vector<int> in_degree;
  vector<vector<int>> next;
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
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    visited.resize(numCourses, 0);
    next.resize(numCourses);
    for (auto prerequisite : prerequisites) {
      next[prerequisite[0]].push_back(prerequisite[1]);
    }

    for (int i = 0; i < numCourses; i++) {
      if (!dfs(i)) return false;
    }

    return true;
  }

  bool dfs(int cur) {
    if (visited[cur] == 1) return true;
    if (visited[cur] == 2) return false;

    visited[cur] = 2;
    for (int next_idx : next[cur]) {
      if (!dfs(next_idx)) return false;
    }

    visited[cur] = 1;

    return true;
  }

 private:
  vector<int> visited;
  vector<vector<int>> next;
};

int main() {
  int numCourses = 2;
  vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
  // vector<vector<int>> prerequisites = {{1, 0}};
  SolutionTemp sol;
  bool ans = sol.canFinish(numCourses, prerequisites);
  std::cout << "ans: " << ans << '\n';

  return 0;
}
