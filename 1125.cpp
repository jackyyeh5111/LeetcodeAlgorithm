#include "utils.hpp"

/*
    這題比 691 多了以下 constraint 可以玩味，並且不用考慮字串內重複的字元：
        All the strings of people[] are unique.

    # definition
    dp[i]: the minimum number of people that consists of team.

    req_skills = ["a", "b"]

    people with skills = ["a", "c"]
    state: 10

    # transfer function
    dp[i] = min( dp[i], dp[j]+1 )
 */

class Solution {
 public:
  vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                     vector<vector<string>>& people) {
    int N = req_skills.size();
    vector<int> dp(1 << N, INT_MAX);
    dp[0] = 0;

    vector<pair<int, int>> prev(1 << N);

    for (int i = 0; i < (1 << N); i++) {
      if (dp[i] == INT_MAX) continue;
      for (int k = 0; k < people.size(); k++) {
        int j = findNextStatus(i, req_skills, people[k]);
        if (dp[i] + 1 < dp[j]) {
          dp[j] = dp[i] + 1;
          prev[j] = make_pair(i, k);
        }

        // cout << "i: " << bitset<3>(i) << " | j: " << bitset<3>(j) << '\n';
        // print(req_skills);
        // print(skills);
        // cout << "dp[i]: " << dp[i] << " | dp[j]: " << dp[j] << '\n';
      }
    }

    int status = (1 << N) - 1;
    vector<int> ans;
    while (status != 0) {
      ans.push_back(prev[status].second);
      status = prev[status].first;
    }

    return ans;
  }

 private:
  int findNextStatus(int status, const vector<string>& req_skills,
                     const vector<string>& skills) {
    int N = req_skills.size();
    int new_status = status;
    for (const string skill : skills) {
      for (int i = 0; i < N; i++) {
        if (((new_status >> i) & 1) != 0) continue;
        if (skill == req_skills[i]) {
          new_status += (1 << i);
          break;
        }
      }
    }

    return new_status;
  }
};

int main() {
  vector<string> req_skills{"java", "nodejs", "reactjs"};
  vector<vector<string>> people{{"java"}, {"nodejs"}, {"nodejs", "reactjs"}};
  Solution sol;
  vector<int> ans = sol.smallestSufficientTeam(req_skills, people);
  print(ans);
  //   cout << "ans: " << ans << '\n';
  return 0;
}
