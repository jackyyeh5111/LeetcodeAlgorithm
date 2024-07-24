class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int len_text = text.size();
        string target{'b', 'a', 'l', 'o', 'n'};
        unordered_map<char, int> counter;
        for (char ch : target)
            counter[ch] = 0;
        
        // iterate text string
        for (char ch : text) {
            if (counter.count(ch)) // ch exist as a hashmap key
                counter[ch]++;
        }

        counter['l'] /= 2;
        counter['o'] /= 2;
        int ans = INT_MAX;
        for (char ch : target)
            ans = min(ans, counter[ch]);
        return ans;
    }
};

/* 
    balloon
    
    a:1
    b:1
    l:2
    o:2
    n:1
 */