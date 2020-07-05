/************************ Back Tracking ***********************/
class Solution {
public:
    unordered_map<string,bool> cache;
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;

        vector<string> path;
        dfs(0, s, path, ret);

        return ret;
    }

    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) { ret.push_back(path); return; }
        for(int i = index; i < s.size(); ++i) {
            string sub=s.substr(index,i-index+1);
            if(check(sub)) {
                path.push_back(sub);
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }

    bool check(string& s)
    {
        if(cache.find(s)!=cache.end()) return cache[s];
        string t=s;
        reverse(t.begin(),t.end());
        bool isPalindrome=s==t;
        cache[s]=isPalindrome;
        return t==s;
    }
};

/************************* TLE *************************/
class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        /*
            brute force:
            enumerate all possible partition then check if Palindrome or not.
            aabc
                a
                aa,a a
                aab,a ab,aa b,a a b
                aabc,a abc,aa bc,a a bc,aab c,a ab c,aa b c, a a b c
            T:O(2^n)*O(check palindrom)
            -----------------------------------
            Think: abba is palindrom, then is abba+c a palindrom?
            a b c b a a
        */
        vector<vector<string>> ans,perms;
        unordered_map<string,bool> cache;
        if (s.length()>0) perms.push_back(vector<string>{s.substr(0,1)});
        for (int i=1; i<s.length(); ++i) {
            int size=perms.size();
            for (int j=0; j<size; ++j) {
                vector<string> perm=perms[j];
                perm.push_back(s.substr(i,1));
                perms.push_back(perm);
                perm.pop_back(); perm.back()+=s.substr(i,1);
                perms.push_back(perm);
            }
            perms.erase(perms.begin(),perms.begin()+size);
        }
        for (auto perm:perms){
            bool valid=true;
            for (string entry:perm) {
                bool isPalindrome;
                if(cache.find(entry)==cache.end()) {
                    isPalindrome=check(entry);
                    cache[entry]=isPalindrome;
                }
                else isPalindrome=cache[entry];
                if(!isPalindrome) {valid=false; break;}
            }
            if(valid) ans.push_back(perm);
        }
        return ans;
    }

    bool check(string& s)
    {
        string t=s;
        reverse(t.begin(),t.end());
        return t==s;
    }
};
