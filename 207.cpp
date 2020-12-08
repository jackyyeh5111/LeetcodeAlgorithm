/***** Third Visit *****/
/*
    Topological order check on adjacent matrix.
    T:O(V^2)/S:O(V+E)
    -----
    DFS to detect acyclic on directed graph
    T:O(V+E)/S:O(V+E)
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> in_degree(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>{});
        for (auto req:prerequisites) {
            graph[req[1]].push_back(req[0]);
            in_degree[req[0]]++;
        }
        for (int i=0; i<numCourses; ++i) {
            bool found=false;
            for (int j=0; j<numCourses; ++j) {
                if (in_degree[j]!=0) continue;
                in_degree[j]=-1;
                for (int v:graph[j]) in_degree[v]--;
                found=true;
                break;
            }
            if (!found) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>{});
        for (auto req:prerequisites)
            graph[req[1]].push_back(req[0]);
        for (int i=0; i<numCourses; ++i) {
            if (!dfs(graph,visited,i)) return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int u)
    {
        if (visited[u]==2) return true;
        else if (visited[u]==1) return false;
        bool ret=true;
        for (int v:graph[u]) {
            visited[u]=1;
            ret&=dfs(graph, visited, v);
            visited[u]=2;
        }
        return ret;
    }
};

/***** Second Visit *****/
class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        graph = vector<vector<int>>(numCourses,vector<int>{});
        visited = vector<int>(numCourses, 0);
        for (auto req:prerequisites) {
            graph[req[1]].push_back(req[0]);
        }
        for (int i=0; i<numCourses; ++i) {
            if (visited[i]==0) {
                if (dfs(i)) return false; // cyclic
            }
        }
        return true; // acyclic
    }

    bool dfs(int u) {
        visited[u]=1;
        for (int v : graph[u]) {
            if (visited[v]==1) return true; // find cyclic
            if (visited[v]==2) continue; // already visited
            bool cyclic = dfs(v);
            if (cyclic) return cyclic;
        }
        visited[u]=2;
        return false;
    }
};

/***** First Visit *****/
class Solution {
public:
    // T:O(V+E), S:O(V+E)
    vector<vector<int>> graph;
    vector<bool> visit;
    vector<bool> predecessor;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        graph = vector<vector<int>>(numCourses,vector<int>{});
        visit = vector<bool>(numCourses, false);
        predecessor = vector<bool>(numCourses, false);
        for(vector<int> prerequisit : prerequisites) {
            graph[prerequisit[0]].push_back(prerequisit[1]);
        }
        for (int i=0; i<numCourses; ++i) {
            if (!visit[i]) {
                bool acyclic = dfs(i);
                if(!acyclic) return false;
            }
        }
        return true;
    }

    bool dfs(int node) // isAcyclic
    {
        visit[node] = true; predecessor[node] = true;
        for (int adj : graph[node]) {
            if (!visit[adj]) {
                if(!dfs(adj)) return false;
            }
            else if (predecessor[adj]) return false;
        }
        predecessor[node] = false;
        return true;
    }

};

/************************ BFS ************************/
/************** Intution: topological sort *********/
/*
BFS uses the indegrees of each node. We will first try to find a node with 0 indegree. If we fail to do so, there must be a cycle in the graph and we return false. Otherwise we set its indegree to be -1 to prevent from visiting it again and reduce the indegrees of its neighbors by 1. This process will be repeated for n (number of nodes) times.
*/
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
    graph g = buildGraph(numCourses, prerequisites);
    vector<int> degrees = computeIndegrees(g);
    for (int i = 0; i < numCourses; i++) {
        int j = 0;
        for (; j < numCourses; j++) {
            if (!degrees[j]) {
                break;
            }
        }
        if (j == numCourses) {
            return false;
        }
        degrees[j]--; // set indegree to -1
        for (int v : g[j]) {
            degrees[v]--;
        }
    }
    return true;
}
