/*  Find local max in window

    brute force:
    for each winidow, find local max
    T:O((n-k+1)*k)=T:O(nk)/S:O(1)
    ----------
    Use an ordered_map to store values in window
        AVL tree: insert/remove/search T:O(logm)
    T:O(nlogk)/S:O(k)
    ----------
    Use a double ended queue
    This queue is used to save the INDEX of LARGER incoming num only,
    which means the num according to the index is increasing order.
    Greedy T:O(n)/S:O(k)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int n=nums.size();
        deque<int> q;
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            if (q.front()==i-k) q.pop_front();
            while(!q.empty() && nums[q.back()]<=nums[i])
                q.pop_back();
            q.push_back(i);
            if (i>=k-1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
