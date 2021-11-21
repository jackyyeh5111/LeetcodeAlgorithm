class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        unordered_map<int,int> m;
	    int ans=0;
        for(int num:nums){
            m[num]++;
            if(m[num]<2) continue;
            if(m[num]==2) ans++;
            else{
                int tmp=(m[num]-1)*(m[num]-2)/2;
                ans += ((m[num]*(m[num]-1))/2-tmp);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        /*
            1 3 6 10 15
           ^ ^ ^ ^  ^
           1 2 3 4  5
        */
        int res = 0;
        unordered_map<int, int> count;
        for (int a: A) {
            res += count[a]++;
        }
        return res;
    }
};
