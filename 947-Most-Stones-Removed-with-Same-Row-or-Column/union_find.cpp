class UnionFind {
    public:
        UnionFind(const vector<vector<int>>& stones) {
            int N = stones.size();
            parents.resize(N);
            for (int i = 0; i < N; i++) 
                parents[i] = i;
            ranks.resize(N);
            num_ccompts = N;
        }
        int find(int x) { // union by compression
            if (parents[x] == x) 
                return x;
            parents[x] = find(parents[x]);
            return parents[x];
        }
        void Union(int x, int y) { // union by ranks
            int rootx = find(x);
            int rooty = find(y);
            if (rootx == rooty)
                return;
            
            if (ranks[rootx] > ranks[rooty]) {
                parents[rooty] = rootx;
                ranks[rootx]++;
            }
            else {
                parents[rootx] = rooty;
                ranks[rooty]++;
            }
            num_ccompts--;
        }
        int count() const {
            return num_ccompts;
        }

        vector<int> parents;
        vector<int> ranks;
        int num_ccompts;
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf(stones);
        
        int N = stones.size();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    uf.Union(i, j);
            }
        }
        return N - uf.count();
    }
};

/* 
    OXO
    XOX
    OXO
 */