// TLE
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships)
    {
        vector<unordered_set<int>> languages_set;
        for (auto l:languages) {
            unordered_set<int> s(l.begin(),l.end());
            languages_set.push_back(s);
        }
        int k=friendships.size(), ans=k;
        vector<bool> need2learn(k,1);
        for (int i=0; i<k; ++i) {
            int u=friendships[i][0]-1;
            int v=friendships[i][1]-1;
            for (int t=0; t<n; ++t) {
                if (languages_set[u].count(t+1)!=0&&languages_set[v].count(t+1)!=0) {
                    need2learn[i]=false;
                    break;
                }
            }
        }
        for (int i=0; i<n; ++i) {
            unordered_set<int> ppl;
            for (int j=0; j<k; ++j) {
                if (!need2learn[j]) continue;
                auto u=languages_set[friendships[j][0]-1];
                auto v=languages_set[friendships[j][1]-1];
                if (u.count(i+1)==0) ppl.insert(friendships[j][0]-1);
                if (v.count(i+1)==0) ppl.insert(friendships[j][1]-1);
                if (ppl.size()>=ans) break;
            }
            ans=min(ans,(int)ppl.size());
        }
        return ans;
    }
};
