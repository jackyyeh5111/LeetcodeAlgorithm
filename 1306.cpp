/*
    Further reduce SC from T:O(n) to T:O(1).
    Same DFS thought, but no need to conduct a graph for traversal. The original arr could achieve it. Use sign bit to check if visited.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (start<0||start>=(int)arr.size()||arr[start]<0) return false;
        else if (arr[start]==0) return true;
        else {
            arr[start]*=-1;
            return canReach(arr,start+arr[start])||canReach(arr,start-arr[start]);
        }
    }
};

/*
    [4,2,3,0,3,1,2], start = 5
    Data Structure: Graph
    Traverse: DFS
    T:O(V+E)/S:O(V+E)
    -----
    constraints:
    1 <= arr.length <= 5 * 10^4
    0 <= arr[i] < arr.length
    0 <= start < arr.length
*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start)
    {
        int n=arr.size();
        vector<vector<int>> graph(n,vector<int>{});
        vector<bool> visited(n,0);
        for (int i=0; i<n; ++i) {
            if (i+arr[i]<n) graph[i].push_back(i+arr[i]);
            if (i-arr[i]>=0) graph[i].push_back(i-arr[i]);
        }

        return dfs(arr,graph,visited,start);
    }

    bool dfs(vector<int>& arr, vector<vector<int>> &graph, vector<bool> &visited, int u)
    {
        if (visited[u]) return false;
        visited[u]=true;
        bool found=arr[u]==0;
        for (int v:graph[u]) {
            found|=dfs(arr,graph,visited,v);
        }
        return found;
    }
};
