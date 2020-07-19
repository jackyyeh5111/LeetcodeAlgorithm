class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        /*
            top-down version number comparison
            7.5.2.4
                ^
            7.5.3
                ^
            As example, we can do comparison of level from top-down order. If someone
            is null, the other one must be greater or equal than it.
        */
        return help(version1, version2, 0, 0);
    }

    int help(string &s1, string &s2, int p1, int p2)
    {
        int i1 = 0, next_p1=p1;
        while(next_p1<s1.length()&&s1[next_p1]!='.') {
            i1=i1*10+(s1[next_p1]-'0');
            next_p1++;
        }
        int i2 = 0, next_p2=p2;
        while(next_p2<s2.length()&&s2[next_p2]!='.') {
            i2=i2*10+(s2[next_p2]-'0');
            next_p2++;
        }
        // cout<<i1<<","<<i2<<endl;
        if (i1==i2) {
            if (p1>=s1.length()&&p2>=s2.length()) return 0;
            else return help(s1,s2,next_p1+1,next_p2+1);
        }
        else return i1>i2? 1:-1;
    }
};

/********************** istringstream **********************/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        for(auto& w : version1) if (w == '.') w=' ';
        for(auto& w : version2) if (w == '.') w=' ';
        istringstream s1(version1), s2(version2);
        while(1) {
            int n1,n2;
            if (not(s1 >> n1) ) n1 = 0;
            if (not(s2 >> n2) ) n2 = 0;
            if (not s1 and not s2) return 0;
            if (n1<n2) return -1;
            if (n1>n2) return 1;
        }
    }
}
