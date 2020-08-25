/************** heap sort **************/
/*
    T:O(n) for heap build up
    T:O(klogn) for top k
*/

/************** priority q **************/
/*
    partial sorting: T:O(nlogn)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        /*
            priority queue
        */
        priority_queue<int,vector<int>,greater<int>> q;
        for (int num:nums) {
            q.push(num);
            if (q.size()>k)
                q.pop();
        }
        return q.top();
    }
};

/************** partition **************/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        /*
            sort. T:O(nlogn), S:O(1) in-place sorting.
            ---
            T(n)=T(n/2)+O(n) worst case O(n^2)
            partition
            ---
            optima: T:O(n)

            321564
            123564
            323124556
            122334556
        */
        int pivot=nums[0];
        int l=1,r=nums.size()-1;
        // for (int c:nums) cout<<c;
        // cout<<endl;
        while(l<=r) {
            while(l<=r&&nums[l]<=pivot) l++;
            while(l<=r&&nums[r]>pivot) r--;
            // cout<<l<<","<<r<<","<<k<<endl;
            if (l<=r) swap(nums[l++],nums[r--]);
        }
        if (r>=0&&r<nums.size()) swap(nums[r],nums[0]);

        if (r==nums.size()-k) return pivot;
        else if(r>nums.size()-k) {
            vector<int> subvec(nums.begin(),nums.begin()+r);
            return findKthLargest(subvec,k-nums.size()+r);
        }
        else {
            vector<int> subvec(nums.begin()+r+1,nums.end());
            return findKthLargest(subvec,k);
        }
    }
};
