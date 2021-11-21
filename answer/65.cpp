class Solution {
public:
    bool isNumber(string s)
    {
        /*
        list all acceptable char:
        0-9 'e' '+-' '.'
        */
        // First excludes string contains unacceptable char
        // validate legal or not for each case
        // e could be only #e#
        // . could be only #.#
        // for each #, could contain +- once and then 0-9
        int l=0,r=s.length()-1;
        while(l<s.length()-1&&s[l]==' ')l++;
        while(r>0&&s[r]==' ')r--;
        if(l>r) return false;
        s=s.substr(l,r-l+1);
        unordered_map<char,int> allow(
            {{'0',0},{'1',0},{'2',0},{'3',0},{'4',0},{'5',0},{'6',0},{'7',0},{'8',0},
             {'9',0},{'+',0},{'-',0},{'e',0},{'.',0}});
        for (const char &c : s) {
            if (allow.find(c)==allow.end()) return false;
            allow[c]++;
        }
        if(allow['e']>1 || allow['.']>1) return false;

        if (s.find('e')!=string::npos){
            int mid = s.find('e');
            return checkNum(s.substr(0,mid),true)&&checkNum(s.substr(mid+1,s.length()-mid-1));
        }
        else if (s.find('.')!=string::npos){ return checkNum(s,true); }
        else {
            return checkNum(s);
        }
    }

    bool checkNum(string s, bool dot=false)
    {
        // check s is num or not.
        // acceptable case:
        // +1 -1 1
        // unacceptable case:
        // ++# +-# --# #+ #-
        // check first char is +- or not, and rest of chars should be only 0-9.
        if (s[0]=='+'||s[0]=='-') s=s.substr(1,s.length()-1);
        if (dot&&s.find('.')!=string::npos) { s=s.erase(s.find('.'),1); }
        if (s.length()==0) return false;
        for (const char &c:s){
            if (c>'9'||c<'0') return false;
        }
        return true;
    }
};
