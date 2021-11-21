/*
    [4,1,5,20,3]
    1 3 1 5 5
    1 1 3 5 5
    1 3 5

    find the odd of each number.See if we can enlarge current min by times 2.
    -----
    2 8 10
    1 5
    -----
    [4,9,4,5]
     1 1 5 9
    -----
    To minimize range, we can enlarge current min or decrease current max.
    First, multiply all odd num by 2. This means we have largest current min.
    Next goal is to minimize current max.

    Conduct a max heap for all even number, minimize each top num(current max) and push back num/2, update current min meanwhile. If the top num is odd, it means that we cannot decrease current max anymore.

    Intuition 1: we can divide even numbers multiple times - till we get an odd number, but we can only double odd numbers once. After that, it will become an even number.

    Intuition 2: Even numbers never increase.

    refers: https://leetcode.com/problems/minimize-deviation-in-array/discuss/955262/C%2B%2B-intuitions-and-flip
    
    T:O(nlogn)/S:O(n)
*/
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int,vector<int>,less<int>> pq;
        int cmin=INT_MAX;
        for (int num:nums) {
            if (num%2==0) {pq.push(num); cmin=min(cmin,num);}
            else {pq.push(num*2); cmin=min(cmin,num*2);}
        }
        int ans=pq.top()-cmin;
        while (pq.top()%2==0) {
            int t=pq.top(); pq.pop();
            pq.push(t/2);
            cmin=min(cmin,t/2);
            ans=min(ans,pq.top()-cmin);
        }
        return ans;
    }
};
