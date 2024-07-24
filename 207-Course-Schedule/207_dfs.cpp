class Solution {
 public:
  vector<int> status;
  vector<vector<int>> adj;
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    status.resize(numCourses, 0);
    adj.resize(numCourses);

    // initialzie graph
    for (auto pre : prerequisites) {
      adj[pre[1]].push_back(pre[0]);
    }

    for (int i = 0; i < numCourses; i++) {
      if (!dfs(i)) return false;
    }
    return true;
  }
  /*
      node    0   1   2
    status    2   2   2
   */
  bool dfs(int course) {
    if (status[course] == 2)  // visited
      return true;
    if (status[course] == 1)  // visiting
      return false;

    // not visited
    status[course] = 1;  // update status
    for (int next_course : adj[course]) {
      if (!dfs(next_course)) return false;
    }
    status[course] = 2;  // update status
    return true;
  }
};

/*
    three status:
        1. not visited
        2. visiting
        3. visited

    0 -> 1 -> 2
         ^____|

 */