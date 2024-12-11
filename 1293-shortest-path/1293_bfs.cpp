#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n_rows = grid.size(), cols = grid[0].size();
        auto manhattan_distance = [&](int row, int col) {
            return (n_rows - 1 - row) + (cols - 1 - col);
        };

        queue<tuple<int, int, int, int>> queue; // (steps, row, col, remainingEliminations)
        unordered_set<string> seen;

        queue.emplace(0, 0, 0, k);
        seen.insert("0,0," + to_string(k));

        while (!queue.empty()) {
            auto [steps, row, col, remainEliminations] = queue.front();
            queue.pop();

            if (row == n_rows - 1 && col == cols - 1) {
                return steps;
            }

            for (auto [dir_row, dir_col] : vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                int new_row = row + dir_row;
                int new_col = col + dir_col;
                if (new_row < 0 || new_row >= n_rows || new_col < 0 || new_col >= cols)
                    continue;
                int new_eliminations = remainEliminations - grid[new_row][new_col];
                string state_key = to_string(new_row) + "," + to_string(new_col) + "," + to_string(new_eliminations);

                if (new_eliminations >= 0 && seen.count(state_key) == 0) {
                    seen.insert(state_key);
                    queue.emplace(steps + 1, new_row, new_col, new_eliminations);
                }
            }
        }

        return -1;
    }
};
