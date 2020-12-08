/***** Second Visit *****/
/*
    Divide and Conquer
    -----
    123
    [1][23]
       [2+3]
       [2-3]
       [2*3]
      ^ + or -, since * would break priority
    T(n)=T(1)+T(n-2)+...+T(n-2)+T(1
        =2(T(n-2)+...+T(1))
        =O(n^2)
    FAIL TO PROCESS OPERATORS PRIORITY
    -----
    SEE FIRST VISIT COMMENT
    There are n-1 slots for us to add an operator and there are 4 choices (+, -, * and no operator) so the complexity is 4^(N-1)
    T:O(4^n)/S:O(n)
*/
class Solution {
public:

    vector<string> addOperators(string num, int target)
    {
        if (num==to_string(target)&&num[0]!='0') return {num};
        else if (num=="") return {};
        vector<string> ans;
        dfs(num,target,0,0,0,"",ans);
        return ans;
    }

    void dfs(string num, int target, int i, long cv, long pv, string s, vector<string> &ans)
    {
        if (i==num.length()&&target==cv) {
            ans.push_back(s);
            return;
        }
        for (int k=i; k<num.length(); ++k) {
            if (k!=i&&num[i]=='0') continue; // as 0 can not be the begin of any number
            string sub=num.substr(i,k-i+1);
            long n=stol(sub);
            if (i==0) {
                dfs(num,target,k+1,n,n,sub,ans);
                continue;
            }
            dfs(num,target,k+1,cv+n,n,s+"+"+sub,ans);
            dfs(num,target,k+1,cv-n,-n,s+"-"+sub,ans);
            dfs(num,target,k+1,cv-pv+pv*n,pv*n,s+"*"+sub,ans);
        }
    }


};

/***** First Visit *****/
/*
    pos: current tracing position
    cv: current value
    pv: previous value
    r: expression so far
    ----
    Use recursive (backtracking) to solve it, the key is to keep previous value
    for "*" operation. If we meet "*", we need to subtract previous value, then
    add previous*the value we are looking at now for updating cv.
*/
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty()) return res;
        if (stol(num) == (long)target && num[0] != '0') {
            res.push_back(num);
            return res;
        }
        dfs(num, target, 0, 0, 0, "", res);
        return res;
    }

    void dfs(string& s, int target, int pos, long cv, long pv, string r, vector<string>& res) {
        if (pos == s.size() && cv == target) {
            res.push_back(r);
            return;
        }
        for (int i = 1; i <= s.size() - pos; i++) {
            string t = s.substr(pos, i);
            if (i > 1 && t[0] == '0') continue; // preceding
            long n = stol(t);
            if (pos == 0) {
                dfs(s, target, i, n, n, t, res);
                continue;
            }
            dfs(s, target, pos+i, cv+n, n, r+"+"+t, res);
            dfs(s, target, pos+i, cv-n, -n, r+"-"+t, res);
            dfs(s, target, pos+i, cv-pv+pv*n, pv*n, r+"*"+t, res);
        }
    }
};
