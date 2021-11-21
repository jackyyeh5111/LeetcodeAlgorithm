/***** Second Visit *****/
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes)
    {
        N+=1;
        vector<vector<int>> graph(N,vector<int>{});
        vector<int> visited(N,0); //0, 1, 2
        for (auto edge:dislikes) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i=0; i<N; ++i) {
            if (visited[i]!=0) continue;
            queue<int> q;
            q.push(i);
            int label=1;
            while (!q.empty()) {
                int k=q.size();
                while (k--) {
                    int u=q.front(); q.pop();
                    visited[u]=label;
                    for (int &v:graph[u]) {
                        if (visited[v]==label) return false;
                        else if (visited[v]==0) q.push(v);
                    }
                }
                label=3-label;
            }
        }
        return true;
    }
};

/***** First Visit *****/
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
