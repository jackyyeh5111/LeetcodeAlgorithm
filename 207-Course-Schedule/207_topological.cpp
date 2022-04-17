/* Approach 2: BFS
    BFS的算法思想是拓扑排序：从外围往核心进发。我们每次在图中找入度为0的点，然后移除。
    如果最后没有入度为0的点，但是图中仍有点存在，那么这些剩下来的点一定是交错成环的。

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
    vector<int> in_degrees(numCourses, 0);
    unordered_map<int, vector<int>> premap;
    for (auto pre : prerequisites) {
      premap[pre[0]].push_back(pre[1]);
      in_degrees[pre[1]]++;
    }

    queue<int> que;
    int num_visit = 0;
    for (int i = 0; i < numCourses; i++) {
      if (in_degrees[i] == 0) {
        que.push(i);
        num_visit++;
      }
    }

    /*
        1->2->3->4
              ^
        5->6->7->8
              ^__|
    */
    while (!que.empty()) {
      int label = que.front();
      for (int next_label : premap[label]) {
        in_degrees[next_label]--;
        if (in_degrees[next_label] == 0) {
          que.push(next_label);
          num_visit++;
        }
      }

      que.pop();
    }

    return num_visit == numCourses;
  }
};