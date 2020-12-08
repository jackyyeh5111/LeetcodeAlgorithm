/*
    find largest conected component in undirected graph.
    DFS
    edge: if A[i],A[j] share same common factor
    how to check common factor exists or not?
    check:
        Due to gcd calc, we need to take care if num is 0.
        null input ?
        duplicate num ?
    T:O(n^2)/S:O(n^2)

    1 <= A.length <= 20000
    1 <= A[i] <= 100000
    If we have worst case with 20000 nums in A, we have a HUGE graph with size 20000*20000, which will lead to TLE!!
    --------------
    Apply union. for each num, check its factor from 2 - sqrt(k), worst case would be only 20000 * sqrt(100000), far smaller than graph approach.
    for union/find op, it takes O(1) in amortize.
    T:O(n*sqrt(k)) / S:O(n)
*/

/***** Union *****/
class UnionFindSet {
public:
    vector<int> parents;
    UnionFindSet(int n)
    {
        parents=vector<int>(n+1);
        for (int i=1; i<=n; ++i)
            parents[i]=i;
    }

    void Union(int x, int y)
    {
        parents[Find(x)]=Find(y);
    }

    int Find(int x)
    {
        int tmp=x;
        while (parents[x]!=x) x=parents[x];
        parents[tmp]=x;
        return x;
    }

};

/***** Graph *****/
class Solution {
public:
    int largestComponentSize(vector<int>& A)
    {
        int n=*max_element(A.begin(),A.end());
        UnionFindSet ufs(n);
        for (int a:A) {
            int target = sqrt(a);
            for (int i=2; i<=target; ++i) {
                if (a%i) continue;
                ufs.Union(a,i);
                ufs.Union(a,a/i);
            }
        }
        unordered_map<int,int> m;
        int ans=1;
        for (int a:A) {
            int parent=ufs.Find(a);
            m[parent]++;
            ans=max(ans,m[parent]);
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    int largestComponentSize(vector<int>& A)
    {
        int n=A.size();
        graph = vector<vector<int>>(n,vector<int>{});
        visited = vector<bool>(n,0);
        for (int i=0; i<n-1; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (isCF(A[i],A[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int ans=0;
        for (int i=0; i<n; ++i) {
            int size=0;
            dfs(i,size);
            ans=max(ans,size);
        }
        return ans;
    }

    void dfs(int u, int &size)
    {
        if (visited[u]) return;
        visited[u]=true;
        size++;
        for (int v:graph[u]) dfs(v,size);
    }

    bool isCF(int a, int b)
    {
        if (a<b) swap(a,b);
        while(b) {
            a%=b;
            swap(a,b);
        }
        return a!=1;
    }
};
/*
6 4
4
2
  4
  0
*/
