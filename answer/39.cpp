/***** Third Visit *****/
/*
    comb sum with unlimited duplicated nums
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> comb;
        help(candidates,0,comb,target);
        return ans;
    }

    void help(vector<int>& candidates, int idx, vector<int> &comb, int target)
    {
        if (target==0) {ans.push_back(comb); return;}
        else if (idx>=candidates.size()||target<0) return;

        int k=abs(target/candidates[idx]);
        for (int i=1; i<=k; ++i) {
            comb.push_back(candidates[idx]);
            help(candidates, idx+1, comb, target-candidates[idx]*i);
        }
        for (int i=0; i<k; ++i) comb.pop_back();
        help(candidates, idx+1, comb, target);
    }
};

/***** Second Visit *****/
/*
    Find all combination and check sum==target
    T:O(2^n)/S:O(1)
    According to constraints, we dont need to worry about oberflow.
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> comb;
        int sum=0;
        help(candidates,0,comb,sum,target,ans);
        return ans;
    }

    void help(vector<int>& candidates, int i, vector<int>& comb,
              int& sum, int target, vector<vector<int>>& ans)
    {
        if (i==candidates.size()) return;
        help(candidates,i+1,comb,sum,target,ans);
        int time=target/candidates[i];
        int x=0;
        while(x<time) {
            x++;
            sum+=candidates[i];
            comb.push_back(candidates[i]);
            if (sum>target) break;
            else if (sum==target) {ans.push_back(comb); break;}
            else help(candidates,i+1,comb,sum,target,ans);
        }
        for (; x>0; --x){
            sum-=candidates[i];
            comb.pop_back();
        }
    }
};

/***** First Visit *****/
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
