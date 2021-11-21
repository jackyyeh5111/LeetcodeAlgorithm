class Solution {
public:
    int countArrangement(int n)
    {
        vector<bool> visited(n,0);
        int ans=0;
        help(visited,0,n,ans);
        return ans;
    }

    void help(vector<bool> &visited, int idx, int n, int &ans)
    {
        if (idx==n) {
            ans++;
            return;
        }

        for (int i=1; i<=n; ++i) {
            if ((i%(idx+1)==0||(idx+1)%i==0)&&!visited[i-1]) {
                visited[i-1]=true;
                help(visited,idx+1,n,ans);
                visited[i-1]=false;
            }
        }

    }
};
