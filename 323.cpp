class UnionFind {
public:
    vector<int> parents, ranks;
    int count;
    UnionFind(int n) {
        count = n;
        parents.resize(n);
        ranks.resize(n, 1);
        for (int i = 0; i < n; i++) parents[i] = i;
    }
    int find(int id) {
        if (parents[id] == id)  return id;
        parents[id] = find(parents[id]); // path compression
        return parents[id];
    }
    void Union(int id1, int id2) {
        // already in a same set
        int root1 = find(id1);
        int root2 = find(id2);
        if ( root1 == root2 ) return; 
        
        // union by rank
        if (ranks[root1] < ranks[root2]) {
            parents[root2] = root1;
            ranks[root2]++;
        }
        else {
            parents[root1] = root2;
            ranks[root1]++;
        }
        count--;
    }
    int getCount() const {return count;}
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (const auto& edge : edges) {
            uf.Union(edge[0], edge[1]);
        }
        return uf.getCount();
    }
};

/* 
    0 1 2 3 4


                 [0]
               /     \
            [1]      [2]
            /
          [4]
 */