/***** Third Visit *****/
/*
    Notice overflow in the first digit.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        digits.back()+=1;
        int n=digits.size(),c=0;
        for (int i=n-1; i>=0; --i) {
            digits[i]+=c;
            c=digits[i]/10;
            digits[i]%=10;
            if (c==0) break;
        }
        if (c) digits.insert(digits.begin(),1);
        return digits;
    }
};

/***** Second Visit *****/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        /*
            bottom up sum, use a variable for carry
            if carry==1 when finish for loop, insert 1 in the begining.
        */
        int size=digits.size(); int carry=1;
        for (int i=size-1; i>=0; --i) {
            digits[i]+=carry;
            carry=digits[i]/10;
            digits[i]=digits[i]%10;
        }
        // if (carry) digits.insert(digits.begin(),1);
        if (carry) {digits[0]=1; digits.push_back(0);}
        return digits;
    }
};

/***** First Visit *****/
/**************** Insert in the bigin *********************/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        /*
        bottom up tracing, add last digit then check carry bottm up.
        T: O(n)
        */
        digits.back()++;
        int carry=digits.back()/10;
        digits.back()=digits.back()%10;
        for (int i=digits.size()-2; i>=0; --i) {
            if (carry==0) break;
            digits[i]++;
            carry=digits[i]/10;
            digits[i]=digits[i]%10;
        }
        if (carry) digits.insert(digits.begin(),1);
        return digits;

    }
};

/**************** Insert in the end *********************/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        /*
        bottom up tracing, add last digit then check carry bottm up.
        T: O(n)
        */
        for (int i = digits.size()-1; i >= 0; --i) {
            if (digits[i] == 9) digits[i] = 0;
            else {
                digits[i]++;
                return digits;
            }
        }
        digits[0] =1;
        digits.push_back(0);
        return digits;
    }
};
