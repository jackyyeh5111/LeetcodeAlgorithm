/***** Third Visit *****/
/*
    Considering with 1 bucket or 2 buckets.
*/
class Solution {
public:
    string getHint(string secret, string guess) {
        int table[10]={0};
        int A=0, B=0;
        for (int i=0; i<secret.length(); ++i) {
            if (secret[i]==guess[i]) A++;
            else {
                if (table[secret[i]-'0']<0) B++;
                if (table[guess[i]-'0']>0) B++;
                table[secret[i]-'0']++;
                table[guess[i]-'0']--;
            }
        }
        return to_string(A)+"A"+to_string(B)+"B";
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        int a[10]={0};
        int b[10]={0};
        int A=0, B=0;
        for (int i=0; i<secret.length(); ++i) {
            if (secret[i]==guess[i]) A++;
            else {
                a[secret[i]-'0']++;
                b[guess[i]-'0']++;
            }
        }
        for (int i=0; i<10; ++i) B+=min(a[i],b[i]);
        return to_string(A)+"A"+to_string(B)+"B";
    }
};

/***** Second Visit *****/
/*
    bull: match both digit and position
    cow: match number but fail position
    Note: only digits containing, and same length
    use a counter to check the digit in wrong position.
    T:1 pass O(n)/S:O(10)
*/
class Solution {
public:
    string getHint(string secret, string guess)
    {
        vector<int> counter(10);
        int n=secret.length();
        int bull=0, cow=0;
        for (int i=0; i<n; ++i) {
            if (secret[i]==guess[i]) bull++;
            else {
                if (counter[secret[i]-'0']<0) cow++;
                if (counter[guess[i]-'0']>0) cow++;
                counter[secret[i]-'0']++;
                counter[guess[i]-'0']--;
            }
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};

/***** First Visit *****/
/*
    Q: is there only digits? yes
    Q: are their length same? yes
    Q: duplicate digits? yes
    --------
    for each char
        if same digit: A
        else add into the buckets of secret/guess
    compare each bucket (0-9)
    T:O(n)/S:O(32)~=S:O(1)
    --------
    Is there any other solution without bucket?
    NO, we need to record then look forward.
    --------
    Further improve into ONE pass & ONE bucket.
    use sign bit to simulate up/down(secret/guess)
    T:O(n)/S:O(1)
*/

/****** Optima. Only 1 bucket is used with 1 pass only ******/
class Solution {
public:
    string getHint(string secret, string guess)
    {
        int n=secret.size();
        int a=0,b=0;
        vector<int> bucket(10,0);
        for (int i=0; i<n; ++i) {
            if (secret[i]==guess[i]) a++;
            else {
                if (bucket[secret[i]-'0']++<0) b++;
                if (bucket[guess[i]-'0']-->0) b++;
            }
        }

        return to_string(a)+"A"+to_string(b)+"B";
    }
};

/****** 2 bucket & 2 pass ******/
class Solution {
public:
    string getHint(string secret, string guess)
    {
        int n=secret.size();
        int a=0,b=0;
        vector<int> x(10,0),y(10,0);
        for (int i=0; i<n; ++i) {
            if (secret[i]==guess[i]) a++;
            else {
                x[secret[i]-'0']++;
                y[guess[i]-'0']++;
            }
        }
        for (int i=0; i<10; ++i) {
            b+=min(x[i],y[i]); // intersection, which is min
        }
        return to_string(a)+"A"+to_string(b)+"B";
    }
};
