/*
    stamp = "abca", target = "aabcaca"
    aabcaca
    abca    0
       abca 1
     abca   2
    -----
    stamp = "abc", target = "ababc"
    ababc
    abc
      abc
    For every char, we have at most k choice to filled up.
    -----
    brute force:
    keep replacing xxxxx *xxxx xxxx* and so on.
    T:O(nk*nk)/S:O(1)
*/
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target)
    {
        int n=target.size(), k=stamp.size();
        vector<int> ans;
        bool change=true;
        while (change) {
            change=false;
            for (int i=0; i<k; ++i) {
                for (int j=0; j<=i; ++j) {
                    string t=string(j,'*')+stamp.substr(j,k-i)+string(i-j,'*');
                    auto pos=target.find(t);
                    while (pos!=string::npos) {
                        ans.push_back(pos);
                        fill(begin(target)+pos,begin(target)+pos+k,'*');
                        pos=target.find(t);
                        change=true;
                    }
                }
            }
        }
        for (char &c:target) {
            if (c!='*') return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
