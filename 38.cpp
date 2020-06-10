// Bad description
class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        else if (n==2) return "11";

        string last = countAndSay(n-1);
        string ans="";
        char tmp = last[0];
        int count = 1;
        for (int i=1; i<last.length(); ++i) {
            if (tmp==last[i]) count++;
            else {
                ans+=to_string(count)+string(1,tmp);
                count = 1;
                tmp=last[i];
            }
        }
        ans+=to_string(count)+string(1,tmp);
        return ans;
    }
};

// Another approach with moving comparison
string countAndSay(int n) {
    if (n == 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}
