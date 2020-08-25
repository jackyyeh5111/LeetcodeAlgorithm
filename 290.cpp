/*
    use 2 hashmap to store word<->char
    T:O(len(str))/S:O(m+n)
    -------------
    use 1 hashmap to store the first appearance of both word/pattern.
    to separate word/pattern, add postfix "_" to the pattern.
    T:O(len(str))/S:O(# of word)
*/

/***** 1 hashmap *****/
class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<string,char> m;
        int i=0,j=0;
        while(j<str.length()) {
            string word="";
            while (j<str.length()&&str[j]!=' ') word+=str[j++];

            if (m.find(word)==m.end()) m[word]=i;
            if (m.find(pattern.substr(i,1)+"_")==m.end()) m[pattern.substr(i,1)+"_"]=i;
            if (m[word]!=m[pattern.substr(i,1)+"_"]) return false;

            j++; i++;
        }
        return i==pattern.size();
    }
};

/***** 2 hashmap *****/
class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<string,char> m;
        unordered_map<char,string> n;
        int i=0,j=0;
        while(j<str.length()) {
            string word="";
            while (j<str.length()&&str[j]!=' ') word+=str[j++];
            if (m.find(word)==m.end()) {
                if (n.find(pattern[i])==n.end()) {
                    m[word]=pattern[i]; n[pattern[i]]=word;
                }
                else return false;
            }
            else if (m[word]!=pattern[i]) return false;
            j++; i++;
        }
        return i==pattern.size();
    }
};
/*
"abba"
"dog cat cat dog"
"abba"
"dog cat cat fish"
"aaaa"
"dog cat cat dog"
"abba"
"dog dog dog dog"
*/
