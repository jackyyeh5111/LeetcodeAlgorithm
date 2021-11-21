/*
    Findn out all the index of 1.
    The first and last period dont need to be divided, else divide by 2.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats)
    {
        int ans=0, n=seats.size(), i=0;
        while (i<n) {
            int j=i;
            while (j<n&&seats[j]!=1) j++;
            if (j<n&&seats[j]==1&&i>0&&seats[i-1]==1)
                ans=max((j-i+1)/2,ans);
            else ans=max(ans,j-i);
            i=j+1;
        }
        return ans;
    }
};
