class Solution {
public:
    int countBalls(int lowLimit, int highLimit)
    {
        unordered_map<int,int> mp;
        int ans=0;
        for (int i=lowLimit; i<=highLimit; ++i) {
            int t=i, num=0;
            while (t>0) {
                num+=t%10;
                t/=10;
            }
            mp[num]++;
            ans=max(ans,mp[num]);
        }
        return ans;
    }
};
