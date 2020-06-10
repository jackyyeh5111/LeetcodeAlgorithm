class Solution {
public:
    // T: DFS O(V+E), S:O(V+E)
    bool possibleBipartition(int N, vector<vector<int>>& dislikes)
    {
        vector<vector<int>> graph(N, vector<int>{});
        for (vector<int> dislike:dislikes) {
            graph[dislike[0]-1].push_back(dislike[1]-1);
            graph[dislike[1]-1].push_back(dislike[0]-1);
        }

        vector<int> record(N,0);
        for (int i=0; i<N; ++i) {
            if(record[i]!=0) continue;
            record[i] = 1;
            stack<int> s; // visit
            s.push(i);
            while (!s.empty()) {
                int node = s.top(); s.pop();
                // if not visit, then visit
                for (int x : graph[node]) {
                    if (record[x]==0) {
                        record[x]=record[node]==1 ? 2 : 1; // visit
                        s.push(x);
                    }
                    else if (record[x]==record[node]) return false;
                }
            }
        }
        return true;

    }
};
