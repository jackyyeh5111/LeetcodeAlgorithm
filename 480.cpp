#include "utils.hpp"

/* Visit 1
ref:

*/

class Solution {
 public:
  std::multiset<double> m;

  double findMedian(double remove, double add) {
    m.insert(add);
    m.erase(m.find(remove));
    int n = m.size();
    double a = *next(m.begin(), n / 2 - 1);
    double b = *next(m.begin(), n / 2);
    return n & 1 ? b : (a + b) * 0.5;
  }

  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> ans;
    if (nums.size() < k) return ans;
    for (int i = 0; i < k; i++) {
      m.insert(nums[i]);
    }
    ans.push_back(findMedian(0, 0));
    for (int i = k; i < nums.size(); i++) {
      ans.push_back(findMedian(nums[i - k], nums[i]));
    }
    return ans;
  }
};

int main(int argc, char **argv) {
  vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  Solution sol;
  vector<double> ans = sol.medianSlidingWindow(nums, k);
  print(ans);

  return 0;
}