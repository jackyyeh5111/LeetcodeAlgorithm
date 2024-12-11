#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        auto manhattan_distance = [&](int row, int col) {
            return (rows - 1 - row) + (cols - 1 - col);
        };

        using Node = tuple<int, int, int, int>; // (estimated_cost, steps, row, col, remainingEliminations)
        auto compare = [](const Node& a, const Node& b) {
            return get<0>(a) > get<0>(b); // Min-heap based on estimated_cost
        };
        priority_queue<Node, vector<Node>, decltype(compare)> pq(compare);
        unordered_set<string> seen;

        pq.emplace(manhattan_distance(0, 0), 0, 0, k);
        seen.insert("0,0," + to_string(k));

        while (!pq.empty()) {
            auto [estimated_cost, steps, row, col, remainEliminations] = pq.top();
            pq.pop();

            if (row == rows - 1 && col == cols - 1) {
                return steps;
            }

            for (auto [dr, dc] : vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                int new_row = row + dr, new_col = col + dc;
                if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols) {
                    int new_eliminations = remainEliminations - grid[new_row][new_col];
                    string state_key = to_string(new_row) + "," + to_string(new_col) + "," + to_string(new_eliminations);

                    if (new_eliminations >= 0 && seen.find(state_key) == seen.end()) {
                        seen.insert(state_key);
                        int new_steps = steps + 1;
                        int new_cost = new_steps + manhattan_distance(new_row, new_col);
                        pq.emplace(new_cost, new_steps, new_row, new_col, new_eliminations);
                    }
                }
            }
        }

        return -1;
    }
};
