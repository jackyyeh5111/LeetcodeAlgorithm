
/************************ DFS ************************/
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
