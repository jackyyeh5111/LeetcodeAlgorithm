class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans=0;
        for (int num:nums) {
            if (m.count(k-num)!=0&&m[k-num]>0) {m[k-num]--; ans++;}
            else m[num]++;
        }
        return ans;
    }
};