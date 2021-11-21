/***** Second Visit *****/
/*
    brute force: sort and find max difference
    T:O(nlogn)/S:O(1)
    -----
    constraint: T:O(n)/S:O(n) -> bucket sort.
    (largest-smallest) / number of gaps could gain min gap.
    The rest possible larger gap would be the difference between max num of current bucket and min num of next bucket.
*/
class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        int n=nums.size();
        if (n<2) return 0;
        auto lu=minmax_element(nums.begin(),nums.end());
        int gap=max((*lu.second-*lu.first)/(n-1),1);
        int m=(*lu.second-*lu.first)/gap+1;
        vector<int> minBucket(m,INT_MAX);
        vector<int> maxBucket(m,INT_MIN);
        for (int num:nums) {
            int k=(num-*lu.first)/gap;
            minBucket[k]=min(minBucket[k],num);
            maxBucket[k]=max(maxBucket[k],num);
        }
        int i=0;
        gap=(*lu.second-*lu.first)/(n-1);
        while (i<m) {
            int j=i+1;
            while (j<m&&minBucket[j]==INT_MAX) j++;
            if (j==m) break;
            gap=max(gap,minBucket[j]-maxBucket[i]);
            i=j;
        }
        return gap;
    }
};

/***** First Visit *****/
/*
Suppose all the n elements in nums fall within [l, u], the maximum gap will not
be smaller than gap = (u - l) / (n - 1). However, this gap may become 0 and so
we take the maximum of it with 1 to guarantee that the gap used to create the
buckets is meaningful.

Then there will be at most m = (u - l) / gap + 1 buckets. For each number num,
it will fall in the k = (num - l) / gap bucket. After putting all elements of
nums in the corresponding buckets, we can just scan the buckets to compute the
maximum gap.

The maximum gap is only dependent on the maximum number of the current bucket
and the minimum number of the next neighboring bucket (the bucket should not be
empty). So we only store the minimum and the maximum of each bucket. Each
bucket is initialized as {minimum = INT_MAX, maximum = INT_MIN} and then
updated while updating the buckets.

*/
class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        /*
            constrain: T:O(n), S:O(n)
            3 6 9 1
              ^
            --------------------
            Radix Sort (distributive sorts)
            Refers to: https://leetcode.com/problems/maximum-gap/discuss/50694/12ms-C%2B%2B-Suggested-Solution

            3 6 9 1
            gap=(9-1)/3=2
            m=(9-1)/2+1=5
            [0-1] 0: 1
            [2-3] 1: 3
            [4-5] 2:
            [6-7] 3: 6
            [8-9] 4: 9
        */
        int size=nums.size();
        if (size<2) return 0;
        auto lu=minmax_element(nums.begin(),nums.end());
        int l=*(lu.first); int u=*(lu.second);
        int gap=max((u-l)/(size-1),1);
        int m=(u-l)/gap+1;
        vector<int> minBucket(m,INT_MAX);
        vector<int> maxBucket(m,INT_MIN);

        for (int num:nums){
            int k=(num-l)/gap;
            minBucket[k]=min(minBucket[k],num);
            maxBucket[k]=max(maxBucket[k],num);
        }

        int i=0;
        gap=(u-l)/(size-1);
        // gap=maxBucket[0]-minBucket[0];
        while(i<m) {
            int j=i+1;
            while(j<m && minBucket[j]==INT_MAX && maxBucket[j]==INT_MIN) j++;
            if (j==m) break;
            gap = max(gap,minBucket[j]-maxBucket[i]);
            i=j;
        }
        return gap;
    }
};
