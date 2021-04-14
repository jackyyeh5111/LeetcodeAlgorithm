/***** Fourth Visit *****/
/*
    Use a counter for each letter.
    To form a smallest lexicon order, we'd like to pop out larger letter while insert a new letter IF AND ONLY IF we know theres duplicate letter in the following string.
    Once the incoming letter has been dealed, we can just skip it.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> cnt(26,0);
        vector<bool> seen(26,0);
        for (char c:s) cnt[c-'a']++;
        string ans="";
        for (char c:s) {
            cnt[c-'a']--;
            if (seen[c-'a']) continue;
            while (!ans.empty()&&ans.back()>c&&cnt[ans.back()-'a']>0) {
                seen[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans+=c;
            seen[c-'a']=true;
        }
        return ans;
    }
};

/***** Third Visit *****/
/*
    First, count all chars in s.
    Greedy find the min lexicon order.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        int n=s.length();
        vector<char> table(26,0);
        vector<bool> visited(26,0);
        for (char c:s) table[c-'a']++;
        string ans="";
        for (char c:s) {
            table[c-'a']--;
            if (visited[c-'a']) continue;
            while(!ans.empty()&&ans.back()>c&&table[ans.back()-'a']>0) {
                visited[ans.back()-'a']=false;
                ans.pop_back();
            }
            visited[c-'a']=true;
            ans+=c;
        }
        return ans;
    }
};

/***** Second Visit *****/
/*
    01234567
    cbacdcbc
     ^  ^
     a: 2
     b: 1, 6
     c: 0, 3, 5, 7
     d: 4

     we want to choose small char with small index as possible
     T:O(n)/S:O(n)
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> count;
        unordered_map<char,bool> visited;
        string ans="";
        for (char c:s) count[c]++;
        for (char c:s) {
            count[c]--;
            if (visited[c]) continue;
            while (ans!=""&&c<ans.back()&&count[ans.back()]>0) {
                visited[ans.back()]=false;
                ans.pop_back();
            }
            visited[c]=true;
            ans+=c;
        }
        return ans;
    }
};

/***** First Visit *****/
/*
    DP approach
    dp[i] denotes smallest lexicographical order from 0-i
    dp[i+1]=dp[i] or move the duplicated char to the last.
    T:O(n^2)/S:O(n)
    Wrong Answer
    -----
    Greedy find min string in lexical order with distinct letter.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        unordered_map<char,int> counter;
        unordered_map<char,bool> visited;
        string ans="";
        for (char c:s) counter[c]++;
        for (char c:s) {
            counter[c]--;
            if (visited[c]) continue;
            while (ans.length()!=0&&counter[ans.back()]>0&&c<ans.back()) {
                visited[ans.back()]=false;
                ans.pop_back();
            }
            ans+=c;
            visited[c]=true;
        }
        return ans;
    }
};
