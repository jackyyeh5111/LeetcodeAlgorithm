/************** hashmap with bit key **************/
/*
    refers to: https://leetcode.com/problems/repeated-dna-sequences/discuss/53952/20-ms-solution-(C%2B%2B)-with-explanation

    Hashing: We compute the hash ourselves, but take advantage of the
    overlapping. We treat each letter as a two-bit number. (Arbitrarily, A=0,
    C=1, G=2, T=3.) We treat ten consecutive letters as a 20-bit integer.

*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10)
            return vector<string>();

        vector<string> R;
        bitset<1<<20> S1;
        bitset<1<<20> S2;

        int val = 0;
        for (int i=0; i < 10; i++)   // Calc. the has value for the first string.
            val = (val << 2) | char2val(s[i]);
        S1.set(val);
        cout << val << " | ";

        int mask = (1 << 20) - 1;
        for (int i=10; i < s.size(); i++) {
            // Calc the hash value for the string ending at position i.
            val = ((val << 2) & mask) | char2val(s[i]);
            if (S2[val])
                continue;
            if (S1[val]) {
                R.push_back(s.substr(i-10+1, 10));
                S2.set(val);
            }
            else
                S1.set(val);
        }
        return R;
    }

    int char2val(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
    }
};
/************** hashmap with directed key: string **************/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        int length=s.length();
        for (int i=0; i<=length-10; ++i) {
            string sub=s.substr(i,10);
            m[sub]++;
        }
        vector<string> ans;
        for (auto it=m.begin(); it!=m.end(); ++it){
            if(it->second>1)
                ans.push_back(it->first);
        }
        return ans;
    }
};
