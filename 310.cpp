#include "utils.hpp"

/*
    ref:
    https://github.com/wisdompeak/LeetCode/tree/master/Tree/310.Minimum-Height-Trees

    剝洋蔥，要找個離各點都平均近的節點當成 tree root
 */

class Solution2 {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};
    unordered_map<int, vector<int>> map;
    vector<int> in_degrees(n, 0);
    for (const auto edge : edges) {
      in_degrees[edge[0]]++;
      in_degrees[edge[1]]++;
      map[edge[0]].push_back(edge[1]);
      map[edge[1]].push_back(edge[0]);
    }

    int count = 0;
    queue<int> que;
    for (int i = 0; i < n; i++) {
      if (in_degrees[i] == 1) {
        que.push(i);
        count++;
      }
    }

    while (!que.empty() && count < n) {
      int size = que.size();
      for (int i = 0; i < size; i++) {
        int label = que.front();
        que.pop();
        for (int next_label : map[label]) {
          in_degrees[next_label]--;
          if (in_degrees[next_label] == 1) {
            que.push(next_label);
            count++;
          }
        }
      }
    }

    vector<int> ans;
    while (!que.empty()) {
      ans.push_back(que.front());
      que.pop();
    }

    return ans;
  }
};

/* Approach 1: Topological sort
    不要從中心往外走，反過來從外走向裡面，就是 Topological sort了！
    這是錯的！

    error case:
        input: 2, [[0,1]]
        Output: []
        Expected: [0,1]
 */
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {};
    vector<int> degrees(n, 0);
    unordered_map<int, set<int>> map;
    for (const vector<int>& edge : edges) {
      map[edge[0]].insert(edge[1]);
      map[edge[1]].insert(edge[0]);
      degrees[edge[0]]++;
      degrees[edge[1]]++;
    }

    int count = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (degrees[i] == 1) {
        q.push(i);
        count++;
      }
    }

    while (!q.empty()) {
      int num_level = q.size();
      for (int i = 0; i < num_level; i++) {
        int num = q.front();
        q.pop();
        for (auto it = map[num].begin(); it != map[num].end(); it++) {
          int val = *it;
          degrees[val]--;
          if (degrees[val] == 1) {
            q.push(val);
            count++;
          }
        }
      }

      if (count == n) break;  // error 位置要往前擺動
    }

    std::vector<int> ans;
    while (!q.empty()) {
      ans.push_back(q.front());
      q.pop();
    }

    return ans;
  }
};

int main() {
  int numCourses = 6;
  vector<vector<int>> prerequisites{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
  //   vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
  // vector<vector<int>> prerequisites = {{1, 0}, {1, 2}, {1, 3}};
  Solution2 sol;
  vector<int> ans = sol.findMinHeightTrees(numCourses, prerequisites);
  print(ans);

  return 0;
}
