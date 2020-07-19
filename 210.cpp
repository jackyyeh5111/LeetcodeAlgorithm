/******************** detect cyclic + reverse postDFS ********************/
// T:O(V+E), S:O(V+E)
class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visited;
    bool cyclic=false;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        visited=vector<int>(numCourses,0);
        graph=vector<vector<int>>(numCourses,vector<int>{});
        for (auto req : prerequisites) graph[req[1]].push_back(req[0]);

        vector<int> ans;
        for (int i=0; i<numCourses; ++i)
            dfs(i, ans);

        if (cyclic) return vector<int>{};
        else {
            reverse(ans.begin(), ans.end());
            return ans;
        }

    }

    void dfs(int node, vector<int> &ans)
    {
        if (visited[node]==2) return;
        else if (visited[node]==1) {
            cyclic=true;
            return;
        }
        visited[node]=1;
        for (int next:graph[node])
            dfs(next,ans);
        visited[node]=2;
        ans.push_back(node);
    }
};

/******************** indegrees counting ********************/
class Solution {
public:
    // T:O(V*(V+E)) V+E for traversing each 0 in-degree node, V for finding 0
    // in-degree node.
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int, unordered_set<int>> graph;
        for (int i=0; i<numCourses; ++i) graph[i]=unordered_set<int>{};
        for (auto req : prerequisites) graph[req[0]].insert(req[1]);

        vector<int> ans;
        while (graph.size() > 0) {
            bool valid=false;
            int node;
            for (auto it=graph.begin(); it!=graph.end(); ++it) {
                if (it->second.size()>0) continue;
                valid=true;
                ans.push_back(it->first);
                node=it->first;
                for (auto t=graph.begin(); t!=graph.end(); ++t ) {
                    t->second.erase(it->first);
                }
                break;
            }
            if (!valid) return vector<int>{}; // cyclic finding
            else graph.erase(node);
        }
        return ans;
    }
};

/******************** indegrees counting (neat) ********************/
// T:O(V+E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> graph(numCourses,vector<int>());

        for(auto pre:prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> que;
        for(int i=0;i<indegree.size();i++)
            if(indegree[i]==0)
                que.push(i);

        while(!que.empty()) {
            int u = que.front();que.pop();
            res.push_back(u);
            for(auto v:graph[u]) {
                indegree[v]--;
                if(indegree[v] == 0)
                    que.push(v);
            }
        }
        if(res.size()==numCourses)
            return res;
        else
            return vector<int>();
    }
};
