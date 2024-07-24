class Solution {
 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    if (n != edges.size() + 1) return false;

    unordered_map<int, vector<int>> dict;
    for (auto edge : edges) {
      dict[edge[0]].push_back(edge[1]);
      dict[edge[1]].push_back(edge[0]);
    }

    // bfs
    queue<int> que;
    que.push(0);
    vector<bool> visited(n, false);
    while (!que.empty()) {
      int node = que.front();
      que.pop();
      visited[node] = true;
      for (int next_node : dict[node]) {
        if (!visited[next_node]) que.push(next_node);
      }
    }
    for (bool is_visit : visited)
      if (!is_visit) return false;
    return true;
  }
};

/*
   dict = {
       0: [1, 2, 3]
       1: [0, 4]
       2: [0]
       3: [0]
       4: [1]
   }

    1. check # of edges == # of nodes - 1
    2. Make sure # of connected components == 1 (bfs)
    3. Check if every node is visited.


   queue: [1,2,3]
   visited: []
 */