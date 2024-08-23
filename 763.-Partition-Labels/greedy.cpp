class Solution {
public:
    vector<int> partitionLabels(string s) {
        // step create hashmap
        unordered_map<char, pair<int, int>> hashmap;
        for (int i =0; i < s.size(); i++) {
            char ch = s[i];
            if (hashmap.count(ch))
                hashmap[ch].second = i;
            else
                hashmap[ch] = make_pair(i, i);
        }

        // step 2: greedy partition
        vector<int> ans;
        int start = 0;
        int end = hashmap[s[0]].second;
        for (int i = 1; i < s.size(); i++) {
            char ch = s[i];
            if (hashmap[ch].first > end) {
                ans.push_back(end - start + 1);
                start = i;
                end = hashmap[ch].second;
            }
            else {
                end = max(end, hashmap[ch].second);
            }
        }
        ans.push_back(end - start + 1);
        return ans;
    }
};

/* 
    hashmap = {
        a: [0, 2]
        b: [1, 3]
        c: [4, 4]
    }

    end = 3

    ababc
        ^
 
    1) create hashmap to store start and end index of characters
    2) iterate string once, greedy partition
 */