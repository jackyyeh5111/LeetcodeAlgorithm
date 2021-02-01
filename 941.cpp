/*
    2 ptr checking
    T:O(n)/S:O(1)
    -----
    Could we apply binary checking?
    No, we need to check if the array is strict increasing/decreasing
    Thus we have to iterate over all nums.
*/
class Solution {
public:
    bool validMountainArray(vector<int>& arr)
    {
        int n=arr.size(), l=0, r=n-1;
        if (n<3) return false;
        while (l<r&&arr[l+1]>arr[l]) l++;
        while (l<r&&arr[r-1]>arr[r]) r--;
        return r==l&&l!=0&&r!=n-1;
    }
};
