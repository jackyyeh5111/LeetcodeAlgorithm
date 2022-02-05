#include "utils.hpp"

/*
    Approach 1: Brute force search
    Worst case: O(m*n) ==> 2(bits)*9(matrix size)*5(flip)

    基本想法：
    1. 每個位置最多翻一次，翻兩次 = 沒翻，翻三次 = 翻一次
    2. 翻的順序沒有差別

    ex:
        state: 1000 (filp mat[i][j])，每個 1's bit 代表 flip

        0 0 ==> 1 1
        0 1     1 1
*/

class Solution5 {
 public:
  int minFlips(vector<vector<int>>& mat) {
    m = mat.size();
    n = mat[0].size();

    int ans = INT_MAX;

    for (int state = 0; state < (1 << (m * n)); state++) {
      if (check(state, mat)) {
        ans = min(ans, __builtin_popcount(state));
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }

 private:
  int m, n;
  bool check(int state, const vector<vector<int>>& mat) {
    vector<vector<int>> flip_mat = mat;
    vector<pair<int, int>> dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {0, 0}};
    for (int i = 0; i < m * n; i++) {
      if ((state >> i) & 1) {
        int raw_r = i / n;
        int raw_c = i % n;

        for (auto dir : dirs) {
          int r = raw_r + dir.second;
          int c = raw_c + dir.first;

          if (c < 0 || c >= n || r < 0 || r >= m) continue;

          flip_mat[r][c] = 1 - flip_mat[r][c];
        }
      }
    }

    for (auto row : flip_mat)
      for (int num : row)
        if (num) return false;

    return true;
  }
};

class Solution4 {
 public:
  int minFlips(vector<vector<int>>& mat) {
    m = mat.size();
    n = mat[0].size();

    int ans = INT_MAX;

    for (int state = 0; state < (1 << (m * n)); state++) {
      if (check(state, mat)) {
        ans = min(ans, __builtin_popcount(state));
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }

 private:
  int m, n;
  bool check(int state, const vector<vector<int>>& mat) {
    vector<vector<int>> flip_mat = mat;
    vector<pair<int, int>> dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {0, 0}};
    for (int i = 0; i < m * n; i++) {
      if ((state >> i) & 1) {
        /* 這裏定義仍是錯的 >"< */
        int raw_r = i / n;
        int raw_c = i % m;

        for (auto dir : dirs) {
          int r = raw_r + dir.second;
          int c = raw_c + dir.first;

          if (c < 0 || c >= n || r < 0 || r >= m) continue;

          flip_mat[r][c] = 1 - flip_mat[r][c];
        }
      }
    }

    for (auto row : flip_mat)
      for (int num : row)
        if (num) return false;

    return true;
  }
};

class Solution3 {
 public:
  int minFlips(vector<vector<int>>& mat) {
    m = mat.size();
    n = mat[0].size();

    int ans = INT_MAX;

    for (int state = 0; state < (1 << (m * n)); state++) {
      if (check(state, mat)) {
        ans = min(ans, __builtin_popcount(state));
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }

 private:
  int m, n;
  bool check(int state, const vector<vector<int>>& mat) {
    vector<vector<int>> flip_mat = mat;
    vector<pair<int, int>> dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {0, 0}};
    for (int i = 0; i < m * n; i++) {
      if ((state >> i) & 1) {
        /* 這裏 raw_r, raw_c 定義有誤！ */
        int raw_r = i / m;
        int raw_c = i % n;

        for (auto dir : dirs) {
          int r = raw_r + dir.second;
          int c = raw_c + dir.first;

          if (c < 0 || c >= n || r < 0 || r >= m) continue;

          flip_mat[r][c] = 1 - flip_mat[r][c];
        }

        cout << "state: " << state << '\n';
        cout << "i: " << i << '\n';
        cout << "row: " << raw_r << " | col: " << raw_c << '\n';
        print(flip_mat);
      }
    }

    for (auto row : flip_mat)
      for (int num : row)
        if (num) return false;

    return true;
  }
};

class Solution2 {
 public:
  int minFlips(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    int ans = INT_MAX;

    for (int state = 0; state < (1 << (m * n)); state++) {
      if (check(state, mat)) {
        ans = min(ans, __builtin_popcount(state));
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }

 private:
  bool check(int state, const vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> flip_mat = mat;
    vector<pair<int, int>> dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {0, 0}};
    for (int i = 0; i < m * n; i++) {
      if ((state >> i) & 1) {
        int raw_y = i / m;
        int raw_x = i % n;

        /* 這裡的x, y 定義有誤！！ */
        for (auto dir : dirs) {
          int y = raw_y + dir.second;
          int x = raw_x + dir.first;

          if (x < 0 || x >= n || y < 0 || y >= m) continue;

          flip_mat[x][y] = 1 - flip_mat[x][y];
        }
      }
    }

    for (auto row : flip_mat)
      for (int num : row)
        if (num) return false;

    return true;
  }
};

class Solution {
 public:
  int minFlips(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    int ans = INT_MAX;

    // Wrong here!!!!
    for (int state = 0; state < m * n; state++) {
      if (check(state, mat)) {
        ans = min(ans, __builtin_popcount(state));
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }

 private:
  bool check(int state, const vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> flip_mat = mat;
    vector<pair<int, int>> dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {0, 0}};
    for (int i = 0; i < m * n; i++) {
      if ((state >> i) & 1) {
        int raw_y = i / m;
        int raw_x = i % n;

        /* 這裡的x, y 定義有誤！！ */
        for (auto dir : dirs) {
          int y = raw_y + dir.second;
          int x = raw_x + dir.first;

          if (x < 0 || x >= n || y < 0 || y >= m) continue;

          flip_mat[x][y] = 1 - flip_mat[x][y];
        }
      }
    }

    for (auto row : flip_mat)
      for (int num : row)
        if (num) return false;

    return true;
  }
};

int main() {
  vector<vector<int>> mat{{0}, {1}, {1}};
  //   vector<vector<int>> mat{{1, 0, 0}, {1, 0, 0}};
  //   vector<vector<int>> mat{{0, 0}, {0, 1}};

  Solution5 sol;
  int ans = sol.minFlips(mat);
  cout << "ans: " << ans << '\n';
  return 0;
}
