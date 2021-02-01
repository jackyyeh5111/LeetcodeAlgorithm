/*
    Brute force:
    Enumerate all possible triplets and find if feasible.
    T:O(n^3)/S:O(1)
    -----
    left/right stack checking?
    T:O(n)/S:O(n)
    Actually the stack size will have at most 3 entry, thus it is S:O(1)
    -----
    If we dont like to use stack, parameterize it!!
    T:O(n)/S:O(1)
    -----
    It does [1,2,0,3] very well. And I realize that c1 and c2 are indeed having the meaning of:

    C1 = so far best candidate of end element of a one-cell subsequence to form a triplet subsequence

    C2 = so far best candidate of end element of a two-cell subsequence to form a triplet subsequence
    T:O(n)/S:O(1)

    Nota that this solution comes from BIS with knowing how many increasing nums should we care.
*/

// DP  problem
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1=INT_MAX,c2=INT_MAX;
        for (int num:nums) {
            if (num<=c1) c1=num;
            else if (num<=c2) c2=num;
            else return true;
        }
        return false;
    }
};

// Use stack, fail if we are asked to find 4 pair.
// [1,0,2,6,3,0,4]
// [1,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,3]
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        stack<int> left, right;
        int n=nums.size();
        for (int i=0; i<n; ++i) {
            while(!left.empty()&&nums[left.top()]>=nums[i]) left.pop();
            left.push(i);
            while(!right.empty()&&nums[right.top()]<=nums[n-i-1]) right.pop();
            right.push(n-i-1);
            if (left.size()>=3||right.size()>=3) return true;
        }
        return left.size()>=3||right.size()>=3;
    }
};

// parameterize stack
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> left(3,-1);
        vector<int> right(3,-1);
        int l=-1,r=-1;
        int n=nums.size();
        for (int i=0; i<n; ++i) {
            while (l>=0&&nums[left[l]]>=nums[i]) l--;
            left[++l]=i;
            while (r>=0&&nums[right[r]]<=nums[n-i-1]) r--;
            right[++r]=n-i-1;
            if (l==2||r==2) return true;
        }
        return l==2||r==2;
    }
};
