/***** Second Visit *****/
/*
    use a dictionary to save I<->1,IV<->4, ... etc.
    parse string, check IV XL CD.
*/
class Solution {
public:
    int romanToInt(string s) {
        static unordered_map<char, int> T = { { 'I' , 1 },
                                           { 'V' , 5 },
                                           { 'X' , 10 },
                                           { 'L' , 50 },
                                           { 'C' , 100 },
                                           { 'D' , 500 },
                                           { 'M' , 1000 } };
        int n=s.length(),ans=0;
        for (int i=0; i<n; ++i) {
            if (i>0&&T[s[i]]>T[s[i-1]]) ans-=2*T[s[i-1]];
            ans+=T[s[i]];
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    int romanToInt(string s)
    {
        // T:O(n)
        unordered_map<char, int> T = { { 'I' , 1 },
                                       { 'V' , 5 },
                                       { 'X' , 10 },
                                       { 'L' , 50 },
                                       { 'C' , 100 },
                                       { 'D' , 500 },
                                       { 'M' , 1000 } };

       int sum = T[s.back()];
       for (int i = s.length() - 2; i >= 0; --i)
       {
           if (T[s[i]] < T[s[i + 1]])
           {
               sum -= T[s[i]];
           }
           else
           {
               sum += T[s[i]];
           }
       }

       return sum;
    }
};

// class Solution {
// public:
//     // T:O(n*c)
//     int romanToInt(string s) {
//         unordered_map<string, int> table;
//         table["I"] = 1; table["IV"] = 4; table["V"] = 5;
//         table["IX"] = 9; table["X"] = 10; table["XL"] = 40;
//         table["L"] = 50; table["XC"] = 90; table["C"] = 100;
//         table["CD"] = 400; table["D"] = 500; table["CM"] = 900;
//         table["M"] = 1000;
//
//         int result=0;
//         for (int i=0; i<s.length(); ++i) {
//             if (table.find(s.substr(i,2))!=table.end() && i<s.length()-1) {
//                 result+=table[s.substr(i,2)];
//                 i=i+1;
//             }
//             else
//                 result+=table[string(1,s[i])];
//         }
//         return result;
//     }
// };
