/*
    [1,1,4,2,3] 5
     ^   ^
     
    [3,2,20,1,1,3] 10
     ^        ^
     3  5  25 26 27 30
     
     maintain right cumulative sum.
     w. vector & binary search T:O(nlogn) / S:O(n)
     w. hashmap T:O(1) / S:O(n)
     -----
     It is a twisted variation of Two Sum. The rolling sum always increases, 
     so we can use two pointers - both starting from one side - to find 
     portions of the array that sum to x.
*/
// T:O(n)/S:O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        unordered_map<int,int> right;
        int n=nums.size(),lsum=0,rsum=0,ans=INT_MAX;
        for (int i=0; i<n; ++i) {
            right[rsum]=n-i-1;
            rsum+=nums[n-i-1];
        }
        for (int i=0; i<n; ++i) {
            if (right.count(x-lsum)!=0) 
                ans=min(ans,n-right[x-lsum]+i-1);
            lsum+=nums[i];
        }
        return ans==INT_MAX?-1:ans;
    }
};

// T:O(n)/S:O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int ans=INT_MAX, l=0,r=0,csum=0,n=nums.size();
        for (int num:nums) csum+=num;
        while (l<=r) {
            if (csum>=x) {
                if (csum==x) ans=min(ans,l+n-r);
                if (r<n) csum-=nums[r++];
                else break;
            }
            else csum+=nums[l++];
        }
        return ans==INT_MAX?-1:ans;
    }
};