class Solution {
public:
    // T:O(27), S:O(n), notice that 0 leading illegal IP
    vector<string> ans;
    vector<string> restoreIpAddresses(string s)
    {
        /*
            brute force: O(n^3) with 3 for loop
            thought:
            reduce problem to group into 4 group with max length 3
            recursive:
            help(s,i,j,k,n)
            1111
            1112
            1113
            1121
            1122
            1123
            1131
            1132
            1133
            1211
            1212
            ...
        */
        for (int i=1; i<=3; ++i) {
            for (int j=1; j<=3; ++j) {
                for (int k=1; k<=3; ++k) {
                    help(s,i,j,k,s.length());
                }
            }
        }
        return ans;
    }

    void help(string &s, int i, int j, int k, int n)
    {
        if (n<4) return;
        int l=n-i-j-k;
        if (i>3||j>3||k>3||l>3||l<1) return;
        string ip1="",ip2="",ip3="",ip4="";
        int i1=-1, i2=-1, i3=-1, i4=-1;
        int idx=0;
        if (idx+i<=n) {
            ip1=s.substr(idx,i); idx+=i; i1=stoi(ip1);
            if (ip1[0]=='0'&&ip1.length()!=1) i1=-1;}
        else return;
        if (idx+j<=n) {
            ip2=s.substr(idx,j); idx+=j; i2=stoi(ip2);
            if (ip2[0]=='0'&&ip2.length()!=1) i2=-1;}
        else return;
        if (idx+k<=n) {
            ip3=s.substr(idx,k); idx+=k; i3=stoi(ip3);
            if (ip3[0]=='0'&&ip3.length()!=1) i3=-1;}
        else return;
        if (idx+l<=n) {
            ip4=s.substr(idx,l); idx+=l; i4=stoi(ip4);
            if (ip4[0]=='0'&&ip4.length()!=1) i4=-1;}
        else return;
        // cout<<i<<j<<k<<l<<endl;
        // cout<<ip1<<"."<<ip2<<"."<<ip3<<"."<<ip4<<endl;

        if (i1>=0&&i1<=255&&i2>=0&&i2<=255&&
            i3>=0&&i3<=255&&i4>=0&&i4<=255)
            ans.push_back(to_string(i1)+"."+to_string(i2)+"."+to_string(i3)+"."+to_string(i4));
    }

};
