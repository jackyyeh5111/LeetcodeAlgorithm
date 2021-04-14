/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

/*
    GridMaster represents the position we are steping on.
    Apply BFS to findout min dist to the target.
    T:O(V+E)/S:O(V+E)

    question: how to find out if visited? self defined
*/
class Solution {
public:
    vector<pair<char,int>> dirs={{'U',-2},{'D',2},{'L',-1},{'R',1}};
    unordered_map<char,char> inv={{'U','D'},{'D','U'},{'L','R'},{'R','L'}};
    int findShortestPath(GridMaster &master)
    {
        vector<vector<int>> table(1001,vector<int>(1001,-1));
        if (!dfs(table,master,500,500)) return -1;
        queue<pair<int,int>> q;
        q.push({500,500});
        // for (auto a:table) {
        //     for (auto b:a) cout<<b<<",";
        //     cout<<endl;
        // }
        int ans=0;
        while (!q.empty()) {
            int k=q.size();
            while (k--) {
                auto p=q.front(); q.pop();
                int x=p.first, y=p.second;
                if (table[x][y]<=0) continue;
                table[x][y]=-1;
                for (auto &d:dirs) {
                    if (table[x+d.second/2][y+d.second%2]<=0) continue;
                    else if (table[x+d.second/2][y+d.second%2]==2) return ans+1;
                    q.push({x+d.second/2,y+d.second%2});
                }
            }
            ans++;
        }
        return -1; //something wrong.
    }

    bool dfs(vector<vector<int>> &table, GridMaster &ms, int x, int y)
    {
        if (table[x][y]!=-1) return table[x][y]==2;
        bool found=false;
        if (ms.isTarget()) {table[x][y]=2; found=true;}
        else table[x][y]=1;
        for (auto d:dirs) {
            if (ms.canMove(d.first)){
                ms.move(d.first);
                found=dfs(table,ms,x+d.second/2,y+d.second%2)||found;
                ms.move(inv[d.first]);
            }
            else table[x+d.second/2][y+d.second%2]=0;
        }
        return found;
    }
};
