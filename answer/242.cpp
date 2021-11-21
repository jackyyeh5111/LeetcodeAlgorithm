/***** Third Visit *****/
/*
    If input contains unicode, it means we have unlimited range. Then change vector into map.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int cnt=s.length();
        vector<int> v(26,0);
        for (char c:s) v[c-'a']++;
        for (char c:t) {
            if (v[c-'a']<=0) return false;
            v[c-'a']--;
            cnt--;
        }
        return cnt==0;
    }
};

/***** Second Visit *****/
/*
    T:O(n)/S:O(n)
*/
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char,int> ss,ts;
        int ls=s.length(),lt=t.length();
        if (ls!=lt) return false;
        for (int i=0; i<ls; ++i) {
            ss[s[i]]++;
            ts[t[i]]++;
        }
        return ss==ts;
    }
};

/***** First Visit *****/
/*
    Problem statement says that there are only lower cases, so the hashtable
    could be replaced by char[256]
*/
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char,int>sm,tm;
        if (s.length()!=t.length()) return false;
        for (int i=0; i<s.length(); ++i) {
            sm[s[i]]++; tm[t[i]]++;
        }
        return sm==tm;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<string,int>sm,tm;
        int i=0;
        while(i<s.length()) {
            string str=""; str+=s[i++];
            if (str=="/") { // unicode length: 4
                while(i<s.length()&&s[i]!='/')
                    str += s[i++];
            }
            sm[str]++;
        }
        int j=0;
        while(j<t.length()) {
            string str=""; str+=t[j++];
            if (str=="/") { // unicode length: 4
                while(j<t.length()&&t[j]!='/')
                    str += t[j++];
            }
            tm[str]++;
        }
        return sm==tm;
    }
};
