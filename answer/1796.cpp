class Solution {
public:
    int secondHighest(string s) {
        int cfirst=-1,csecond=-1;
        for (char &c:s) {
            if (!isdigit(c)) continue;
            int num=c-'0';
            if (num>cfirst) {csecond=cfirst; cfirst=num;}
            else if (num>csecond&&num!=cfirst) csecond=num;
        }
        return csecond;
    }
};
