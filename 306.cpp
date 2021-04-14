typedef long double ld;
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n=num.length();
        return dfs(num,0,n,-1,-1,-1);
    }


    bool dfs(string s, int idx, int n, ld prevprevprev, ld prevprev, ld prev)
    {
        if (idx==n&&prevprevprev!=-1) return true;
        else if (idx==n) return false;
        ld num=0;
        for (int i=idx; i<n; ++i) {
            if (s[idx]=='0'&&i>idx) return false;
            num=num*10+(s[i]-'0');
            if (prevprev==-1||prev==-1||num==prevprev+prev) {
                if (dfs(s,i+1,n,prevprev,prev,num))
                    return true;
            }
            else if (num>prevprev+prev) return false;
        }
        return false;
    }
};
