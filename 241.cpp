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
