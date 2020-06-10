class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size()+1, -1);
        for (vector<int> edge : edges) {
            bool cyclic = set_union(edge[0], edge[1], parents);
            if (cyclic) return edge;
        }
        return {{}};
    }

    int find(int node, vector<int>& parents) {
        if (parents[node] < 0)
            return node;
        return find(parents[node], parents);
    }

    bool set_union (int x, int y, vector<int>& parents) {
        int parent_x = find(x, parents);
        int parent_y = find(y, parents);
        cout << parent_x << "," << parent_y << endl;
        if (parent_x < parent_y)
            parents[parent_y] = parent_x;
        else
            parents[parent_x] = parent_y;

        return parent_x==parent_y;
    }

};
