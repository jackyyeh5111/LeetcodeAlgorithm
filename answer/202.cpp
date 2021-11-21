/***** Second Visit *****/
class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<int> s;
        while (true) {
            int tmp=0;
            while (n) {tmp+=pow(n%10,2); n/=10;}
            if (s.count(tmp)) return false;
            else if (tmp==1) return true;
            s.insert(tmp);
            n=tmp;
        }
        return -1;
    }
};

/***** First Visit *****/
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
