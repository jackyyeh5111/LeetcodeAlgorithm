/*
    Return the minimum number of operations needed to make all the elements of arr equal.
    arr[i] = (2 * i) + 1
    each op: arr[x]-=1 arr[y]+=1
    -----
    greedy approach
    -----
     2
    [1, 3, 5], n=3
    [2,3,4]
    [3,3,3]
    -----
     3 1
    [1,3,5,7]
    [2,3,5,6]
    [3,3,5,5]
    [4,3,5,4]
    [4,4,4,4]
    -----
    [1,3,5]
     ^   ^ <--- dist: 1
    [1,3,5,7,9]
     ^       ^ <--- dist: 2 <-- 4
    odd: dist*2
    -----
    [1,3] dist <--(0+1)*2

         4 2
    odd [1,3,5,7,9]
         3 1
    even[1,3,5,7]
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int minOperations(int n)
    {
        int ans=0;
        for (int i=0; i<n/2; ++i)
            ans+=(n/2-i)*2-(n%2==0);

        return ans;
    }
};
