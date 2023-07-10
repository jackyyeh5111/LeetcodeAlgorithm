class UnionFind {
    public:
        void add(int i) {
            parents_[i] = i;
            ranks_[i] = 0;
        }
        bool exist(int i) const {
            return parents_.find(i) != parents_.end();
        }
        int find(int i) { // path compression
            if (parents_[i] != i)
                parents_[i] = find(parents_[i]);
            return parents_[i];
        }
        void Union(int x, int y) { // union by rank
            int rootx = find(x);
            int rooty = find(y);
            if (ranks_[rootx] < ranks_[rooty]) {
                parents_[rootx] = rooty;
                ++ranks_[rooty];
            }
            else {
                parents_[rooty] = rootx;
                ++ranks_[rootx];
            }
        }
        int getLongestConsecutive() {
            unordered_map<int, int> cnts;
            int max_cnt = 0;
            for (auto it = parents_.begin(); it != parents_.end(); ++it) {
                int root = find(it->first);
                ++cnts[root];
                if (cnts[root] > max_cnt)
                    max_cnt = cnts[root];
            }
            return max_cnt;
        }
    private:
        unordered_map<int, int> parents_, ranks_;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        UnionFind uf;
        for (int num : nums) {
            if (uf.exist(num))
                continue;
            uf.add(num);
            if (uf.exist(num + 1))
                uf.Union(num, num + 1);
            if (uf.exist(num - 1))
                uf.Union(num, num - 1);
        }
        return uf.getLongestConsecutive();
    }
};

/* 
    UnionFind()

    map = { 
        100: 0,
        4: 1,
        200: 2,
        1: 3,
        3: 1,
        2: 
    }
 */
