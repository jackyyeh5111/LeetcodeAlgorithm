#include "utils.hpp"

/* Approach 1: BFS
    BFS的算法思想是拓扑排序：从外围往核心进发。我们每次在图中找入度为0的点，然后移除。
    如果最后没有入度为0的点，但是图中仍有点存在，那么这些剩下来的点一定是交错成环的。
 */
class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    in_degree.resize(numCourses, 0);
    next.resize(numCourses);

    for (vector<int> p : prerequisites) {
      next[p[1]].push_back(p[0]);
      in_degree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (in_degree[i] == 0) q.push(i);
    }

    vector<int> ans;
    while (!q.empty()) {
      int idx = q.front();
      q.pop();
      ans.push_back(idx);
      for (int next_idx : next[idx]) {
        in_degree[next_idx]--;
        if (in_degree[next_idx] == 0) q.push(next_idx);
      }
    }

    if (ans.size() == numCourses) return ans;
    return {};
  }

 private:
  vector<int> in_degree;
  vector<vector<int>> next;
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
