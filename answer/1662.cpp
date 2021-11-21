/*
    brute force:
    concate array1 and array2 then do string comparison.
    T:O(m+n)/S:O(m+n)
*/
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        int c1=0,c2=0,w1=0,w2=0,n1=word1.size(),n2=word2.size();
        while (w1<n1&&w2<n2) {
            if (c1>=word1[w1].length()) {c1=0; w1++;}
            if (c2>=word2[w2].length()) {c2=0; w2++;}
            if (w1<n1&&w2<n2&&word1[w1][c1]!=word2[w2][c2]) return false;
            else {c1++; c2++;}
        }
        return w1==n1&&w2==n2;
    }
};
