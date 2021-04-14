typedef long long ll;
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal)
    {
        ll csum=0, ans=0,lgoal=goal,llimit=limit;
        for( int num:nums) csum+=num;
        if (csum<lgoal) {
            int k=(lgoal-csum)/llimit;
            ans+=k; csum+=k*llimit;
        }
        else if (csum>lgoal) {
            int k=(csum-lgoal)/llimit;
            ans+=k; csum+=k*-1*llimit;
        }
        while (csum!=lgoal) {
            if (csum<lgoal) csum+=min(llimit,lgoal-csum);
            else csum+=max(-1*llimit,lgoal-csum);
            ans++;
        }
        return ans;
    }
};
