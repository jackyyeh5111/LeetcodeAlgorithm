/***** Second Visit *****/
class Solution {
public:
    string countAndSay(int n)
    {
        static vector<string> v(30,"");
        if (v[n-1]!="") return v[n-1];
        v[0]="1";
        for (int i=1; i<n; ++i) {
            string prev=v[i-1];
            string s="";
            char c=prev[0]; int count=1;
            for (int j=1; j<prev.length(); ++j) {
                if (prev[j]==c) count++;
                else {
                    s+=to_string(count)+string(1,c);
                    if(j<prev.length()) {c=prev[j]; count=1;}
                }
            }
            if (count) s+=to_string(count)+string(1,c);
            v[i]=s;
        }
        return v[n-1];
    }
};

/***** First Visit *****/
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
