/*
    treat it as a graph problem
    apply BFS
    pruning continuous num to avoid TLE
	T:O(V+E)/S:O(V+E)
*/
class Solution {
public:
    int minJumps(vector<int>& arr)
    {
        int n=arr.size();
        vector<int> visited(n,0);
        unordered_map<int,vector<int>> m;
        for (int i=0; i<n; ++i) {
            if (m.count(arr[i])==0) m[arr[i]]=vector<int>{};
            m[arr[i]].push_back(i);
            int j=i;
            while(j<n-1&&arr[j+1]==arr[j]) j++;
            if (j!=i) m[arr[i]].push_back(j);
            i=j;
        }

        // bfs
        int step=0;
        queue<int> q;
        q.push(0); visited[0]=1;
        while (!q.empty()) {
            int k=q.size();
            for (int i=0; i<k; ++i) {
                int u=q.front(); q.pop();
                if (u==n-1) return step;
                for (int v:m[arr[u]]) {
                    if (u!=v&&!visited[v]) {visited[v]=1; q.push(v);}
                }
                if (u+1<n&&!visited[u+1]) {q.push(u+1); visited[u+1]=1;}
                if (u-1>=0&&!visited[u-1]) {q.push(u-1); visited[u-1]=1;}
            }
            step+=1;
        }
        return -1;
    }
};
