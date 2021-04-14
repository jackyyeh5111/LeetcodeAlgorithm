/***** Third Visit *****/

// combine ocean 1 and 2 into 1 dfs function
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        if (matrix.size()==0||matrix[0].size()==0) return ans;
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));


        for (int i=0; i<m; ++i) {
            dfs(dp,matrix,i,0,m,n,INT_MIN,1,ans);
            dfs(dp,matrix,i,n-1,m,n,INT_MIN,2,ans);
        }
        for (int j=0; j<n; ++j) {
            dfs(dp,matrix,0,j,m,n,INT_MIN,1,ans);
            dfs(dp,matrix,m-1,j,m,n,INT_MIN,2,ans);
        }

        return ans;
    }

    void dfs(vector<vector<int>> &dp, vector<vector<int>>& matrix,
                    int i, int j, int m, int n, int prev, int ocean, vector<vector<int>> &ans)
    {
        if (i<0||i>=m||j<0||j>=n) return;
        else if (matrix[i][j]<prev) return;
        else if (dp[i][j]==ocean||dp[i][j]==3) return;
        dp[i][j]=dp[i][j]|ocean;
        if (dp[i][j]==3) ans.push_back({i,j});
        dfs(dp,matrix,i+1,j,m,n,matrix[i][j],ocean,ans);
        dfs(dp,matrix,i-1,j,m,n,matrix[i][j],ocean,ans);
        dfs(dp,matrix,i,j+1,m,n,matrix[i][j],ocean,ans);
        dfs(dp,matrix,i,j-1,m,n,matrix[i][j],ocean,ans);
    }
};

// separate dfs function
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        if (matrix.size()==0||matrix[0].size()==0) return ans;
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));


        for (int i=0; i<m; ++i)
            dfsPacific(dp,matrix,i,0,m,n,INT_MIN);
        for (int j=0; j<n; ++j)
            dfsPacific(dp,matrix,0,j,m,n,INT_MIN);

        for (int i=0; i<m; ++i)
            dfsAtlantic(dp,matrix,i,n-1,m,n,INT_MIN, ans);
        for (int j=0; j<n; ++j)
            dfsAtlantic(dp,matrix,m-1,j,m,n,INT_MIN, ans);
        return ans;
    }

    void dfsPacific(vector<vector<int>> &dp, vector<vector<int>>& matrix,
                    int i, int j, int m, int n, int prev)
    {
        if (i<0||i>=m||j<0||j>=n) return;
        else if (dp[i][j]!=0) return;
        else if (matrix[i][j]<prev) return;
        dp[i][j]=dp[i][j]|1;
        dfsPacific(dp,matrix,i+1,j,m,n,matrix[i][j]);
        dfsPacific(dp,matrix,i-1,j,m,n,matrix[i][j]);
        dfsPacific(dp,matrix,i,j+1,m,n,matrix[i][j]);
        dfsPacific(dp,matrix,i,j-1,m,n,matrix[i][j]);
    }

    void dfsAtlantic(vector<vector<int>> &dp, vector<vector<int>>& matrix,
                    int i, int j, int m, int n, int prev, vector<vector<int>> &ans)
    {
        if (i<0||i>=m||j<0||j>=n) return;
        else if (dp[i][j]==3||dp[i][j]==2) return;
        else if (matrix[i][j]<prev) return;
        if (dp[i][j]==1) ans.push_back({i,j});
        dp[i][j]=dp[i][j]|2;
        dfsAtlantic(dp,matrix,i+1,j,m,n,matrix[i][j],ans);
        dfsAtlantic(dp,matrix,i-1,j,m,n,matrix[i][j],ans);
        dfsAtlantic(dp,matrix,i,j+1,m,n,matrix[i][j],ans);
        dfsAtlantic(dp,matrix,i,j-1,m,n,matrix[i][j],ans);
    }
};

/***** Second Visit *****/
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
    {
        if (matrix.size()==0||matrix[0].size()==0) return {};
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> ans;
        for (int i=0; i<m; ++i) {
            dfs(matrix,visited,i,0,1,INT_MIN,ans);
            dfs(matrix,visited,i,n-1,2,INT_MIN,ans);
        }
        for (int j=0; j<n; ++j) {
            dfs(matrix,visited,0,j,1,INT_MIN,ans);
            dfs(matrix,visited,m-1,j,2,INT_MIN,ans);
        }
        return ans;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& visited,
             int i, int j, int ocean, int pre, vector<vector<int>> &ans)
    {
        int m=matrix.size(),n=matrix[0].size();
        if (i<0||i>=m||j<0||j>=n||matrix[i][j]<pre||visited[i][j]==3||visited[i][j]==ocean) return;
        visited[i][j]=visited[i][j]|ocean;
        if (visited[i][j]==3) ans.push_back({i,j});
        dfs(matrix,visited,i+1,j,ocean,matrix[i][j],ans);
        dfs(matrix,visited,i-1,j,ocean,matrix[i][j],ans);
        dfs(matrix,visited,i,j+1,ocean,matrix[i][j],ans);
        dfs(matrix,visited,i,j-1,ocean,matrix[i][j],ans);
    }
};

/***** First Visit *****/
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
    {
        if (matrix.size()==0||matrix[0].size()==0) return {};
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> visited(m,vector<int>(n));
        vector<vector<int>> ans;
        for (int i=0; i<m; ++i) {
            dfs(matrix,visited,i,0,INT_MIN,1,ans);
            dfs(matrix,visited,i,n-1,INT_MIN,2,ans);
        }
        for (int i=0; i<n; ++i) {
            dfs(matrix,visited,0,i,INT_MIN,1,ans);
            dfs(matrix,visited,m-1,i,INT_MIN,2,ans);
        }
        return ans;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& visited,
             int i, int j, int pre, int creach, vector<vector<int>> &ans)
    {
        int m=matrix.size(), n=matrix[0].size();
        if (i<0||i>=m||j<0||j>=n||pre>matrix[i][j]||visited[i][j]==3||visited[i][j]==creach) return;
        visited[i][j]=visited[i][j]|creach;
        if (visited[i][j]==3) ans.push_back({i,j});
        dfs(matrix,visited,i+1,j,matrix[i][j],creach,ans);
        dfs(matrix,visited,i-1,j,matrix[i][j],creach,ans);
        dfs(matrix,visited,i,j+1,matrix[i][j],creach,ans);
        dfs(matrix,visited,i,j-1,matrix[i][j],creach,ans);
    }
};
