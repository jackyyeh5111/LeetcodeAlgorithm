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
