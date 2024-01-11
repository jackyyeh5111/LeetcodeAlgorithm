#include "utils.hpp"

/* 
    More elegant!

    If conflict happens, there are cycles among the alien rule.

    wrd
    wre

    in_degrees = {
        z: 1
        x: 1
    }
    map = {
        z: [x]
        x: [z]
    }

    z -> x
    x -> z
 */
class Solution2 {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> in_degrees;
        unordered_map<char, vector<char>> nexts;
        
        // initialzie in_degrees
        for (string word : words)
            for (char ch : word)
                in_degrees[ch] = 0;

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int j = 0, len = min(w1.size(), w2.size());
            for (; j < len; j++) {
                if (w1[j] != w2[j]) break;
            }
            if (j == len) {
                if (w1.size() > w2.size())
                    return "";       
                continue;
            }

            char ch1 = w1[j], ch2 = w2[j];
            in_degrees[ch2]++;
            nexts[ch1].push_back(ch2);
        }

        // topological sort
        queue<char> que;
        for (auto it = in_degrees.begin(); it != in_degrees.end(); it++) {
            if (it->second == 0)
                que.push(it->first);
        }
        
        string ans = "";
        while(!que.empty()) {
            char ch = que.front();
            que.pop();
            ans += ch;
            for (char next_ch : nexts[ch]) {
                in_degrees[next_ch]--;
                if (in_degrees[next_ch] == 0)
                    que.push(next_ch);
            }
        }
        return ans.size() == in_degrees.size() ? ans : "";
    }
};

 */

/* ref:
    https://www.youtube.com/watch?v=yfGJFDkyEmE
 */

/*
  Finally correct!
 */
class Solution {
 public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> next;
    unordered_map<char, int> in_degrees;

    // init in_degrees
    for (auto word : words) {
      for (char ch : word) {
        in_degrees[ch] = 0;
      }
    }

    // compare across words
    for (int i = 0; i < words.size(); ++i) {
      for (int j = i; j < words.size(); ++j) {
        bool hit = false;  // for handing the wrong case happening in the
                           // previous solution
        for (int k = 0; k < min(words[i].size(), words[j].size()); ++k) {
          if (words[i][k] == words[j][k]) continue;
          auto ret = next[words[i][k]].insert(words[j][k]);
          if (ret.second)  // insert operation taking place
            ++in_degrees[words[j][k]];
          hit = true;
          break;
        }
        if (!hit && words[i].size() > words[j].size()) return "";
      }
    }

    // init queue
    queue<char> que;
    for (auto it = in_degrees.begin(); it != in_degrees.end(); ++it) {
      if (it->second == 0) que.push(it->first);
    }

    // topological sort
    string ans = "";
    while (!que.empty()) {
      char ch = que.front();
      que.pop();
      ans += ch;
      for (char child : children[ch]) {
        --in_degrees[child];
        if (in_degrees[child] == 0) que.push(child);
      }
    }

    return ans.size() == in_degrees.size() ? ans : "";
  }
};

/*
  Wrong answer!
  Wrong case:
    - words: ["abc","ab"]
    - output: cba
    - expected: ""
 */
class Solution {
 public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> next;
    unordered_map<char, int> in_degrees;

    // init in_degrees
    for (auto word : words) {
      for (char ch : word) {
        in_degrees[ch] = 0;
      }
    }

    for (int i = 0; i < words.size(); ++i) {
      for (int j = i; j < words.size(); ++j) {
        // compare across words
        for (int k = 0; k < min(words[i].size(), words[j].size()); ++k) {
          if (words[i][k] == words[j][k]) continue;
          auto ret = next[words[i][k]].insert(words[j][k]);
          if (ret.second)  // insert operation taking place
            ++in_degrees[words[j][k]];
          break;
        }
      }
    }

    queue<char> que;
    for (auto it = in_degrees.begin(); it != in_degrees.end(); ++it) {
      if (it->second == 0) {
        que.push(it->first);
        --in_degrees[it->first];
      }
    }

    // topological sort (bfs)
    string ans = "";
    while (!que.empty()) {
      char ch = que.front();
      que.pop();
      ans += ch;
      for (auto it = next[ch].begin(); it != next[ch].end(); ++it) {
        if (--in_degrees[*it] == 0) {
          que.push(*it);
        }
      }
    }
    return ans.size() == in_degrees.size() ? ans : "";
  }
};

/*
  Wrong answer!
  We do not have to compare characters within a word.
 */
class Solution {
 public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> next;
    unordered_map<char, int> in_degrees;

    // init in_degrees
    for (auto word : words) {
      for (char ch : word) {
        in_degrees[ch] = 0;
      }
    }

    for (int i = 0; i < words.size(); ++i) {
      // compare across words
      if (i < words.size() - 1) {
        for (int j = 0; j < min(words[i].size(), words[i + 1].size()); ++j) {
          if (words[i][j] == words[i + 1][j]) continue;
          auto ret = next[words[i][j]].insert(words[i + 1][j]);
          if (ret.second)  // insert operation taking place
            ++in_degrees[words[i + 1][j]];
          break;
        }
      }

      // compare within the word
      for (int j = 0; j < words[i].size() - 1; ++j) {
        if (words[i][j] == words[i][j + 1]) continue;
        auto ret = next[words[i][j]].insert(words[i][j + 1]);
        if (ret.second) ++in_degrees[words[i][j + 1]];
      }
    }

    queue<char> que;
    for (auto it = in_degrees.begin(); it != in_degrees.end(); ++it) {
      if (it->second == 0) {
        que.push(it->first);
        --in_degrees[it->first];
      }
    }

    // topological sort (bfs)
    string ans = "";
    while (!que.empty()) {
      char ch = que.front();
      que.pop();
      ans += ch;
      for (auto it = next[ch].begin(); it != next[ch].end(); ++it) {
        if (--in_degrees[*it] == 0) {
          que.push(*it);
        }
      }
    }
    return ans.size() == in_degrees.size() ? ans : "";
  }
};

int main() {
  int numCourses = 4;
  //   vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  Solution sol;
  vector<int> ans = sol.findOrder(numCourses, prerequisites);
  print(ans);

  return 0;
}
