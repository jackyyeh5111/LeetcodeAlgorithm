class Solution {
public:
    int totalMoney(int n) 
    {
        int weeks=n/7;
        int ans=0;
        ans+=28*weeks+(weeks>1?weeks*(weeks-1)*7/2:0);
        n-=7*weeks;
        for (int i=0; i<n; ++i) ans+=(++weeks);
        return ans;
    }
};