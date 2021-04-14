/*
    binary searcch T:O(mlogn)
    build heap T:O(m)
    return ans T:O(klogm)
*/
typedef pair<int,int> pi;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        vector<pair<int,int>> v; // # of soldier, row idx
        for (int i=0; i<mat.size(); ++i) {
            vector<int> &row=mat[i];
            int l=0, r=row.size();
            while (l<r) {
                int mid=l+(r-l)/2;
                if (row[mid]==1) l=mid+1;
                else r=mid;
            }
            v.push_back({l,i});
        }
        priority_queue<pi,vector<pi>,greater<pi>> pq(v.begin(),v.end());
        vector<int> ans;
        for (int i=1; i<=k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
