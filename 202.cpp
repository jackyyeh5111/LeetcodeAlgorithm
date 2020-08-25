class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<int> s;
        while(n!=1&&s.find(n)==s.end()) {
            s.insert(n);
            int tmp=0;
            while(n) {
                tmp+=pow(n%10,2);
                n/=10;
            }
            n=tmp;
        }
        if (n==1) return true;
        else return false;
    }
};
