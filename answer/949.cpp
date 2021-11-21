/*
    use a dictionary to store digits
    k:0-9, v: count.
    process for each digit.
    T:O(3*4*7*10)/S:O(10+4)
    ERROR
    -----
    use backtracking with recursive
    T:O(3*4*7*10)/S:O(10+4)
    -----
    Another solution is to enumerate all permutation, then check valid
    time or not. Sort the input time from larget to small first.
*/

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A)
    {
        vector<int> table(10);
        for (auto a:A) table[a]++;
        string ans="";
        if (getDigit(table,ans)) return ans.insert(2,":");
        else return "";
    }

    bool getDigit(vector<int> &table, string &s)
    {
        if (s.length()==4) return true;
        int x=9;
        if(s=="") x=2;
        else if (s=="2") x=3;
        else if (s.length()==2) x=5;
        // cout<<s<<","<<x<<endl;
        for(int i=x; i>=0; --i) {
            if (table[i]==0) continue;
            table[i]--;
            s+=to_string(i);
            if (getDigit(table,s)) return true;
            table[i]++;
            s=s.substr(0,s.length()-1);
        }
        return false;
    }
};
