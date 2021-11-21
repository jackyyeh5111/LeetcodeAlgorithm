/*
    Directly apply 3 sum without duplicate checking.
    T:O(n^2)/S:O(1)
    -----
    try with some pruning
    [1,1,2,2,3,3,4,4,5,5], target=8
    [1,2,3,4,5], target=8
    [2,2,2,2,2]
     ^   ^   ^ 8+8
       ^
       ^   ^

     T:O(k^2+nlogn+n)/S:O(1)
*/
class Solution {
public:
    int mod=1e9+7;
    int threeSumMulti(vector<int>& arr, int target)
    {
        sort(arr.begin(),arr.end());
        vector<pair<int,int>> nums;
        for (int &a:arr) {
            if (nums.empty()||nums.back().first!=a)
                nums.push_back({a,1});
            else if (nums.back().first==a) nums.back().second+=1;
        }
        int n=nums.size(),ans=0;
        for (int i=0; i<n; ++i) {
            int j=i, k=n-1;
            while (j<=k){
                if (nums[i].first+nums[j].first+nums[k].first==target) {
                    long p=nums[i].second--, q=nums[j].second--, r=nums[k].second--;
                    if (p>0&&q>0&&r>0) {
                        if (nums[i]==nums[j]&&nums[j]==nums[k])
                            ans=(ans+(p*q*r/6)%mod)%mod;
                        else if (nums[i]==nums[j]||nums[i]==nums[k]||nums[j]==nums[k])
                            ans=(ans+(p*q*r/2)%mod)%mod;
                        else ans=(ans+p*q*r)%mod;
                    }
                    p=nums[i].second++; q=nums[j].second++; r=nums[k].second++;
                    j++; k--;
                }
                else if (nums[i].first+nums[j].first+nums[k].first>target) k--;
                else j++;
            }
        }
        return ans;
    }
};
