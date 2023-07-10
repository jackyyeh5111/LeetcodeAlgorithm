/* 
  Correct answer
 */
class UnionFind {
    public:
        UnionFind(const vector<vector<char>>& grid) {
            int num_r = grid.size();
            int num_c = grid[0].size();
            parents.resize(num_r * num_c);
            ranks.resize(num_r * num_c);
            count = 0;
            for (int r = 0; r < num_r; ++r) 
                for (int c = 0; c < num_c; ++c) {
                    int idx = r * num_c + c;
                    if (grid[r][c] == '0') {
                        parents[idx] = -1; // dummy
                    }
                    else {
                        parents[idx] = idx;
                        ++count;
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
            --count;
        }
        int getCount() {
            return count;
        }
        vector<int> parents;
        vector<int> ranks;
        int count;
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
                grid[r][c] = '0'; // Not need an extra visited vector.
                for (auto dir : dirs) {
                    int nextR = r + dir[0];
                    int nextC = c + dir[1];
                    if (nextR < 0 || nextC < 0 || nextR >= num_r || nextC >= num_c)
                        continue;
                    if (grid[nextR][nextC] == '0')
                        continue;
                    grid[r][c] = '0';
                    uf.Union(r * num_c + c, nextR * num_c + nextC);
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

