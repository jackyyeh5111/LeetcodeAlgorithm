/***** Fifth Visit *****/
/*
    T(N) = Total Number of Valid Expressions

    T(N) = 3T(N - 1) + 3T(N - 2) + 3T(N - 3) + .... 3T(0)

    If we use first digit as an operand, total number of valid expressions would be T(N - 1) x 3. Three accounts
    for our three operations. If we use first two digits as an operand, total number of valid expressions would be T(N - 2) x 3 and so on.

    Now T(N - 1) = 3T(N - 2) + 3T(N - 3) + 3T(N - 4) + .... 3T(0)

    if we put T(N - 1) in T(N) we'll get

    T(N) = 3 x 4 ( T(N - 2) + T(N - 3) + T(N - 4) + .... T(0) )

    If we put T(N - 2) in T(N) we'll get

    T(N) = 3 x 4^2 ( T(N - 3) + T(N - 4) + T(N - 5) + .... T(0) )

    If we generalize it, we'll get

    T(N) = 3 x 4^k ( T(N - (k + 1)) + T(N - (k + 2)) + .... T(0))

    If we put k = N - 1, we'll get

    T(N) = 3 x 4^(N - 1) (T(0)) = O(4^N)
*/
class Solution {
public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> ans;
        dfs(num,target,0,0,0,"",ans);
        return ans;
    }

    void dfs(string num, long target, int idx, long prev, long cur, string s,
             vector<string> &ans)
    {
        int n=num.length();
        if (idx==n) {
            if (cur==target) ans.push_back(s);
            return;
        }
        for (int i=idx; i<n; ++i) {
            if (num[idx]=='0'&&i>idx) continue;
            string sub=num.substr(idx,i-idx+1);
            long val=stol(sub);
            if (idx==0) {
                dfs(num,target,i+1,val,val,sub,ans);
                continue;
            }
            dfs(num,target,i+1,val,cur+val,s+'+'+sub,ans);
            dfs(num,target,i+1,-1*val,cur-val,s+'-'+sub,ans);
            dfs(num,target,i+1,val*prev,cur-prev+prev*val,s+'*'+sub,ans);
        }
    }
};

/***** Fourth Visit (FAIL) *****/
class Solution {
public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> ans;
        help(num,target,0,0,0,ans,"");
        return ans;
    }

    void help(string num, long target, int idx, long prev, long cur, vector<string> &ans, string s)
    {
        if (idx==num.length()) {
            if (cur==target) ans.push_back(s);
            return;
        }

        for (int i=idx; i<num.length(); ++i) {
            if (num[idx]=='0'&&i>idx) continue;
            string sub = num.substr(idx, i-idx+1);
            long n = stol(sub);
            if (idx==0) {
                help(num,target,i+1,n,n,ans,sub);
                continue;
            }
            help(num,target,i+1,n,cur+n,ans,s+"+"+sub);
            help(num,target,i+1,-n,cur-n,ans,s+"-"+sub);
            help(num,target,i+1,prev*n,cur-prev+prev*n,ans,s+"*"+sub);
        }
    }
};

/***** Third Visit (Fail) *****/
class Solution {
public:
    vector<string> addOperators(string num, int target)
    {
        if (num==to_string(target)&&num[0]!='0') return {num};
        else if (num=="") return {};

        vector<string> ans;
        help(num, 0, 0, 0, target, "", ans);
        return ans;
    }

    void help(string num, int idx, long prev, long cur, long target,
              string s, vector<string> &ans)
    {
        if (idx==num.length()) {
            if (cur==target) ans.push_back(s);
            return;
        }
        for (int i=idx; i<num.length(); ++i) {
            if (i>idx&&num[idx]=='0') continue;
            string sub=num.substr(idx,i-idx+1);
            long k=stol(sub);
            if (idx==0) {
                help(num,i+1,k,k,target,sub,ans);
                continue;
            }
            help(num,i+1,k,cur+k,target,s+"+"+sub,ans);
            help(num,i+1,-k,cur-k,target,s+"-"+sub,ans);
            help(num,i+1,prev*k,(cur-prev)+prev*k,target,s+"*"+sub,ans);
        }
    }
};

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
