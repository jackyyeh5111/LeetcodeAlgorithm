/*
    divide/mod op takes time due to computer architectur.
    we can use "add" instead.
    T:O(n)/S:O(1)
    ---------
    Division/mod can be expensive operation. Writing to memory will often be
    cheaper, so doing extra writes is probably better than expensive arithmetic.
*/
class Solution {
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans;
        for (int i=1; i<=n; ++i) {
            string s="";
            if (i%3==0)s+="Fizz";
            if (i%5==0)s+="Buzz";
            if (s=="") s=to_string(i);
            ans.push_back(s);
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int i = 1;i <= n; i++) {
            res[i - 1] = to_string(i);
        }
        for(int i = 2;i < n; i += 3) {
            res[i] = "Fizz";
        }
        for(int i = 4;i < n; i += 5) {
            res[i] = "Buzz";
        }
        for(int i = 14;i < n; i += 15) {
            res[i] = "FizzBuzz";
        }
        return res;
    }
};
