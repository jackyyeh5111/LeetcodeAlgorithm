/***** Sixth Visit *****/
/*
    Divide and Conquer
    T:1/(n+1)C^2n_n, i.e. catalan number in worst case.
*/
class Solution {
public:
    unordered_map<string,vector<int>> mp;
    vector<int> diffWaysToCompute(string input)
    {
        if (mp.count(input)!=0) return mp[input];
        int n=input.size();
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            if (isdigit(input[i])) continue;
            else {
                auto lefts=diffWaysToCompute(input.substr(0,i));
                auto rights=diffWaysToCompute(input.substr(i+1));
                for (int l:lefts) {
                    for (int r:rights) {
                        ans.push_back(calc(l,r,input[i]));
                    }
                }
            }
        }
        if (ans.empty()) ans.push_back(stoi(input));
        mp[input]=ans;
        return ans;
    }

    int calc(int a, int b, char op)
    {
        if (op=='-') return a-b;
        else if (op=='+') return a+b;
        else return a*b;
    }
};

/***** Fourth Visit *****/
/*
    "2*3-4*5"
     6 -1 20
     2,-2 -17,-5
     -----
     Recursively enumerate all possible parentheses combination.
*/
class Solution {
public:
    unordered_map<string,vector<int>> mp;
    vector<int> diffWaysToCompute(string input) {
        if (mp.count(input)!=0) return mp[input];
        int n=input.size();
        vector<int> combs;
        for (int i=0; i<n; ++i) {
            if (isdigit(input[i])) continue;
            auto left =diffWaysToCompute(input.substr(0,i));
            auto right=diffWaysToCompute(input.substr(i+1));
            for (int l:left){
                for (int r:right) {
                    combs.push_back(calc(l,r,input[i]));
                }
            }
        }
        if (combs.empty()) mp[input]={stoi(input)};
        else mp[input]=combs;
        return mp[input];
    }

    int calc (int a, int b, char c)
    {
        if (c=='+') return a+b;
        else if (c=='-') return a-b;
        else return a*b;
    }
};

/***** Third Visit *****/
/*
    "2*3-4*5"
    w.o. memo DP
    T(n) = CATALAN NUMBER * O(n)
    w. memo DP
    T(n) = CATALAN NUMBER
*/
class Solution {
public:
    unordered_map<string, vector<int>> m;
    vector<int> diffWaysToCompute(string input)
    {
        if (m.count(input)!=0) return m[input];
        int n=input.length();
        bool isNum=true;
        vector<int> ret;
        for (int i=0; i<n; ++i) {
            if (!isdigit(input[i])) {
                isNum=false;
                auto left = diffWaysToCompute(input.substr(0,i));
                auto right = diffWaysToCompute(input.substr(i+1));
                for (int l:left) {
                    for (int r:right) {
                        ret.push_back(calc(l,r,input[i]));
                    }
                }
            }
        }
        if (isNum) ret=vector<int>{stoi(input)};
        m[input]=ret;
        return ret;
    }

    int calc(int a, int b, char op)
    {
        if (op=='+') return a+b;
        else if (op=='-') return a-b;
        else return a*b;
    }
};

/***** Second Visit *****/
/*
    Divide & Conquer
    [ sub1 ] op [ sub2 ]
*/
class Solution {
public:
    unordered_map<string,vector<int>> cache;
    vector<int> diffWaysToCompute(string input)
    {
        if (cache.count(input)!=0) return cache[input];
        int n=input.length();
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            if (!isdigit(input[i])) {
                auto left=diffWaysToCompute(input.substr(0,i));
                auto right=diffWaysToCompute(input.substr(i+1));
                for (int l:left) {
                    for (int r:right) {
                        ans.push_back(calc(l,r,input[i]));
                    }
                }
            }
        }
        if (ans.size()==0) ans.push_back(stoi(input));
        cache[input]=ans;
        return ans;
    }

    int calc (int a, int b, char op)
    {
        if (op=='+') return a+b;
        else if (op=='-') return a-b;
        else return a*b;
    }
};

/***** First Visit *****/
/*
    2*3-4*5
    10
    -24
    -10
    -10
    -14
    -34
    3 operators -> 3! results but not guaranteed to be unique.
    2-1-15
    *-*
    T:O(k!)
    ------------
    recursive -> DP
        recursive:
        separate each input into <left op right>
        T(n)=catalan number! 1/(n+1) C^2n_n * O(n)

        DP:
        use a hashmap to do a memorized DP!
        T(n)=catalan number! 1/(n+1) C^2n_n

*/
class Solution {
public:
    unordered_map<string,vector<int>> cache;
    vector<int> diffWaysToCompute(string input)
    {
        if(cache.find(input)!=cache.end()) return cache[input];
        int n=input.size();
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            char c=input[i];
            if (!isdigit(c)) {
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for(int l:left) {
                    for (int r:right) {
                        ans.push_back(calc(l,r,c));
                    }
                }
            }
        }
        if (ans.empty()) ans.push_back(stoi(input));
        cache[input]=ans;
        return ans;
    }

    int calc(int a, int b, char op)
    {
        switch(op) {
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            default:
                return -1;
        }
    }
};
