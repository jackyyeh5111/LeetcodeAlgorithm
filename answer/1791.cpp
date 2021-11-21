class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
        unordered_map<int,vector<int>> graph;
        for (auto edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for (auto p:graph) {
            if (p.second.size()==graph.size()-1)
                return p.first;
        }
        return -1;
    }
};
