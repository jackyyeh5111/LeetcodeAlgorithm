/*
    Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

    binary search on the length of array and check if feasible
    T:O(logn * nlogn)/S:O(1)
    -----
    [4,2,7,6,9,14,12], bricks = 5, ladders = 1
    use a minheap for ladder usage, each time q.size()>ladders, pop out the minima bricks.
    Goal: let the ladder be used on larger bricks!
    T:O(nlogk)/S:O(k)
*/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=heights.size();
        for (int i=1; i<n; ++i) {
            if (heights[i]<=heights[i-1]) continue;
            pq.push(heights[i]-heights[i-1]);
            if (pq.size()>ladders) {
                int t=pq.top(); pq.pop();
                bricks-=t;
                if (bricks<0) return i-1;
            }
        }
        return n-1;
    }
};
