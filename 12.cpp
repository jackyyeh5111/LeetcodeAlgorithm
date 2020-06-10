class Solution {
public:
    string intToRoman(int num)
    {
        string res;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        for(int i=0; num != 0; i++)
        {
            while(num >= val[i])
            {
                num -= val[i];
                res += sym[i];
            }
        }

        return res;
    }
};
// class Solution {
// public:
//     string intToRoman(int num) {
//
//         unordered_map<int, char> table;
//         table[1] = 'I';
//         table[5] = 'V';
//         table[10] = 'X';
//         table[50] = 'L';
//         table[100] = 'C';
//         table[500] = 'D';
//         table[1000] = 'M';
//
//         string num_str = to_string(num);
//         string result="";
//         int count=pow(10, num_str.length()-1);
//         for (int i=0; i<num_str.length(); ++i) {
//             int number = (num_str[i]-'0');
//             if (number==0) {
//                 count/=10;
//                 continue;
//             }
//             else if(number>=1&&number<=3) {
//                 for (int k=0; k<number; ++k)
//                     result += table[count];
//             }
//             else if (number==4) {
//                 result+=table[count];
//                 result+=table[count*5];
//             }
//             else if (number==9) {
//                 result+=table[count];
//                 result+=table[count*10];
//             }
//             else {
//                 result += table[count*5];
//                 for (int k=0; k<number-5; ++k)
//                     result += table[count];
//             }
//             count/=10;
//
//         }
//         return result;
//     }
// };
