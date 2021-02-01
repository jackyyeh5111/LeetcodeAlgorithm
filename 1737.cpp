class Solution {
public:
    int minCharacters(string a, string b)
    {
        vector<int> A(26,0);
        vector<int> B(26,0);
        int ans=max(a.length(),b.length());
        for (char c:a) A[c-'a']++;
        for (char c:b) B[c-'a']++;

        for (int i=1; i<26; ++i) {
            int opa,opb;
            opb=accumulate(B.begin(),B.begin()+i,0);
            opa=accumulate(A.begin()+i,A.end(),0);
            ans=min(ans,opa+opb);
            opb=accumulate(B.begin()+i,B.end(),0);
            opa=accumulate(A.begin(),A.begin()+i,0);
            ans=min(ans,opa+opb);

        }
        int opa=accumulate(A.begin(),A.end(),0)-*max_element(A.begin(),A.end());
        int opb=accumulate(B.begin(),B.end(),0)-*max_element(B.begin(),B.end());
        ans=min(ans,opa+opb);
        return ans;
    }
};
