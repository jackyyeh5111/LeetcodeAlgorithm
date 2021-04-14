/*
    Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

    n = 3, k = 1
    [1, 2, 3]
    -----
    n = 3, k = 2
    [1, 3, 2]
    -----
    First, lets figuure out how many possible k we can make if n==4
    1234 k=1
    1243 k=2
    1324 k=2
    1342 k=2
    1423 k=3
    1432 k=2
    -----
    brute force: dfs T:O(n!)/S:O(n) by backtracking -> TLE
    Lets figure out mathematical approach
    -----
    n==5,k==4
    15243 -> diff: 4321
    n==5,k==3
    15234 -> diff: 4311
    n==5,k==2
    15432 -> diff: 4111
    n==5,k==1
    12345 -> diff: 1111
    -----
    n==10,k==8
    1 10 2 9 3 8 4 7 6 5 -> diff: 987654311

    greedy 1 pass T:O(n)/S:O(n) includes return space
*/
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans={1};
        int i=0;
        for (i=0; i<k-1; ++i) {
            if (i%2==0) ans.push_back(ans.back()+n-i-1);
            else ans.push_back(ans.back()-n+i+1);
        }
        while (ans.size()!=n) {
            if (i%2==0) ans.push_back(ans.back()+1);
            else ans.push_back(ans.back()-1);
        }
        return ans;
    }
};
