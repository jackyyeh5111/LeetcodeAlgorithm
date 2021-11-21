/*
    [1,2,2,2,5,0]
     1 3 5 7 12 12
    Maintain a running sum and comduct binary search to find lower/upper bound.
    T:O(nlogn)
    -----
    2 ptr solution to check possiible i, j, k.
    first ptr: i
    second ptr: j, k
    Notice that j and k are only moving forward, thats why we can have linear 
        probing complexity.
    refers: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/discuss/999257/C%2B%2BJavaPython-O(n)-with-picture
    T:O(n)/S:O(1)
*/

// T:O(n)/S:O(1)
class Solution {
public:
    int waysToSplit(vector<int>& nums) 
    {
        int n=nums.size(), ans=0, j=0, k=0, mod=pow(10,9)+7;
        for (int i=1; i<n; ++i) 
            nums[i]+=nums[i-1];
        for (int i=0; i<n-2; ++i) {
            while (j<=i||(j<n-1&&nums[j]<nums[i]*2)) j++;
            while (k<j||(k<n-1&&nums[k]-nums[i]<=nums[n-1]-nums[k])) k++;
            ans=(ans+k-j)%mod;
        }
        return ans;
    }
};

// T:O(nlogn)/S:O(n)
class Solution {
public:
    int waysToSplit(vector<int>& nums) 
    {
        int n=nums.size(), csum=0, ans=0, mod=pow(10,9)+7;
        vector<int> csums;
        for (int num:nums) {
            csum+=num;
            csums.push_back(csum);
        }
        for (int i=0; i<n-2; ++i) {
            int l=i+1, r=n-2;
            while (l<=r) {
                int mid=l+(r-l)/2;
                if ((csums[mid]-csums[i]>=csums[i])&&(csums.back()-csums[mid]>=csums[mid]-csums[i]))
                    r=mid-1;
                else if (csums.back()-csums[mid]<csums[mid]-csums[i])
                    r=mid-1;
                else l=mid+1;
            }
            int lower=l;
            r=n-2;
            while (l<=r) {
                int mid=l+(r-l)/2;
                if ((csums[mid]-csums[i]>=csums[i])&&(csums.back()-csums[mid]>=csums[mid]-csums[i]))
                    l=mid+1;
                else r=mid-1;
            }
            ans=(ans+max(r-lower+1,0))%mod;
        }
        return ans;
    }
};