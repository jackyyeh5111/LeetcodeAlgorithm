/*
     1 2 3 4 5 6 7 8 9
      6 8 7 9
     1 2 3 4 56
*/
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck)
    {
        int n=deck.size(),j=0;
        vector<int> ans(n,0);
        sort(deck.begin(),deck.end());
        for (int i=0; i<n-1; ++i) {
            ans[j]=deck[i];
            int c=0;
            while(!(c==1&&ans[j]==0)) {c+=(ans[j]==0); j=(j+1)%n;}
        }
        for (int i=0; i<n; ++i) {
            if (ans[i]==0) {
                ans[i]=deck.back();
                break;
            }
        }
        return ans;
    }
};
