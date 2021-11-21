/*
    trivial graph traverse problem.
    Insiide each room <-> key, it represents an edge cross
    T:O(V+E) dfs traverse.
    Implement stack/recursive
*/

// recursive
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n=rooms.size(),nodes=0;
        vector<bool> visited(n,0);
        dfs(rooms,visited,0,nodes);
        return nodes==n;
    }

    void dfs(vector<vector<int>> &rooms, vector<bool> &visited, int u, int &nodes)
    {
        if (visited[u]) return;
        visited[u]=true; nodes++;
        for (int v:rooms[u])
            dfs(rooms,visited,v,nodes);
    }
};

// stack
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n=rooms.size();
        unordered_set<int> visited;
        stack<int> s; s.push(0);
        visited.insert(0);
        while (!s.empty()) {
            int u=s.top(); s.pop();
            for (int &v:rooms[u]) {
                if (visited.count(v)==0) {
                    visited.insert(v);
                    s.push(v);
                }
            }
        }
        return visited.size()==n;

    }
};

// stack
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n=rooms.size();
        unordered_set<int> visited;
        stack<int> s; s.push(0);
        while (!s.empty()) {
            int u=s.top(); s.pop();
            if (visited.count(u)) continue;
            visited.insert(u);
            for (int &v:rooms[u])
                s.push(v);
        }
        return visited.size()==n;
    }
};
