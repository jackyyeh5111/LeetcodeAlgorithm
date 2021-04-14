class Solution {
public:
    int arraySign(vector<int>& nums)
    {
        // 1 positive, -1 negative, 0 zero
        int sign=1;
        for (int num:nums) {
            if (num>0) continue;
            else if (num==0) {sign=0; break;}
            else sign*=-1;
        }
        return sign;
    }
};
