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
