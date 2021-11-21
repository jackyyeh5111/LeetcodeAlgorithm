class Solution {
public:
    /*
        binary search s.length()/2
        length: mid
        for (i=0;i<length-mid; i++) {
            bool found=false;
            for (j=i+mid;j<length-mid;j++) {
                compare string // rabin-karp
                if same: found=true
            }
            if found(l=mid+1)
            else r=mid-1
        }
    */
    string longestDupSubstring(string S) {
        if(S.empty()) return "";
        int n = S.size();
        int left = 1,right = n;
        vector<int> table;
        for(int i = 0;i < n;i++) {
            table.push_back(S[i] - 'a');
        }
        string res = "";
        int subLen = 0;
        while(left < right)
        {
            subLen = (left + right) / 2;
            if (helper(table,n,subLen)) left = subLen + 1;
            else right = subLen;
        }

        if(maxLen !=  0) res = S.substr(start,maxLen);

        return res;
    }

    int helper(vector<int> &table,int strLen,int subLen)
    {
        unsigned int a =1;
        unsigned int temp = 0;
        unordered_set<unsigned int> mm;
        for(int i = 0;i < subLen;i++) {
            a = a*26 % UINT_MAX;
            temp = temp*26 % UINT_MAX;
            temp += table[i];
        }
        mm.insert(temp);
        for(int i = 1;i < (strLen -subLen + 1);i++)
        {
            temp = temp*26 % UINT_MAX - table[i-1]*a % UINT_MAX + table[i + subLen -1];
            if(mm.find(temp) != mm.end()) {
                if(subLen > maxLen) {
                    start = i;
                    maxLen = max(maxLen,subLen);
                }
                return true;
            }
            mm.insert(temp);
        }
        return false;
    }

    int start = 0;
    int maxLen = 0;
};
