/*
    Keep the condition:
    1. play the smallest tokens game to gain scores
    2. play the largeest tokens game to gain tokens
    T:O(nlogn)/S:O(1) with in-place sorting
*/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P)
    {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int l=0,r=n-1,s=0,ans=0;
        while(l<=r) {
            if (P<tokens[l]) {
                if (s<=0) break;
                s--;
                P+=tokens[r--];
            }
            else {
                P-=tokens[l++];
                s++;
                ans=max(ans,s);
            }
        }
        return ans;
    }
};
