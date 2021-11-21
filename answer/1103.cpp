/*
    90, 4
    1  2  3  4
    5  6  7  8
    9  10 11 12
    12
    ------------
    27 18 21 24

    10 3
    1 2 3
    4 5 6
    7 8 9

    n(n+1)<=2m
    Use binary search to find n, then do math calculation.
    T:O(logn)+O(n)/S:O(1)
*/
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        int l=0, r=candies;
        while(l<r) {
            int mid=(l+r)/2;
            if ((long)mid*(long)(mid+1)>(long)2*(long)candies) r=mid; // may overflow !!
            else l=mid+1;
        }
        // cout<<l-1<<endl;
        vector<int> ans(num_people,0);
        int d=(l-1)/num_people;
        int re=(l-1)%num_people;
        for (int i=0; i<num_people; ++i) {
            int depth=d+((i+1)<=re);
            ans[i]+=(i+1+(i+1+num_people*(depth-1)))*depth/2;
        }
        ans[re]+=candies-l*(l-1)/2;

        return ans;
    }
};
