/***** Third Visit *****/
/*
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0,m=version1.length(),n=version2.length();
        while (i<m||j<n) {
            int v1=0,v2=0;
            while (i<m&&version1[i]!='.') {v1=v1*10+(version1[i]-'0'); i++;}
            while (j<n&&version2[j]!='.') {v2=v2*10+(version2[j]-'0'); j++;}
            if (i<m) i++;
            if (j<n) j++;
            if (v1>v2) return 1;
            else if (v1<v2) return -1;
        }
        return 0;
    }
};

/***** Second Visit *****/
/*
    version comparison
    while loop parsing digits
    default is 0.
*/
class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        int i1=0,i2=0, n1=version1.length(), n2=version2.length();
        while (i1<n1||i2<n2) {
            int v1=0,v2=0;
            while(i1<n1&&version1[i1]!='.') v1=v1*10+(version1[i1++]-'0');
            while(i2<n2&&version2[i2]!='.') v2=v2*10+(version2[i2++]-'0');
            if (v1<v2) return -1;
            else if (v1>v2) return 1;
            i1++; i2++;
        }
        return 0;
    }
};

/***** First Visit *****/
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
