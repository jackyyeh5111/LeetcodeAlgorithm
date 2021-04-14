/* The knows API is defined for you.
      bool knows(int a, int b); */
/*
    list all n's in-degree/out-degree
    T:O(n^2)/S:O(n)
    -----
    dfs from arbitary node, terminate while meet the end point.
    Then check the end node of the path.
    T:O(3*T(know))/S:O(n)
*/

class Solution {
public:
    int findCelebrity(int n) {
        int cand=0;
        for (int i=1; i<n; ++i) {
            if (knows(cand,i)) cand=i;
        }
        int in=0,out=0;
        for (int i=0; i<n; ++i) {
            if (i==cand) continue;
            if (knows(i,cand)) in++;
            if (knows(cand,i)) out++;
        }
        return in==n-1&&out==0?cand:-1;
    }
};

class Solution {
public:
    int findCelebrity(int n)
    {
        vector<bool> visited(n,0);
        int end=0,in=0,out=0;
        end=dfs(visited,0);
        for (int i=0; i<n; ++i) {
            if (i==end) continue;
            if (knows(i,end)) in++;
            if (knows(end,i)) out++;
        }
        return in==n-1&&out==0?end:-1;
    }

    // return end node
    int dfs(vector<bool> &visited, int u)
    {
        if (visited[u]) return -1;
        visited[u]=true;
        for (int i=0; i<visited.size(); ++i) {
            if (i!=u&&knows(u,i)) {
                int k=dfs(visited,i);
                if(k!=-1) return k;
            }
        }
        return u;
    }
};
