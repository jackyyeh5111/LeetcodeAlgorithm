class Solution {
public:
    string largestNumber(vector<int>& nums) {
        /*
            Basically this could be solved by sorting nums in MSD order.
            ex.
            3 30 34 5 9
            9 5 34 30 3 FAIL
            ------------------
            Brute force would be try out all permutation, which is T:O(N!)
            ------------------
            32 323 -> 32323 v.s. (32332)
            32 322 -> (32322) v.s. 32232
            12 121 -> (12121) v.s. 12112
            12 122 -> 12122 v.s. (12212)
            23 232 -> (23232) v.s. 23223
            23 233 -> 23233 v.s. (23323)
            thought: pad the first digit
        */
        sort(nums.begin(),nums.end(),[](int a, int b){
            string sa=to_string(a);
            string sb=to_string(b);
            return sa+sb>sb+sa;
        });
        string ans="";
        for (int num:nums)
            ans+=to_string(num);
        return ans[0]=='0'?"0":ans;
    }
};
