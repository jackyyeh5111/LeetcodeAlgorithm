/*
    Note: no duplicate start points
    1 pass: vector of pair: start point, index
    2 pass: sort the vector
    3 pass: for each interval, binary search in pair
    T:O(nlogn)/S:O(n)
    -----------
    Actually we can use map(AVL) with lower_bound for neat code.
*/
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals)
    {
        int n=intervals.size();
        vector<int> ans(n);
        vector<pair<int,int>> v;
        for (int i=0; i<n; ++i) {
            v.push_back(make_pair(intervals[i][0],i));
        }
        sort(v.begin(),v.end());
        for (int i=0; i<n; ++i) {
            vector<int> interval=intervals[i];
            int l=0,r=n;
            while (l<r) {
                int mid=(l+r)/2;
                if (v[mid].first==interval[1]) {
                    l=mid; break;
                }
                else if (v[mid].first>interval[1]) r=mid;
                else l=mid+1;
            }
            if (l==n) ans[i]=-1;
            else ans[i]=v[l].second;
        }
        return ans;
    }
};
