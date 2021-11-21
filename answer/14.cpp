/***** Second Visit *****/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int n=strs.size();
        int idx=0;
        if (n==0) return "";
        for (int i=0; i<strs[0].length(); ++i) {
            char c=strs[0][i];
            for (int j=1; j<n; ++j) {
                if (i>=strs[j].length()||strs[j][i]!=c) return strs[0].substr(0,idx);
            }
            idx++;
        }
        return strs[0];
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans=""; int n=strs.size();
        if (n==0) return ans;
        for (int i=0;;++i) {
            bool diff=false; char c=0;
            for (auto str:strs) {
                if (i>=str.length()||(c&&str[i]!=c)) {diff=true; break;}
                c=str[i];
            }
            if(diff) break;
            ans+=c;
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    // T: O(min(str.size())) S: O(min(str.size()))
    // S could be optimied to O(1)
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return "";
        if (strs.size()==1) return strs[0];
        string result="";
        for (int i=0; i<strs[0].length(); ++i) {
            char common = strs[0][i];
            for (int j=1; j<strs.size(); ++j) {
                if (i>=strs[j].size()||common!=strs[j][i]) return result;
                // Could return substring instead result
            }
            result += string(1, common);
        }
        // Could return strs[0] instead.
        return result;
    }
};
