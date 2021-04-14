/*
    "110"
     113

     012345
    "001011"
     210
     432
     543
*/
class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        int lacc=0,racc=0,n=boxes.length(),l=0,r=0;
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            if (boxes[i]=='1') {racc+=i; r++;}
        }
        for (int i=0; i<n; ++i) {
            ans.push_back(lacc+racc);
            if (boxes[i]=='1') {r--; l++;}
            racc-=r; lacc+=l;
        }
        return ans;
    }
};
