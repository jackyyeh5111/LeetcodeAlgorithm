/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,pair<int,vector<int>>> graph;
        for (auto employ:employees) {
            graph[employ->id]={employ->importance,employ->subordinates};
        }
        return help(graph,id);
    }

    int help(unordered_map<int,pair<int,vector<int>>> &graph, int id)
    {
        if (graph[id].second.empty())
            return graph[id].first;
        int ret=graph[id].first;
        for (int v:graph[id].second) {
            ret+= help(graph,v);
        }
        return ret;
    }
};
