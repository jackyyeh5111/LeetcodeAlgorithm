/***** Second Visit *****/
/*
    dfs to find connected component
    T:O(V+E)/S:O(V+E)
    -----
    union find
    T:O(V+E)/S:O(V+E)
*/
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int *parents=new int[n];
        memset(parents,-1,n*4);
        for (auto edge:edges) {
            if (myunion(parents,edge[0],edge[1]))
                n--;
        }
        return n;
    }

    int find(int *parents, int x)
    {
        int root=x;
        while (parents[root]>=0)
            root=parents[root];
        while (x!=root) {
            int next=parents[x];
            parents[x]=root;
            x=next;
        }
        return root;
    }

    // true if unioned, false if in the same component.
    bool myunion(int *parents, int x, int y)
    {
        int rx=find(parents, x),ry=find(parents, y);
        if (rx==ry) return false;
        if (rx<ry) parents[ry]=rx;
        else parents[rx]=ry;
        return true;
    }
};

/***** First Visit *****/
/*
    Union/Find
    [1,2,2,4,4]
     2 2 2 4 4
    T:O(nlogn)
    -----
    DFS
    T:O(V+E)
*/
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        vector<int> parents(n,0);
        for (int i=0; i<n; ++i) parents[i]=i;
        for (auto edge:edges) {
            int px=find(parents,edge[0]), py=find(parents,edge[1]);
            Union(parents,px,py);
        }
        unordered_set<int> s;
        for (int i=0; i<n; ++i) {
            s.insert(find(parents,i));
        }
        return s.size();
    }

    // O(logn)
    int find(vector<int> &parents, int u)
    {
        int i=u;
        while (parents[i]!=i) {
            i=parents[i];
        }
        int j=u;
        while(parents[j]!=i) {
            int t=parents[j];
            parents[j]=i;
            j=parents[t]; //j=t
        }
        return i;
    }

    // O(1)
    void Union(vector<int> &parents, int x, int y)
    {
        if (parents[x]<=parents[y]) parents[x]=parents[y];
        else parents[y]=parents[x];
    }
};
