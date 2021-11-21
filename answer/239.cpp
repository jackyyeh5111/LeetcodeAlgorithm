/***** Fourth Visit *****/
/*
    Utilize deque with decreasing order.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            while(!dq.empty()&&nums[i]>dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
            if (i>=k&&dq.front()==nums[i-k]) dq.pop_front();
            if (i>=k-1)ans.push_back(dq.front());
        }
        return ans;
    }
};

/***** Third Visit *****/
/*
    brute force:
    maintain a moving window with priority queue.
    pop out the current max. while window size is larger than k.
    T:O(nlogk)/S:O(k)
    -----
    Maintain a deque with decreasing num in terms of index.
    the front one is current max, pop out while front is equal to i-k, which means size is running out.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            while(!dq.empty()&&nums[dq.back()]<=nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (dq.front()==i-k)
                dq.pop_front();
            if (i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

/***** Second Visit *****/
/*
    Find largest num in each sliding window with size k.
    Constraints:
        1 <= nums.length <= 105
        -104 <= nums[i] <= 104
        1 <= k <= nums.length
    -----
    brute force:
    > T:O(nk)/S:O(1)
    -----
    Use priority queue?
        insert: O(logn)
        delete specific: O(n)
    -----
    Use multi set (AVL tree)
        insert: O(logn)
        delete specific: O(logn)
    > T:O(nlogn)/S:O(n)
    -----
    Is there any other O(n) solution?
    Use deque to record each decreasing order num in terms of index.
       1 3 -1 -3 -5 6, k=6
    q: 0
       1
       1 2
       1 2 3
       1 2 3 4
       5
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); ++i) {
            if  (dq.front()==i-k) dq.pop_front();
            while  (!dq.empty()&&nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        multiset<int> s;
        int i=0,j=0,n=nums.size();
        vector<int> ans;
        while (j<n) {
            s.insert(nums[j++]);
            if (s.size()>k) s.erase(s.find(nums[i++]));
            if (s.size()==k) ans.push_back(*s.rbegin());
        }
        return ans;
    }
};

/***** First Visit *****/
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
