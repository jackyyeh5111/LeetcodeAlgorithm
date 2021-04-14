/***** Fourth Visit *****/
class Solution {
public:
    string reverseWords(string s)
    {
        if (s=="") return s;
        reverse(s.begin(),s.end());
        int i=0, j=0, n=s.length();
        while (i<n) {
            while (i<n&&s[i]==' ') i++;
            int k=i;
            while (k<n&&s[k]!=' ') k++;
            if (i==k) break;
            reverse(s.begin()+j, s.begin()+k);
            j+=k-i+1; i=k;
        }
        return s.substr(0,s[j-1]==' '?j-1:j);
    }
};

/***** Third Visit *****/
/*
    the sky is   blue
    eulb   si yks eht
    ^
    blue   si yks eht
         ^
    blue is   yks eht
            ^
    blue is sky   eht
                ^
    blue is sky the
                    ^
    -----
    T:O(n)/S:O(1)
*/
class Solution {
public:
    string reverseWords(string s)
    {
        int i=0,j=0,n=s.length();
        if (n<=1) return s;
        reverse(s.begin(),s.end());
        while (i<n) {
            while (i<n&&s[i]==' ') i++;
            int k=0;
            while (i<n&&s[i]!=' ') {i++;k++;}
            reverse(s.begin()+j,s.begin()+i);
            j+=k+1;
        }
        return s.substr(0,s[j-2]==' '?j-2:j-1);
    }
};

/***** Second Visit *****/
class Solution {
public:
    string reverseWords(string s)
    {
        /*
            reverse whole string, then reverse each word
            'hello world  '
            ' dlrow olleh'
        */
        reverse(s.begin(),s.end());
        int idx=0, running_idx=0, length=s.length();
        while(idx<length) {
            while(idx<length&&s[idx]==' ') idx++;
            int j=idx;
            while(j<length&&s[j]!=' ') j++;
            if (idx==j) break;
            if (running_idx!=0) running_idx++;
            int word_size=j-idx;
            reverse(s.begin()+running_idx,s.begin()+j);
            running_idx+=word_size;

            idx=j;
        }
        s=s.substr(0,running_idx);
        return s;
    }
};
/***** First Visit *****/
/***************** In-place *****************/
/*
    reverse the string, then reverse each word
    input:   "  the  sky      is blue   "
    reverse  "eulb si      yks  eht     "
             "blue    si      yks  eht  "
                  ^
             "blue is         yks  eht  "
                     ^  ^
             "blue is sky          eht  "
                      ^  ^       ^
             "blue is sky the           "
                             ^
*/
class Solution {
public:
    string reverseWords(string s)
    {
        /*
            constrain: S:O(1)
            Note: notice that there's leading space or tailing space.
            think T:O(n) in 1 pass.
        */
        reverse(s.begin(),s.end());
        int storeIndex=0, length=s.length();
        for (int i=0; i<length; ++i) {
            if (s[i]==' ') continue;
            if (storeIndex!=0) storeIndex++;
            int j=i;
            while(j<length&s[j]!=' ') j++;
            reverse(s.begin()+storeIndex,s.begin()+j);
            storeIndex+= j-i;
            i=j;
        }
        s.erase(s.begin()+storeIndex,s.end());
        return s;
    }
};

class Solution {
public:
    string reverseWords(string s)
    {
        /*
            constrain: S:O(1)
            Note: notice that there's leading space or tailing space.
            think T:O(n) in 1 pass.
        */
        int i=0, length=s.length();
        int tail=0;
        string ans="";
        while(i<length) {
            while(i<length&&s[i]==' ') i++;
            int j=i;
            while(j<length&&s[j]!=' ') j++;
            if(i==j) break;
            string word=s.substr(i,j-i);
            if (ans=="") ans=word;
            else ans=word+" "+ans;
            i=j+1;
        }
        return ans.substr(0,ans.length());
    }
};
