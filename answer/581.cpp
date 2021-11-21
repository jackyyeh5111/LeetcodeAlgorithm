/*
    [2,6,4,1,10,9,15]
     0 1 2 3 4  5 6

     2 6 4 -> 2 4
     2 4 1 -> 1

     [1,2,4,3]

     bidirection mono stack
     T:O(n)/S:O(n)
     -----
     We can reduce stack by 2 ptr, which are the left/right endian we'd like to sort
     T:O(n)/S:O(1)
*/

// stack solution T:O(n)/S:O(n)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> left,right;
        int l=INT_MAX,r=INT_MIN, n=nums.size();
        for (int i=0; i<n; ++i) {
            while(!left.empty()&&nums[left.top()]>nums[i]){
                l=min(l,left.top()); left.pop();
            }
            while(!right.empty()&&nums[right.top()]<nums[n-i-1]){
                r=max(r,right.top()); right.pop();
            }
            left.push(i); right.push(n-i-1);
        }
        return l==INT_MAX?0:r-l+1;
    }
};

// 2 ptr solution T:O(n)/S:O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l=INT_MAX,r=INT_MIN, n=nums.size();
        for (int i=0; i<n; ++i) {
            if (i>0&&nums[i]<nums[i-1]) {
                l=min(l,i);
                while(l>0&&nums[l-1]>nums[i]) l--;
            }
            if (i>0&&nums[n-i-1]>nums[n-i]) {
                r=max(r,n-i-1);
                while(r<n-1&&nums[r+1]<nums[n-i-1]) r++;
            }
        }
        return l==INT_MAX?0:r-l+1;
    }
};
