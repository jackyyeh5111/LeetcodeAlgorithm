/*
    w->e t->f r->t e->r
    w->e->r->t->f
    |_____^
    a->z

    a->c ca     acb
    b--^

    topologic order ->  postDFS over ALL NODES then reverse to ensure aboce ex.
    -----
    Intution: every 2 pair can give us at most 1 edge if we found the order of 2 different char.

    Construct the graph which node u -> node v denotes u is smaller than v in lexicon order.
    Apply topological sort to find the smallest lexicon order.
    T:O(V+E)/S:O(V+E)
*/
class Solution {
public:
    string alienOrder(vector<string>& words)
    {
        if (words.size()==1) return words[0];
        unordered_map<char,unordered_set<char>> graph;
        unordered_map<char,int> visited;
        unordered_map<char,int> indegree;
        int n=words.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                int k=min(words[i].length(),words[j].length()),t=0;
                for (; t<k; ++t) {
                    if (words[i][t]==words[j][t]){
                        if (graph.count(words[i][t])==0)
                            graph[words[i][t]]={};
                        if (visited.count(words[i][t])==0)
                            visited[words[i][t]]=0;
                        if (indegree.count(words[i][t])==0)
                            indegree[words[i][t]]=0;
                    }
                    else{
                        graph[words[i][t]].insert(words[j][t]);
                        visited[words[i][t]]=0; visited[words[j][t]]=0;
                        indegree[words[j][t]]++;
                        if (indegree.count(words[i][t])==0)
                            indegree[words[i][t]]=0;
                        break;
                    }
                }
                if ((int)words[i].size()-t>0&&t==(int)words[j].size()) return "";
                for (int q=t; q<words[i].length(); ++q) {
                    if (graph.count(words[i][q])==0) graph[words[i][q]]={};
                    if (visited.count(words[i][q])==0) visited[words[i][q]]=0;
                    if (indegree.count(words[i][q])==0) indegree[words[i][q]]=0;
                }
                for (int q=t; q<words[j].length(); ++q) {
                    if (graph.count(words[j][q])==0) graph[words[j][q]]={};
                    if (visited.count(words[j][q])==0) visited[words[j][q]]=0;
                    if (indegree.count(words[j][q])==0) indegree[words[j][q]]=0;
                }
            }
        }
        string ans="";
        for (auto it=indegree.begin(); it!=indegree.end(); ++it) {
            if (it->second==0) {
                string temp="";
                if (postDFS(graph,visited,it->first,temp)) return "";
                ans+=temp;
            }
        }
        if (ans.size()!=graph.size()) return "";
        reverse(ans.begin(),ans.end());
        return ans;
    }

    // true if cyclic
    bool postDFS(unordered_map<char,unordered_set<char>> &graph,
                 unordered_map<char,int> &visited,
                 char u, string &order)
    {
        if (visited[u]==1) return true;
        else if (visited[u]==2) return false;
        visited[u]=1;
        for (int v:graph[u]) {
            if (postDFS(graph,visited,v,order))
                return true;
        }
        order+=u;
        visited[u]=2;
        return false;
    }
};
