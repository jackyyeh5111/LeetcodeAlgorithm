/***** Third Visit *****/
/*
    DNA: 10-letter-long
    char: 'A', 'C', 'G', 'T'
    -----
    string comparison
    1. KMP failure function
    2. TRIE
    3. treat it as array
    -----
    Array
    1. sort help?
    1-1. bucket sort further. help
    2. BINARY SEARCH
    3. 2 ptr solution
    4. running ptr, i.e. window solution
    5. use a stack to record increasing index
    6. 2-D array
    -----
    make a unique number of each DNA string with 20 bits integer.
    We have 4 cases of char. Utilize 2 bit to represent 1 char.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        unordered_map<int,bool> visited;
        int i=0, n=s.length(), mask=(1<<20)-1, cur=0;
        while (i<10) cur=(cur<<2)|to_bit(s[i++]);
        visited[cur]=true;
        while (i<n) {
            cur=((cur<<2)|to_bit(s[i++]))&mask;
            if (visited.count(cur)==0) visited[cur]=true;
            else if (visited[cur]) {
                ans.push_back(s.substr(i-10,10));
                visited[cur]=false;
            }
        }
        return ans;
    }

    int to_bit(char c)
    {
        if (c=='A') return 0; // 00
        else if (c=='C') return 1; // 01
        else if (c=='G') return 2; // 10
        else return 3; // 11
    }
};

/***** Second Visit *****/
/*
    KMP - failure function
    a a a b
    0 1 2 0
   -1 0 1-1
   -----
   use a running window as hashset/hashmap to check if duplidate dna is visited.
   We have only ACGT 4 letters, which canbe represented as 0123, 2 bit for each letter.
   Therefore, we have 20 bits as a dna series. Utilize bit manipulation to save substr time.
    T:O(n)/S:O(n*10)
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        int n=s.length(), i=0;
        if (n<=10) return ans;
        unordered_set<int> looked, found;
        int dna=0;
        for (int i=0; i<10; ++i)
            dna=(dna<<2)|encode(s[i]);
        looked.insert(dna);
        int mask=(1<<20)-1;
        for(int i=10; i<n; ++i) {
            dna=((dna<<2)|encode(s[i]))&mask;
            if (looked.count(dna)>0&&found.count(dna)==0) {
                ans.push_back(s.substr(i-9,10));
                found.insert(dna);
            }
            looked.insert(dna);
        }
        return ans;
    }

    int encode(char c)
    {
        if (c=='A') return 0;
        else if (c=='C') return 1;
        else if (c=='T') return 2;
        else return 3;
    }
};

/***** First Visit *****/
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
