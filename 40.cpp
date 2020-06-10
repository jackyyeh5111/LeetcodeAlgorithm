/*
Check duplicated case approach
    1. hashmap frequency checking.
    2. check if current entry is equal to the entry last one.
       If we meet 11, we will have these choice at this level(or depth).
       Example:
       11
       2 || 2 || 3 || 3 || 3
       Apparently, the second 2 and the 2nd & 3rd 3 will induce duplicate
       solutions, because we use DFS and these solutions have been computed in
       the path 112(first '2') or 113(first'3').

        ↓If we choose first 2,                          ↓If we choose second 2,
              112                                                  112
        2 || 3 || 3 || 3                                         3 || 3 || 3
*/

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> nums;
    unordered_map<int, int> freq;
    // T:O(2^n), T(n)=2T(n-1)+O(1), S:O(2^n)
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        // count frequency forduplicated entry.
        for (int c:candidates) {
            if (freq[c]==0) nums.push_back(c);
            freq[c]++;
        }

        vector<int> trajectory;
        combinationSum(0, nums.size()-1, target, trajectory);
        return ans;
    }

    void combinationSum(int start, int end, int target, vector<int>& trajectory)
    {
        if (target==0) {
            ans.push_back(trajectory);
            return;
        }
        if (target<0||start>end) return;

        for (int i=start; i<=end; ++i) {
            if (freq[nums[i]]<=0) continue;
            trajectory.push_back(nums[i]);
            freq[nums[i]]--;
            combinationSum(i, end, target-nums[i], trajectory);
            trajectory.pop_back();
            freq[nums[i]]++;
        }

    }
};

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> nums;
    // T:O(2^n), T(n)=2T(n-1)+O(1), S:O(2^n)
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        nums=candidates;

        vector<int> trajectory;
        combinationSum(0, nums.size()-1, target, trajectory);
        return ans;
    }

    void combinationSum(int start, int end, int target, vector<int>& trajectory)
    {
        if (target==0) {
            ans.push_back(trajectory);
            return;
        }
        if (target<0||start>end) return;

        for (int i=start; i<=end; ++i) {
            /************* duplica checking *************/
            if (i>start&&nums[i]==nums[i-1]) continue;
            /********************************************/
            trajectory.push_back(nums[i]);
            combinationSum(i+1, end, target-nums[i], trajectory);
            trajectory.pop_back();
        }

    }
};
