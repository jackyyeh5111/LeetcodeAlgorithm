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
