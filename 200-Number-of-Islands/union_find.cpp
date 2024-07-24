/* 
  Correct answer
 */
class UnionFind {
    public:
        vector<int> parents, ranks;
        int count = 0;
        UnionFind(const vector<vector<char>>& grid) {
            int num_r = grid.size();
            int num_c = grid[0].size();
            int num_node = num_r * num_c;
            parents.resize(num_node, -1);
            ranks.resize(num_node, -1);
            for (int r = 0; r < num_r; r++) {
                for (int c = 0; c < num_c; c++) {
                    int id = r * num_c + c;
                    if (grid[r][c] == '1') {
                        parents[id] = id; // default is itself
                        count++;
                    }
                }
            }
        }
        int Find(int id) { // path compression
            if (parents[id] == id)
                return id;
            parents[id] = Find(parents[id]);
            return parents[id];
        }
        void Union(int id1, int id2) { // rank compression
            int root1 = Find(id1);
            int root2 = Find(id2);
            if (root1 == root2)
                return;
            if (ranks[root1] > ranks[root2]) {
                parents[root2] = root1;
                ranks[root1]++;
            }
            else {
                parents[root1] = root2;
                ranks[root2]++;
            }
            count--;
        }
        int getCount() const {
            return count;
        }

};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        UnionFind uf(grid);
        int num_r = grid.size();
        int num_c = grid[0].size();
        
        // union find
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int r = 0; r < num_r; r++) {
            for (int c = 0; c < num_c; c++) {
                if (grid[r][c] == '0')
                    continue;
                
                int id1 = r * num_c + c;
                for (auto dir : dirs) {
                    int next_r = r + dir[0];
                    int next_c = c + dir[1];
                    
                    // check boundary
                    if (next_r < 0 || next_r >= num_r || next_c < 0 || next_c >= num_c)
                        continue;
                    if (grid[next_r][next_c] == '0')
                        continue;
                
                    int id2 = next_r * num_c + next_c;    
                    uf.Union(id1, id2);
                }
            }
        }
        return uf.getCount();
    }
};


/* Wrong answer 2
  Fail case:
    [["1"]]
  
  Without a dummy parent, it should not subtract dummy at function getNumRoots()
*/
class UnionFind {
    public:
        UnionFind(const vector<vector<char>>& grid) {
            int num_r = grid.size();
            int num_c = grid[0].size();
            parents.resize(num_r * num_c);
            ranks.resize(num_r * num_c);
            for (int r = 0; r < num_r; ++r) 
                for (int c = 0; c < num_c; ++c) {
                    int idx = r * num_c + c;
                    if (grid[r][c] == '0') {
                        parents[idx] = -1; // dummy
                    }
                    else {
                        parents[idx] = idx;
                    }
                }
        }
        int find(int idx) { // path compression
            if (parents[idx] == idx)
                return idx;
            parents[idx] = find(parents[idx]);
            return parents[idx];
        }
        void Union(int x, int y) { // rank compression
            int rootx = find(x);
            int rooty = find(y);
            if (rootx == rooty)
                return;
            
            if (ranks[rootx] > ranks[rooty]) {
                parents[rooty] = rootx;
                ++ranks[rootx];
            }
            else {
                parents[rootx] = rooty;
                ++ranks[rooty];
            }
        }
        int getNumRoots() {
            unordered_set<int> roots;
            for (int parent : parents)
                roots.insert(parent);
            return roots.size() - 1; // subtract dummy
        }
        vector<int> parents;
        vector<int> ranks;
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num_r = grid.size();
        int num_c = grid[0].size();

        UnionFind uf(grid);
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int r = 0; r < num_r; ++r) {
            for (int c = 0; c < num_c; ++c) {
                if (grid[r][c] == '0')
                    continue;
                for (auto dir : dirs) {
                    int nextR = r + dir[0];
                    int nextC = c + dir[1];
                    if (nextR < 0 || nextC < 0 || nextR >= num_r || nextC >= num_c)
                        continue;
                    if (grid[nextR][nextC] == '0')
                        continue;
                    uf.Union(r * num_c + c, nextR * num_c + nextC);
                }
            }
        }
        return uf.getNumRoots();
    }
};

/* Wrong answer */
class UnionFind {
    public:
        UnionFind(const vector<vector<char>>& grid) {
            int num_r = grid.size();
            int num_c = grid[0].size();
            parents.resize(num_r * num_c);
            ranks.resize(num_r * num_c);
            for (int r = 0; r < num_r; ++r) 
                for (int c = 0; c < num_c; ++c) {
                    if (grid[r][c] == '0') // coord that is value '0' still has a parent 0
                        continue;
                    int idx = r * num_c + c;
                    parents[idx] = idx;
                }
        }
        int find(int idx) { // path compression
            if (parents[idx] == idx)
                return idx;
            parents[idx] = find(parents[idx]);
            return parents[idx];
        }
        void Union(int x, int y) { // rank compression
            int rootx = find(x);
            int rooty = find(y);
            if (rootx == rooty)
                return;
            
            if (ranks[rootx] > ranks[rooty]) {
                parents[rooty] = rootx;
                ++ranks[rootx];
            }
            else {
                parents[rootx] = rooty;
                ++ranks[rooty];
            }
        }
        int getNumRoots() {
            unordered_set<int> roots;
            for (int parent : parents)
                roots.insert(parent);
            return roots.size();
        }
        vector<int> parents;
        vector<int> ranks;
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num_r = grid.size();
        int num_c = grid[0].size();

        UnionFind uf(grid);
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int r = 0; r < num_r; ++r) {
            for (int c = 0; c < num_c; ++c) {
                if (grid[r][c] == '0')
                    continue;
                for (auto dir : dirs) {
                    int nextR = r + dir[0];
                    int nextC = c + dir[1];
                    if (nextR < 0 || nextC < 0 || nextR >= num_r || nextC >= num_c)
                        continue;
                    if (grid[nextR][nextC] == '0')
                        continue;
                    uf.Union(r * num_c + c, nextR * num_c + nextC);
                }
            }
        }
        return uf.getNumRoots();
    }
};

