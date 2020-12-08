/*
    a/b=2, b/c=3;
    a->b->c
    6  3  1
    a->b=2,b->c=3
    a->c=2*3=6
    -----
    a/c=4,b/c=3

    a<---c<---b
     ---> --->
    a->c=4, c->b=1/3
    a->c=4*1/3=1.6667
    -----
    Difected Graph
    query:DFS:O(V+E)
    T:O(k*(V+E))/S:O(V+E+k), where k denotes queries.size()
*/
class Solution {
public:
    unordered_map<string,unordered_map<string,double>> graph;
    unordered_map<string,bool> visited;
    vector<double> ans;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        int n=equations.size();
        for (int i=0; i<n; ++i) {
            string u=equations[i][0];
            string v=equations[i][1];
            double w=values[i];
            graph[u][v]=w;
            graph[v][u]=1.0/w;
            visited[u]=false;
            visited[v]=false;
        }

        for (auto q:queries) {
            if (graph.count(q[0])==0&&graph.count(q[1])==0)
                ans.push_back(-1);
            else if (!dfs(q[0],q[1],1))
                ans.push_back(-1);
        }
        return ans;
    }

    bool dfs(string cur, string dst, double value)
    {
        if (cur==dst) {ans.push_back(value); return true;}
        visited[cur]=true;
        bool found=false;
        for (auto edge:graph[cur]) {
            if (visited[edge.first]) continue;
            if (dfs(edge.first,dst,value*edge.second)) {
               found=true; break;
            }
        }
        visited[cur]=false;
        return found;
    }
};
