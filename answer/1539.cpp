/*
    Possible range: n ~ n+k
    1 2, k=2
    3 4

    3 4, k=2
    1 2

    2 3, k=2
    1 4
    We expect the max missing value is k at first.
    iterate over all nums, if theres some number smaller than k, it means the number is not the missing one, then increase k.
    T:O(n)/S:O(1)
    -----
    Binary Search
    [1,4,5,7,8,9] , k=2
    arr[idx]-idx-1 indicates the # of missing numbers.
    binary search on it.
    T:O(logn)/S:O(1)
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        int l=0,r=arr.size();
        while (l<r) {
            int mid=(l+r)/2;
            if (arr[mid]-mid-1<k) l=mid+1;
            else r=mid;
        }
        return l+k;
    }
};

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        for (int num:arr) {
            if (num>k) break;
            else k++;
        }
        return k;
    }
};
