/************************ First Visit ************************/
class Solution {
public:
    string addBinary(string a, string b)
    {
        if (a.length() < b.length()) swap(a,b);
        int i=a.length()-1, j=b.length()-1;
        int c=0;
        string ans="";
        while(i>=0&&j>=0) {
            char ca=a[i], cb=b[j];
            char sum; int tmp=0;
            if (ca==cb) { sum='0'; tmp=ca=='1';}
            else sum='1';
            if (c&&sum=='1') { sum='0'; c=1; }
            else { sum+=c; c=0; }
            c=max(c,tmp);
            ans+=sum;
            --i; --j;
        }
        while (i>=0) {
            if (c&&a[i]=='1') { ans+='0'; c=1; }
            else { ans+=(a[i]+c); c=0; }
            --i;
        }
        if(c) ans+='1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/************************ First Visit ************************/
class Solution {
public:
    string addBinary(string a, string b)
    {
        // we don't consider integer overflow here.
        // T:O(n)
        if (a.length()>b.length()) swap(a,b); // make b longer
        int ar=a.length()-1;
        int br=b.length()-1;
        bool carry=false;
        while(ar>=0&&br>=0) {
            if (a[ar]=='1'&&b[br]=='1') {
                if (carry) b[br]='1';
                else b[br]='0';
                carry=true;
            }
            else if (a[ar]=='1'||b[br]=='1') {
                if (carry) {b[br]='0'; carry=true;}
                else {b[br]='1'; carry=false;}
            }
            else { b[br]=carry+'0'; carry=false;}
            ar--; br--;
        }
        while(br>=0&carry){
            if (b[br]=='0') {b[br]='1'; carry=false;}
            else b[br]='0';
            br--;
        }
        if (carry) b = "1"+b;
        return b;

    }
};

/*************** XOR concise solution *********************/
class Solution {
public:
    string addBinary(string a, string b)
    {
        string result = "";
        int apos = a.size() - 1;
        int bpos = b.size() - 1;
        int adigit, bdigit, carry = 0;

        while (apos >= 0 || bpos >= 0 || carry == 1)
        {
            adigit = bdigit = 0;

            if (apos >= 0) adigit = a[apos--] == '1';
            if (bpos >= 0) bdigit = b[bpos--] == '1';

            // Another way: the digit is 1 if adigit + bdigit + carry == 1 or == 3, but I noticed that
            // XOR is more concise:
            result = static_cast<char>(adigit ^ bdigit ^ carry + '0') + result;
            carry = adigit + bdigit + carry >= 2;
        }
        return result;
    }
};
