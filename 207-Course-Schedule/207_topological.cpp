class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> in_degree(numCourses, 0);  // <course, count>
    vector<vector<int>> next_courses(numCourses);

    // initialize
    for (auto pre : prerequisites) {
      in_degree[pre[0]]++;
      next_courses[pre[1]].push_back(pre[0]);
    }

    queue<int> que;
    for (int i = 0; i < numCourses; i++) {
      if (in_degree[i] == 0) que.push(i);
    }

    // topological sort
    int count = 0;
    while (!que.empty()) {
      int course = que.front();
      que.pop();
      count++;

      // remove course node
      for (int next_course : next_courses[course]) {
        in_degree[next_course]--;
        if (in_degree[next_course] == 0) que.push(next_course);
      }
    }
    return count == numCourses;
  }
};

/*
    clarification:

    structure:
        1. in_degree<int, int> // <course, count>
        2. next_course<int, vector<int>>

    0 -> 1 -> 2
         ^
         3
 */