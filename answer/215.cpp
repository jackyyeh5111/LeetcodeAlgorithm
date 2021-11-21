/***** Fifth Visit *****/

/***** Fourth Visit *****/
/*
    sort
    T:O(nlogn)/S:O(1)
    -----
    partition
    T:O(n^2)
    -----
    max heap
    T:O(n)/S:O(n)
*/
/*
    sorting then find kth largest num.
    T:O(nlogn)/S:O(1)
    -----
    partition
    T:O(n^2)/S:O(1)
    -----
    heap sort
    build heap: T:O(n)/S:O(k)
    find kth element: T:O(klogn)/S:O(1)
    [1,2,3,4,5,6] k=3
           ^ ^
*/
// max heap T:O(klogn)/S:O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,less<int>> pq(nums.begin(),nums.end());
        for (int i=0; i<k-1; ++i) 
            pq.pop();
        return pq.top();
    }
};

// partition T:O(n^2)/S:O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int pivot=nums[0];
        int l=1, r=nums.size()-1, n=nums.size();
        while (l<=r) {
            while (l<=r&&nums[l]<=pivot) l++;
            while (l<=r&&nums[r]>pivot) r--;
            if (l<=r) swap(nums[l++],nums[r--]);
        }
        swap(nums[0],nums[r]);
        if (r==n-k) return pivot;
        else if (n-r<k) {
            // left
            vector<int> left(nums.begin(),nums.begin()+r);
            return findKthLargest(left,k-n+r);
        }
        else {
            // right
            vector<int> right(nums.begin()+r+1,nums.end());
            return findKthLargest(right,k);
        }
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int> pq(nums.begin(),nums.end());
        for (int i=1; i<k; ++i) pq.pop();
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int n=nums.size();
        int pivot=nums[0];
        int l=1, r=n-1;
        while (l<=r) {
            while (l<=r&&nums[l]<=pivot) l++;
            while (l<=r&&nums[r]>pivot) r--;
            if (l<=r) swap(nums[l++],nums[r--]);
        }
        swap(nums[0],nums[r]);
        if (r==n-k) return pivot;
        else if (n-r<k) {
            vector<int> left(nums.begin(),nums.begin()+r);
            return findKthLargest(left,k-n+r);
        }
        else {
            vector<int> right(nums.begin()+r+1,nums.end());
            return findKthLargest(right,k);
        }
    }
};

/***** Third Visit *****/
/*
    quick sort partition
    T:O(n^2)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int pivot=nums[0];
        int l=1, r=nums.size()-1;
        while (l<=r) {
            while (l<=r&&nums[l]<=pivot) l++;
            while (l<=r&&nums[r]>pivot) r--;
            if (l<=r) swap(nums[l],nums[r]); // KEY: seap condition
        }
        swap(nums[0],nums[r]);
        int n=nums.size();
        if (n-r==k) return pivot;
        else if (n-r>k) {
            vector<int> t(nums.begin()+r+1,nums.end());
            return findKthLargest(t,k);
        }
        else {
            vector<int> t(nums.begin(),nums.begin()+r);
            return findKthLargest(t,k-n+r);
        }
    }
};

/***** Second Visit *****/
/*
    T(n)=T(n/2)+O(n) => O(n) in best case.
    T(n)=T(n-1)+O(n)=> O(n^2) in worst case.
    -----
    heap sort
    T:O(n) => best case
    T:O(nlogn) => worst case
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int pivot=nums[0];
        int l=0, r=nums.size()-1, n=nums.size();
        while (l<=r) {
            while(l<=r&&nums[l]<=pivot) l++;
            while(l<=r&&nums[r]>pivot) r--;
            if (l<=r) swap(nums[l++],nums[r--]);
        }
        swap(nums[r],nums[0]);
        if (n-k==r) return nums[r];
        else if (n-k>r) {
            vector<int> tmp(nums.begin()+r+1,nums.end());
            return findKthLargest(tmp,k);
        }
        else {
            vector<int> tmp(nums.begin(),nums.begin()+r);
            return findKthLargest(tmp,k-n+r);
        }
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int> q;
        int n=nums.size();
        for (int num:nums) {
            q.push(num);
            if (q.size()>n-k+1) q.pop();
        }
        return q.top();
    }
};

/***** First Visit *****/
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
