class Solution {
public:
    vector<int> shortestToChar(string s, char c)
    {
        int n=s.length();
        vector<int> ans(n,n);
        int right=-1,left=-1;
        for (int i=0; i<n; ++i) {
            if (s[i]==c) right=0;
            else if (right!=-1) right++;
            if (s[n-i-1]==c) left=0;
            else if (left!=-1) left++;
            if (right!=-1) ans[i]=min(ans[i],right);
            if (left!=-1) ans[n-i-1]=min(ans[n-i-1],left);
        }
        return ans;
    }
};
