class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        vector<string> table{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for (string word:words) {
            string morse="";
            for (char c:word) {
                morse+=table[c-'a'];
            }
            s.insert(morse);
        }
        return s.size();
    }
};
