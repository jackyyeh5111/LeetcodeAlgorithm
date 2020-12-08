/***** Second Visit *****/
class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char,char> m;
        for (int i=0; i<s.length(); ++i){
            if (m.count(s[i])!=0&&m[s[i]]!=t[i]) return false;
            m[s[i]]=t[i];
        }
        swap(s,t);  m.clear();
        for (int i=0; i<s.length(); ++i){
            if (m.count(s[i])!=0&&m[s[i]]!=t[i]) return false;
            m[s[i]]=t[i];
        }
        return true;
    }
};

/***** First Visit *****/
class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char,char> m;
        for (int i=0; i<s.length(); ++i) {
            if (m.find(s[i])==m.end()) m[s[i]]=t[i];
            else if (m[s[i]]!=t[i]) return false;
        }
        swap(s,t); m.clear();
        for (int i=0; i<s.length(); ++i) {
            if (m.find(s[i])==m.end()) m[s[i]]=t[i];
            else if (m[s[i]]!=t[i]) return false;
        }
        return true;
    }
};
