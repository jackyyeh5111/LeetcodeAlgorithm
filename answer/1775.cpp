/*
    [1,2,3,4,5,6] => 21
     ^         ^
    [1,1,2,2,2,2] => 10
     ^         ^
    21-5-4-2
*/
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2)
    {
        int sum1=accumulate(nums1.begin(),nums1.end(),0);
        int sum2=accumulate(nums2.begin(),nums2.end(),0);
        if (sum1==sum2) return 0;
        else if (sum1>sum2) {swap(sum1,sum2); swap(nums1,nums2);}
        int diff=sum2-sum1,ans=0;
        priority_queue<int> pq;
        for (int x:nums1) pq.push(6-x);
        for (int x:nums2) pq.push(x-1);
        while (!pq.empty()) {
            diff -= min(diff,pq.top()); pq.pop();
            ans++;
            if (diff==0) return ans;
        }
        return -1;
    }
};
