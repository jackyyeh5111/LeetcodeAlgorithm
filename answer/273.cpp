/***** Second Visit *****/
class Solution {
public:
    string numberToWords(int num)
    {
        if (num==0) return "Zero";
        string ans=convert(num);
        return ans.substr(1);
    }

    string convert(int num)
    {
        if (num>=1000000000) return convert(num/1000000000)+" Billion"+convert(num%1000000000);
        else if (num>=1000000) return convert(num/1000000)+" Million"+convert(num%1000000);
        else if (num>=1000) return convert(num/1000)+" Thousand"+convert(num%1000);
        else if (num>=100) return convert(num/100)+" Hundred"+convert(num%100);
        else if (num>=20) return " "+below_100[num/10]+convert(num%10);
        else if (num>=1) return " "+below_20[num];
        else return "";
    }
    string below_20[20] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string below_100[10] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

};

/***** First Visit *****/
/*
    Recursive in terms of decimal.
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    string numberToWords(int num)
    {
        if (num==0) return below_20[0];
        return convert(num).substr(1);
    }

    string convert(int num)
    {
        if (num>=1000000000) return convert(num/1000000000)+" Billion"+convert(num%1000000000);
        else if (num>=1000000) return convert(num/1000000)+" Million"+convert(num%1000000);
        else if (num>=1000) return convert(num/1000)+" Thousand"+convert(num%1000);
        else if (num>=100) return convert(num/100)+" Hundred"+convert(num%100);
        else if (num>=20) return " "+below_100[num/10]+convert(num%10);
        else if (num>=1) return " "+below_20[num%20];
        else return "";
    }

    string below_20[20] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string below_100[10] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
};
