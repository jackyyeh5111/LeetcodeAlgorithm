/*
    greedy approach
    constraints: 1 <= s.length <= 500, which means our ans is at least 1.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int maxPower(string s) {
        int i=0,n=s.length();
        int ans=1;
        while (i<n) {
            int k=1;
            while (i<n-1&&s[i+1]==s[i]) {i++; k++;}
            ans=max(ans,k);
            i++;
        }
        return ans;
    }
};
