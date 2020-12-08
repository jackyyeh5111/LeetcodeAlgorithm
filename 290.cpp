/***** Third Visit *****/
/*
    a   b   b   a
    dog cat cat dog
    If we use only char->word map checking, i.e. a->dog, we will fail to check d->dog
    Thus we need to maintain bi-directional checking with 2 mapping
    T:O(n)/S:O(n)
*/
class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char,string> m;
        unordered_map<string,char> invm;
        int n=s.length(), i=0;
        for (char c:pattern) {
            string sub="";
            while (i<n&&s[i]!=' ') sub+=s[i++];
            i++;
            if (m.count(c)==0&&invm.count(sub)==0) {
                m[c]=sub;
                invm[sub]=c;
            }
            else if (m[c]!=sub||invm[sub]!=c) return false;
        }
        return i==n+1;
    }
};

/***** Second Visit *****/
/*
    String:
    1. TRIE
    2. KMP
    3. treat it as array
        1. 2 ptr
        2. moving window (V)

    use a hash table with k:string, v:char
    if exist in table, check the letter is the same or not
    else insert into map
*/
class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<string,char> m;
        unordered_map<char,string> m_i;
        int a=0, b=0, sizea=pattern.length(), sizeb=str.length();
        while(a<sizea&&b<sizeb) {
            string word="";
            while(b<sizeb&&str[b]!=' ') word+=str[b++];
            if (m.count(word)==0&&m_i.count(pattern[a])==0) {
                m[word]=pattern[a];
                m_i[pattern[a]]=word;
            }
            if (m[word]==pattern[a]&&m_i[pattern[a]]==word) {a++; b++;}
            else return false;
        }
        return a==pattern.length()&&b==str.length()+1;
    }
};

/***** First Visit *****/
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
