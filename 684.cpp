/* 
    Union find algo
 */
class UnionFind {
    public:
        UnionFind(int N) {
            // parent_[0] is dummy
            for (int i=0; i <= N; ++i)
                parent_.push_back(i);
            rank_.resize(N+1);
        }
        int find(int i) const {
            if (parent_[i] == i) return i;
            return find(parent_[i]);
        }
        void Union(int x, int y) {
            int rootx = find(x);
            int rooty = find(y);
            if (rank_[rootx] < rank_[rooty]) {
                parent_[rootx] = rooty;
                ++rank_[rooty];
            }
            else {
                parent_[rooty] = rootx;
                ++rank_[rootx];
            }
        }
        bool isSameGroup(int x, int y) const {
            return find(x) == find(y); 
        }
    private:
        vector<int> parent_;
        vector<int> rank_;
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size());
        vector<int> ans;
        for (auto edge : edges) {
            if (uf.isSameGroup(edge[0],  edge[1])) {
                ans = edge;
                break;
            }
            uf.Union(edge[0],  edge[1]);
        }
        return ans;
    }
};


/* 
    wrong answer
 */
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_set<int> nodes;
        vector<int> ans;
        for (auto edge : edges) {
            if (nodes.find(edge[0]) != nodes.end() && nodes.find(edge[1]) != nodes.end()) {
                ans = edge;
                break;
            }
            nodes.insert(edge[0]);
            nodes.insert(edge[1]);
        }
        return ans;
    }
};