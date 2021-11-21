/*
    [[0,4],[1,3],[1,4],[2,4]]
    
    graph: Do dfs for connected component finding.
    0: 4
    1: 3 4
    2: 4
    3: 1
    4: 1, 2
    T:O(V+E)
    -----
    Another way to find connected component: UNION_FOLD
    table[i]>0: ith num is not a root.
    table[i]<0: ith num is a root with abs(table[i]) nums inside.
    Union: T:O(1) // the root num is the smallest one.
    Find: T:O(logn) // collapsing
    TC:O(nlogn) 
*/

// DFS 
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, 
                               vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        vector<vector<int>> graph(n,vector<int>{});
        vector<bool> visited(n,0);
        for (auto e:allowedSwaps) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int ans=n;
        for (int i=0; i<n; ++i) {
            
            vector<int> group;
            dfs(graph,visited,i,group);
            unordered_map<int,int> src_num;
            for (int idx:group) {
                src_num[source[idx]]++;
            }
            for (int idx:group) {
                if (src_num[target[idx]]>0) {
                    ans--; 
                    src_num[target[idx]]--;
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int u, 
             vector<int> &group)
    {
        if (visited[u]) return;
        visited[u]=true;
        group.push_back(u);
        for (int v:graph[u])
            dfs(graph,visited,v,group);
    }
};

// Union-Fold
class Solution {
public:
    // Recursive collapsing T:O(logn)
    int find(vector<int> &ds, int i)
    {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }

    int minimumHammingDistance(vector<int>& s, vector<int>& t, 
                               vector<vector<int>>& allowedSwaps) 
    {
        int sz = s.size(), res = 0;
        vector<int> ds(sz, -1);
        //Union T:O(1)
        for (auto &sw : allowedSwaps)
        {
            int i = find(ds, sw[0]), j = find(ds, sw[1]);
            if (i != j)
            {
                if (ds[i] > ds[j])
                    swap(i, j);
                ds[i] += ds[j];
                ds[j] = i;
            }
        }
        // find src nums in each group
        vector<unordered_multiset<int>> cycles(sz);
        for (auto i = 0; i < sz; ++i)
            if (s[i] != t[i])
                cycles[find(ds, i)].insert(s[i]);

        //compare to tgt nums 
        for (auto i = 0; i < sz; ++i)
        {
            if (s[i] != t[i])
            {
                auto &cycle = cycles[find(ds, i)];
                auto it = cycle.find(t[i]);
                if (it != end(cycle))
                {
                    cycle.erase(it);
                }
                else
                    ++res;
            }
        }
        return res;
    }
};