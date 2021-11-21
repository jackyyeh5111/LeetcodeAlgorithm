/*
Using increasing numbers as codes like that is simple but has some disadvantages, which the below solution fixes:

- If I'm asked to encode the same long URL several times, it will get several entries. That wastes codes and memory.
- People can find out how many URLs have already been encoded. Not sure I want them to know.
- People might try to get special numbers by spamming me with repeated requests shortly before their desired number comes up.
- Only using digits means the codes can grow unnecessarily large. Only offers a million codes with length 6 (or smaller). Using six digits or lower or upper case letters would offer (10+26*2)6 = 56,800,235,584 codes with length 6.

refer: https://leetcode.com/problems/encode-and-decode-tinyurl/discuss/100268/Two-solutions-and-thoughts
*/

// base62 encode by random K nums
class Solution {
public:

    const string CODES = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int K=6;
    unordered_map<string,string> short2long;
    unordered_map<string,string> long2short;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long2short.count(longUrl)!=0) return long2short[longUrl];
        string shortUrl="";
        for (int i=0; i<6; ++i) {
            shortUrl+=CODES[rand()%62];
        }
        short2long[shortUrl]=longUrl;
        long2short[longUrl]=shortUrl;
        return "http://tinyurl.com/"+shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int idx=shortUrl.length()-1;
        while (shortUrl[idx]!='/') idx--;
        string key=shortUrl.substr(idx+1);
        if (shortUrl.length()!=25||short2long.count(key)==0) return "";
        else return short2long[key];
    }
};

// base62 encode by incremental num
class Solution {
public:

    const string CODES = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int toBase10 (string s)
    {
        int ret=0;
        int count=1;
        for (char &c:s) {
            ret+=CODES.find(c)*count;
            count*=62;
        }
        return ret;
    }

    string toBase62(int k)
    {
        string ret="";
        while (k) {
            ret+=CODES[k%62];
            k/=62;
        }
        reverse(ret.begin(),ret.end()); // as the right most is LSB.
        return ret;
    }
    int idx=0;
    unordered_map<string,string> db;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string ids=toBase62(idx++);
        string shortUrl="http://tinyurl.com/"+ids;
        db[ids]=longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int idx=shortUrl.length()-1;
        while (shortUrl[idx]!='/') idx--;
        string ids=shortUrl.substr(idx+1);
        return db[ids];
    }
};
