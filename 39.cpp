
/*
Good example that same time complexity but different time consuming.
In greedy search, it costs time for copy constructor.
Thus we apply backtracking, which can reduce mem copying.
Time: 120ms->12ms.
*/

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> nums;

    // T:O(2^n), T(n)=2T(n-1)+O(1), S:O(2^n)
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        nums = candidates;

        combinationSum(0, nums.size()-1, target, vector<int>{});
        return ans;
    }

    void combinationSum(int start, int end, int target, vector<int> trajectory)
    {
        if (target==0) {
            ans.push_back(trajectory);
            return;
        }
        if (target<0||start>end) return;

        combinationSum(start+1, end, target, trajectory);
        int duplicated = target/nums[start];
        for (int i=0; i<duplicated; ++i) {
            trajectory.push_back(nums[start]);
            combinationSum(start+1, end, target-nums[start], trajectory);
            target -= nums[start];
        }
    }
};


class Solution {
public:

    vector<vector<int>> ans;
    vector<int> nums;
    // T:O(2^n), T(n)=2T(n-1)+O(1), S:O(2^n)
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        nums = candidates;

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
            trajectory.push_back(nums[i]);
            combinationSum(i, end, target-nums[i], trajectory);
            trajectory.pop_back();
        }

    }
};
