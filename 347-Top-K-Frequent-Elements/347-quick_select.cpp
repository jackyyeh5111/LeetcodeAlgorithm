#include "../utils.hpp"

/*
    quicksort
    Use the last element as pivot. Simplify comparisons compared to Solution1.
 */
class Solution2 {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    for (int num : nums) ++um[num];
    vector<int> freqs;
    for (auto pair : um) freqs.push_back(pair.second);
    int freq = quickSelect(freqs, k, 0, freqs.size() - 1);

    vector<int> res;
    for (auto pair : um) {
      if (pair.second >= freq) res.push_back(pair.first);
    }

    return res;
  }

 private:
  unordered_map<int, int> um;
  int quickSelect(vector<int> &freqs, int k, int low, int high) {
    int pivot = freqs[high];
    int pi_idx = low;
    for (int i = low; i < high; ++i) {
      if (freqs[i] < pivot) {
        swap(freqs[pi_idx], freqs[i]);
        ++pi_idx;
      }
    }
    swap(freqs[pi_idx], freqs[high]);

    int cnt_large_and_equal_freq = high - pi_idx + 1;
    if (cnt_large_and_equal_freq > k)
      return quickSelect(freqs, k, pi_idx, high);
    else if (cnt_large_and_equal_freq == k)
      return freqs[pi_idx];
    else
      return quickSelect(freqs, k - cnt_large_and_equal_freq, low, pi_idx - 1);
  }
};

/*
    like quick sort:
    M = pivot value

          l   h
    S S S M M M L L L
          p

    這裡要 quick select 目標 frequency! 不是 value

    if len(L) >= k:
        return quickSelect(h+1, end, k)
    else if len(L) < k && len(L+M) >= k:
        return M.freq
    else
        return quickSelect(start, l-1, k-(end-l+1))

 */
class Solution {
 public:
  unordered_map<int, int> map;
  vector<pair<int, int>> pairs;
  vector<int> topKFrequent(vector<int> &nums, int k) {
    for (auto num : nums) {
      map[num]++;
    }

    for (auto pair : map) {
      pairs.push_back(pair);
    }

    int freq = quickSelect(0, nums.size() - 1, k);
    vector<int> ans;
    for (auto pair : map) {
      if (pair.second >= freq) ans.push_back(pair.first);
    }

    return ans;
  }

  /*
      l   h
      S S S M M M L L L
          p
   */
  int quickSelect(int start, int end, int k) {
    int low = start;
    int hi = end;
    int p = low;
    int pivot_val = pairs[(start + end) / 2].second;

    // sort colors (top-down in-place sorting)
    while (p <= hi) {
      int freq = pairs[p].second;
      if (freq < pivot_val) {
        swap(pairs[low], pairs[p]);
        low++;
        p++;
      } else if (freq == pivot_val) {
        p++;
      } else {
        swap(pairs[hi], pairs[p]);
        hi--;
      }
    }

    if (end - hi >= k) {
      return quickSelect(hi + 1, end, k);
    } else if (end - low + 1 >= k) {
      return pivot_val;
    } else {
      return quickSelect(start, low - 1, k - (end - low + 1));
    }
  }
};

int main(int argc, char **argv) {
  std::vector<int> nums{1, 1, 1, 2, 2, 3, 3, 3};
  int k = 2;
  SolutionTest sol;
  vector<int> ans = sol.topKFrequent(nums, k);
  print(ans);

  return 0;
}