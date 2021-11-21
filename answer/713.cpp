/*
    10 5 2 6 ; 100
    -----
    2 ptr solution
    10,5,2,6
    ^
         ^  <--- 2 arrays are larger than k
       ^
           ^
    -----
    10 5 100 6 ; 100
    We find out the fail cases, then return total-fail, which seems like top down.
    T:O(n)/S:O(1)
    -----
    Another solution is to do it as accumated way.
    for window (5, 2), when 6 is introduced, it add 3 new subarray:
            (6)
         (2, 6)
      (5, 2, 6)
    utilize 2 ptr to find all window which satisfies product smaller than k,
    then accumalted like the way above.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        int n=nums.size(),l=0,r=0,fail=0;
        double total=(double)n*(double)(n+1)/2.0, acc=1;
        while(l<n&&r<n) {
            if (acc>=k) {
                acc/=nums[l++];
                r=max(r,l);
                acc=max(1.0,acc);
                fail+=(n-r+1);
            }
            else acc*=nums[r++];
        }
        while (acc>=k&&l<n) {fail+=1; acc/=nums[l++];}
        return total-fail;
    }
};

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        int n=nums.size(),l=0,ans=0,acc=1;

        for (int r=0; r<n; ++r) {
            acc*=nums[r];
            while(l<=r&&acc>=k) acc/=nums[l++];
            ans+=r-l+1;
        }
        return ans;
    }
};


/*
[4,2,3]
1
[1,8,3,4,5,7]
8
[1,2,3]
0
[10, 5, 2, 6]
100
[10, 5, 100, 6]
100
*/
