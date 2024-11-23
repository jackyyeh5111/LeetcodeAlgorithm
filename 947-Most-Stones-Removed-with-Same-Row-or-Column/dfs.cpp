class Solution {
public:
    vector<vector<int>> adjs;
    vector<bool> visited;
    int removeStones(vector<vector<int>>& stones) {
        // convert from sparse vectors to adj list => O(n^2) time
        adjs.resize(stones.size());
        int size = stones.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adjs[i].push_back(j);
                    adjs[j].push_back(i);
                }
            }
        }
        
        visited.resize(stones.size(), false);
        // dfs
        int num_left_stones = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (visited.at(i)) continue;
            dfs(stones, i);
            num_left_stones++;
        }
        return stones.size() - num_left_stones;
    }
    void dfs(const vector<vector<int>>& stones, int idx) {
        if (visited.at(idx)) return;
        visited[idx] = true;
        for (int next : adjs.at(idx)) {
            if (visited.at(next)) continue;
            dfs(stones, next);
        }
    }

};