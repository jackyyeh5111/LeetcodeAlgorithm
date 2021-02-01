/***** Third Visit *****/
/*
    linear probing
    T:O(n)/S:O(1)
    -----
    T:O(logn) -> binary search
    Basically we just need to go to the larger side, then we'll find in the end.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int n=nums.size(), l=0, r=n;
        while (l<r) {
            int mid=(l+r)/2;
            if ((mid==n-1||nums[mid]>nums[mid+1])&&
                (mid==0||nums[mid]>nums[mid-1])) return mid;
            else if (nums[mid]>nums[mid-1]) l=mid+1;
            else r=mid;
        }
        return l;
    }
};

/***** Second Visit *****/
/*
    constraint: T:O(logn)
    T(n)=2T(n/2)+O(1) -> T:O(n)
        = T(n/2)+O(1) -> T:O(logn)
    -> Considering binary search
    -----
    1 2 3 4
    1 2 4 3
    1 4 2 3
    4 1 2 3
    By example, there must be at least one peak
    -----
    KEY is to find the local max
    Conditions:
     1. array length is 1  -> return the only index
     2. array length is 2  -> return the bigger number's index
     3. array length is bigger than 2 ->
           (1) find mid, compare it with its left and right neighbors
           (2) return mid if nums[mid] greater than both neighbors
           (3) take the right half array if nums[mid] smaller than right neighbor
           (4) otherwise, take the left half
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int l=0,r=nums.size()-1;
        while (l<r) {
            int mid=(l+r)/2;
            if (nums[mid]<nums[mid+1]) l=mid+1;
            else r=mid;
        }
        return l;
    }
};

/***** First Visit *****/
/********************* worst: T:O(logN) *********************/
class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        /*
            Reduce the problem to "Finding local max"

            We only take search range (l, r) if nums[l-1]<nums[l] and
            num[r]>num[r+1]. Note that initial search range (l,r) where l=0 and
            r=len(nums)-1 holds true. Then, each step we reduce the search
            range half making sure the boundary condition holds true. Note that
            the other half the condition does not hold true.

            Therefore, when it finally is reduced to a single number, it is the local maximum since the boundary condition for a single number is same as the condition for local maximum.
        */
        int l=0, r=nums.size()-1;
        while(l<r) {
            int mid=(l+r)/2;
            if (nums[mid]>nums[mid+1]) r=mid;
            else l=mid+1;
        }
        return l;
    }
};

/********************* worst: T:O(N) *********************/
class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        /*
            peak value: num large or equal than both its neighbors.
            constrain: T:O(logN)
            --------------
            To find peak value over each num, it would take T:O(n).
            Can we reduce to T:O(logN) via binary search?

            T(n)=2T(n/2)+O(1)

            1 2 1 3 5 6 4
                  ^

            1 1 1 1 1 3 1
                  ^
            we cannot guarantee if mid is not peak value, we should go left or right.
            --------------
            best case: O(logN), worst case: O(n)
            --------------
            by example, we can sure that there's must be at least one peak value.
        */
        nums.insert(nums.begin(),INT_MIN);
        nums.push_back(INT_MIN);
        int ans=help(nums,0,nums.size()-1);
        return ans>-1?ans-1:-1;
    }

    int help(vector<int> &nums, int l, int r)
    {
        if (l>r) return -1;
        // cout<<l<<","<<r<<endl;
        int mid=(l+r)/2;
        if (mid==0) return help(nums,mid+1,r);
        else if (mid==nums.size()-1) return help(nums,l,mid-1);

        if (nums[mid]>=nums[mid-1]&&nums[mid]>=nums[mid+1])
            return mid;
        else {
            int left=help(nums,l,mid-1);
            if (left==-1) return help(nums,mid+1,r);
            else return left;
        }
    }
};
