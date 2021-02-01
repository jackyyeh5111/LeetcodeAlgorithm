/*
    [7,4,5,3,8], queries = [[0,2,2],[4,2,4],c]
    7 -> 4 -> 5 -> 3 -> 8
    -----
    q: [0,2,2]
    3 ~ 6, t=0 3<7 and 6>0
    -----
    q: [4,2,4]
    3 ~ 12, t=19 3<27 but 12!>19
    -----
    q: [2,13,1000000000]
    14 ~ 14000000000, t=11 14<16 and 14000000000>11
*/
typedef long long ll;
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries)
    {
        int types=candiesCount.size();
        vector<ll> llCandiesCount={candiesCount[0]};
        for (int i=1; i<types; ++i) llCandiesCount.push_back(llCandiesCount.back()+candiesCount[i]);
        vector<bool> ans;
        for (auto q:queries) {
            ll l=q[1]+1, r=l*q[2];
            if (l<=llCandiesCount[q[0]]&&r>(q[0]>0?llCandiesCount[q[0]-1]:0))
                ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};
