/***** Third Visit *****/
/*
    constraints: 1 <= nums.length <= 100
    This constraint implies that we dont need to worry about TLE with T:O(n^2)
    -----
    sort based approach
    T:O(nlogn)/S:O(1)
*/
class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        sort (nums.begin(),nums.end(),[](int a, int b){
            string sa=to_string(a),sb=to_string(b);
            return sa+sb>sb+sa;
        });
        string ans="";
        for(int num:nums) ans+=to_string(num);
        return ans[0]=='0'?"0":ans;
    }
};

/***** Second Visit *****/
/*
    permutation and find max
    T:O(n!)/S:O(n) might get TLE
    -----
    9 1 15
    9115
    9151
    sort then combine
    T:O(nlogn*k)/S:O(n)
*/
class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        sort(nums.begin(),nums.end(),[](int a, int b){
            string as=to_string(a)+to_string(b), bs=to_string(b)+to_string(a);
            int i=0,j=0,m=as.length(),n=bs.length();
            while(i<m&&j<n) {
                int digita,digitb;
                digita=as[i++]-'0'; digitb=bs[j++]-'0';
                if(digita!=digitb) return digita>digitb;
            }
            return false;
        });
        string ans="";
        for(int num:nums) ans+=to_string(num);
        if (ans.size()>0&&ans[0]=='0') return "0";
        else return ans;
    }
};
/*
    [10,2]
    [3,30,34,5,9]
    [5,0,23,32,1,15,51]
    [5500006,55]
    [54,544]
    [54,545]
    [54,535]
    []
    [0]
    [0,1]
*/

/***** First Visit *****/
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
