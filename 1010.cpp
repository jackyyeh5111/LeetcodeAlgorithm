/*
    [30,20,150,100,40]
    [30, 20, 30, 40, 40]
    30: 2
    20: 1
    40: 2

    Could sort help? yes
    Could bucket sort further help? yes
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int table[60]={0}; int ans=0;
        for (int t:time) table[t%60]++;
        for (int i=0; i<=30; ++i) {
            if (i==0||i==30) ans+=table[i]*(table[i]-1)/2;
            else ans+=table[i]*table[60-i];
        }
        return ans;
    }
};
