class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        std::vector<int> group(graph.size(),0);
        for (int i=0;i<graph.size()-1;++i){
            if(group[i]!=0) continue;
            std::stack<int> record;
            record.push(i);
            group[i] = 1;
            while(!record.empty()){
                int vertice = record.top();
                record.pop();
                for (int adj_vertice : graph[vertice]){
                    if (group[adj_vertice]!=0 && group[adj_vertice]==group[vertice])
                        return false;
                    if (group[adj_vertice]!=0)
                        continue;
                    group[adj_vertice] = 3-group[vertice];
                    record.push(adj_vertice);
                }
            }
        }
        return true;
    }
};
