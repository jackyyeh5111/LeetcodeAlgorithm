/***** First Visit *****/
/*
    For minimum spanning tree, there's only one longest path.
    Find the mid node of longest path.
    -----
    A tree is an undirected graph that each vertice has exactly one path to the other vertice, which is so-called spanning tree.
    We can start from any leaf node with DFS/BFS traversal to find the distance to each other node and max depth n (start from 0).
    n is even: n/2, n/2+1
    n is odd: n/2
    T:O(V^2)/S:O(n) due to path handling
    -----
    topologic sort that sequential delete nondes with in-degree 1
    T:O(v+e)/S:O(v+e)
    -----
    Start from any node and run dfs, which calculate distances for all other
    nodes from this node as well as create parent for each node.

    Now, we need to start our dfs all over again from this node  When we run
    our dfs second time, we again find the farthest node.

    关于无向图求最长路径的方法，任选一个节点Q，dfs到终点W停止，则W为Q为起点的最长路径，必为图
    最长路径的一个端点，再以此端点dfs找到另一个端点
    proof: https://leetcode.com/problems/minimum-height-trees/discuss/200941/topic

    2 step proof:

    proof that the longest path start from an arbitrary vertex must intersect
    with the diameter of graph. -> contradiction
        Q -> q is the longest path from Q.
        A - B is the longest path in the graph.
        If no intersection, there must exist k such that conmunicates Q-q, A-B
        which k is one of node in path AB, i.e. Ak+kB=AB, and k is NOT on the path of Q-q, k is the connected point in Qq, i.e. qz+zQ=qQ
        -> There must exist one path max(Ak,Bk)+kz+max(Qz,qz) < qz+zQ
        -> Qz > max(Ak,Bk)+kz > max(Ak,Bk)
        -> Qz+zk+max(Ak,Bk)>max(Ak,Bk)+zk+max(Ak,Bk)>AB
         [contradiction]!

    proof that this intersection node must be an endian of diameter. ->.
    contradiction.
        Say intersection node is k and suppose k is not one of A and B.
        Qk+kq > Qk+max(kA,kB)
        -> kq > max(kA,kB)
        -> max(Ak,Bk)+kq > AB [contractiction]!
    T:O(V+E)/S:O(V+E)
*/

// 2 dfs can help us find the longest path in undirected asyclic graph.
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    	if(n == 1) return {0};
    	vector<vector<int>> adj(n);
    	for(const auto& e: edges){
    		adj[e[0]].push_back(e[1]);
    		adj[e[1]].push_back(e[0]);
    	}
    	vector<int> path, maxpath;
    	vector<bool> visited(n);
    	dfs(adj, visited, maxpath, path, 0);
    	int lastnode = maxpath.back();
    	maxpath.clear();
    	dfs(adj, visited, maxpath, path, lastnode);
    	int mpsize = maxpath.size();
    	if(mpsize%2)
    		return {maxpath[mpsize/2]};
    	return {maxpath[mpsize/2-1], maxpath[mpsize/2]};
    }

    void dfs(const vector<vector<int>>& adj, vector<bool>& visited,
    	   vector<int>& maxpath, vector<int>& path, int node){
    	path.push_back(node);
    	visited[node] = true;
    	bool none_visited = true;
    	for(auto a: adj[node]){
    		if(!visited[a]){
    			none_visited = false;
    			longuest_path_dfs(adj, visited, maxpath, path, a);
    		}
    	}
    	if(none_visited && path.size() > maxpath.size())
    		maxpath = path;
    	path.pop_back();
    	visited[node] = false;
    }
};

// iteratively trim tree.
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(n,vector<int>{});
        vector<int> degree(n,0);
        for (auto edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for (int i=0; i<n; ++i) degree[i]=graph[i].size();
        for (int i=0,remain=n; i<n&&remain>2; ++i) {
            vector<int> del;
            for (int j=0; j<n; ++j) {
                if (degree[j]==1) {
                    remain--;
                    del.push_back(j);
                    degree[j]=-1;
                }
            }
            for (int d:del) {
                for (int neighbor:graph[d])
                    degree[neighbor]--;
            }
        }
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            if (degree[i]>=0)  ans.push_back(i);
        }
        return ans;
    }
};

// [TLE] use postDFS to find longest path across the graph.
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if (n==1) return {0};
        vector<vector<int>> graph(n,vector<int>{});
        vector<int> visited(n,0);
        for (auto edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> max_path;
        postDFS(graph,visited,0,max_path);
        vector<int> ans;
        if (max_path.size()%2==0)
            ans=vector<int>{max_path[max_path.size()/2],max_path[max_path.size()/2-1]};
        else
            ans=vector<int>{max_path[max_path.size()/2]};
        return ans;
    }

    vector<int> postDFS(vector<vector<int>> graph, vector<int> visited, int u, vector<int> &max_path)
    {
        if (visited[u]!=0) return {};
        visited[u]=1;
        vector<vector<int>> paths;
        for (int v:graph[u]) {
            paths.push_back(postDFS(graph,visited,v,max_path));
        }
        sort(paths.begin(),paths.end(),[](auto a, auto b){ return a.size()>=b.size(); });
        if (paths.size()>1&&paths[0].size()+paths[1].size()+1>max_path.size()) {
            max_path=paths[0];
            max_path.push_back(u);
            reverse(paths[1].begin(),paths[1].end());
            max_path.insert(max_path.end(),paths[1].begin(),paths[1].end());
        }
        else if (paths.size()==1&&paths[0].size()+1>max_path.size()){
            max_path=paths[0];
            max_path.push_back(u);
        }
        visited[u]=2;
        paths[0].push_back(u);
        return paths[0];
    }
};
