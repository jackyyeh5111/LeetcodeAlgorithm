
/******************** BFS ********************/
class Solution {
public:
    unordered_map<string,vector<string>> table;
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        /*
            Consider tickets as directed graph.
            Apply BFS to check if all paths are visited.
            T:O(V^2+2*E), S:O(V+E)
        */
        for(auto ticket:tickets){
            if (table.find(ticket[0])==table.end())
                table[ticket[0]]=vector<string>{};
            int pos=0;
            for (;pos<table[ticket[0]].size(); ++pos){
                if (ticket[1]<table[ticket[0]][pos]) break;
            }
            table[ticket[0]].insert(table[ticket[0]].begin()+pos,ticket[1]);
        }
        vector<string> ans; int size=tickets.size();
        ans.push_back("JFK");
        BFS(ans, "JFK", size+1);
        return ans;
    }

    bool BFS(vector<string> &ans, string node, int size)
    {
        if (ans.size()==size) return true;
        for (int i=0; i<table[node].size(); ++i) {
            if(table[node][i]=="") continue;
            string dst=table[node][i];
            table[node][i]="";
            ans.push_back(dst);
            bool reachable = BFS(ans, dst, size);
            if(reachable) return true;
            else{
                ans.pop_back();
                table[node][i]=dst;
            }
        }
        return false;
    }
};

/******************** DFS ********************/
class Solution {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        vector<string> result;
        void dfs(string vtex)
        {
            auto & edges = graph[vtex];
            while (!edges.empty())
            {
                string to_vtex = edges.top();
                edges.pop();
                dfs(to_vtex);
            }
            result.push_back(vtex);
        }
    public:
        vector<string> findItinerary(vector<pair<string, string>> tickets) {
            for (auto e : tickets)
                graph[e.first].push(e.second);
            dfs("JFK");
            reverse(result.begin(), result.end());
            return result;
        }
    };
