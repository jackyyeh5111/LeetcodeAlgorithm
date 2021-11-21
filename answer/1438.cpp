/*
	GOAL: keep tracking current min/max to check if feasible according to limit.
	      If not feasible, step lower bound index right.
    -----
    brute force:
    enumerate each pair (i,j) to find diff between current min/max
    T:O(n^2)/S:O(1)
    -----
    Use an AVL tree for online sorting.
    T:O(nlogk)/S:O(k)
    -----
	Try another approach for T:O(n)/S:O(n)
    2 ptr
    Use 2 deque to record index for
    current_max: index for descending order
    current_min: index for increasing order
    Reduce to problem: 239
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit)
    {
        int n=nums.size(), l=0, ans=0;
        deque<int> cm,cn;
        for (int i=0; i<n; ++i) {
            while (!cm.empty()&&nums[cm.back()]<nums[i]) cm.pop_back();
            cm.push_back(i);
            while (!cn.empty()&&nums[cn.back()]>nums[i]) cn.pop_back();
            cn.push_back(i);
            if (nums[cm.front()]-nums[cn.front()]<=limit)
                ans=max(ans,i-l+1);
            else {
                if (cm.front()==l) cm.pop_front();
                if (cn.front()==l) cn.pop_front();
                l++;
            }
        }
        return ans;
    }
};
