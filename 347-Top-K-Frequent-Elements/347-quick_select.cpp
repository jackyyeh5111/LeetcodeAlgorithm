#include "../utils.hpp"

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
class Solution
{
public:
    unordered_map<int, int> map;
    vector<pair<int, int>> pairs;
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        for (auto num : nums) {
            map[num]++;
        }

        for (auto pair : map) {
            pairs.push_back(pair);
        }

        int freq = quickSelect(0, nums.size() - 1, k);
        vector<int> ans;
        for (auto pair : map) {
            if (pair.second >= freq)
                ans.push_back(pair.first);
        }

        return ans;
    }

    /*
        l   h
        S S S M M M L L L
            p
     */
    int quickSelect(int start, int end, int k)
    {
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

int main(int argc, char **argv)
{
    std::vector<int> nums{1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution sol;
    vector<int> ans = sol.topKFrequent(nums, k);
    print(ans);

    return 0;
}